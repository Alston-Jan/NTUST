%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"
#include "codegen.h"

#define Trace(t) printf(t)

#define TYPE_INT 0
#define TYPE_BOOL 1
#define TYPE_VOID 2

#define MAX_ARGS 10
#define MAX_LINES 1000
char* source_lines[MAX_LINES];  // 一行一個 char*
int source_line_count = 0;
typedef struct {
    char* name;
    int param_types[MAX_ARGS];
    int param_count;
    int return_type;
} func_signature;

func_signature functions[100];
int func_count = 0;
int param_types_temp[MAX_ARGS];
int param_count_temp = 0;
int arg_pass_types[MAX_ARGS];
int arg_pass_count = 0;
int yylex(void);
int current_type = -1;
int current_function_return_type = -1;
int had_error = 0;
int param_index = 0;
void yyerror(const char *msg);
void symboltable_reset_local_index(symboltable* table);
char *classname = NULL;

extern symboltable* symboltable_stack; 
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern char current_line[1024];
extern FILE *out; 

const char* yyin_filename;

static int emitted_main_epilogue = 0;
static int emitted_class_closure = 0;
static int parse_completed = 0;

// 從路徑取得 class name（例如 test.sd → test）
char *get_class_name(const char *filepath) {
    const char *base = strrchr(filepath, '/');
    base = base ? base + 1 : filepath;
    char *dot = strrchr(base, '.');
    size_t len = dot ? (size_t)(dot - base) : strlen(base);
    char *classname = malloc(len + 1);
    strncpy(classname, base, len);
    classname[len] = '\0';
    return classname;
}

void emit_source_comment() {
    if (strlen(current_line) > 0)
        fprintf(out, "/* %d: %s */\n", yylineno, current_line);
}

void register_function(const char* name, int ret_type, int* params, int count) {
    functions[func_count].name = strdup(name);
    functions[func_count].return_type = ret_type;
    functions[func_count].param_count = count;
    for (int i = 0; i < count; i++) {
        functions[func_count].param_types[i] = params[i];
    }
    func_count++;
}

func_signature* lookup_function(const char* name) {
    for (int i = 0; i < func_count; i++) {
        if (strcmp(functions[i].name, name) == 0) return &functions[i];
    }
    return NULL;
}
%}


%union {
    int    ival;
    float  fval;
    char*  sval;
}

%token <ival> INTNUM
%token <sval> STRING STRINGLIT
%token <sval> ID
%token COLON
%token BOOL TRUE FALSE CONST VOID
%token INT
%token IF ELSE WHILE FOR FOREACH RETURN
%token PRINT PRINTLN
%token PLUS MINUS STAR SLASH MOD UMINUS
%token LT LE EQ GE GT NE AND OR NOT DOTDOT
%token ASSIGN
%token SEMICOLON COMMA
%token LPAREN RPAREN LBRACE RBRACE
%left PLUS MINUS
%left STAR SLASH MOD
%right UMINUS

%type <ival> expression expression_list 
%start program
%type <ival> type


%%
program:
    {
        symboltable_push();
        classname = get_class_name(yyin_filename);
        init_codegen(classname);
        fprintf(out, "class %s {\n", classname);
    }
    decl_list
    {
        if (!had_error) {
            if (!emitted_main_epilogue) {
                emit_main_epilogue();
                emitted_main_epilogue = 1;
            }
            if (!emitted_class_closure) {
                finalize_codegen(classname);
                emitted_class_closure = 1;
            }
        }
        parse_completed = 1;
        free(classname);
        symboltable_pop();
    }
    ;

decl_list:
    decl_list declaration
    | declaration
    ;

declaration:
      func_decl
    | var_decl
    | const_decl
    ;

func_decl:
    // 無參數函式（如 void main()）
    type ID LPAREN RPAREN {
        current_function_return_type = $1;
        register_function($2, $1, NULL, 0);

        if (strcmp($2, "main") == 0) {
            if ($1 != TYPE_VOID) {
                yyerror("main function must be declared as 'void main()'");
            }
            emit_main_prologue();  // 正確產生 main(java.lang.String[])
        } else {
            const char *ret_str = ($1 == 0) ? "int" :
                                  ($1 == 1) ? "boolean" : "void";
            emit_function_start($2, ret_str, 0, NULL);
        }

        symboltable_push();
    } block {
        // 如果是 void 函式（例如 main），補上 return
        if (current_function_return_type == TYPE_VOID) {
            codegen_emit_return();
        }
        codegen_emit_function_epilogue();
        symboltable_pop();
    }

    // 有參數函式
    | type ID LPAREN {
        symboltable_push();  // ⚠️ 先建立 scope 再處理 param
      } param_list RPAREN {
        current_function_return_type = $1;
        register_function($2, $1, param_types_temp, param_count_temp);
        symboltable_reset_local_index(symboltable_top());

        const char *ret_str = ($1 == 0) ? "int" :
                              ($1 == 1) ? "boolean" : "void";
        emit_function_start($2, ret_str, param_count_temp, param_types_temp);

        param_count_temp = 0;
      } block {
        if (current_function_return_type == TYPE_VOID) {
            codegen_emit_return();
        }
        codegen_emit_function_epilogue();
        symboltable_pop();
      }
    ;

type:
      INT    { $$ = 0; }
    | BOOL   { $$ = 1; }
    | VOID   { $$ = 2; }
    ;

var_decl:
    // 宣告變數（無初始值）
      type ID SEMICOLON {
        emit_source_comment();

        if (symboltable_top()->prev == NULL) {
            // 在 global scope
            symboltable_insert_global($2, $1);
            fprintf(out, "field static %s %s\n", 
                $1 == 0 ? "int" : "boolean", $2);
        } else {
            // local scope
            symboltable_allocate_local(symboltable_top(), $2, $1);
        }
      }

    // 宣告變數並賦值
    | type ID ASSIGN expression SEMICOLON {
        emit_source_comment();

        if (symboltable_top()->prev == NULL) {
            // global scope
            symboltable_insert_global($2, $1);
            fprintf(out, "field static %s %s\n", 
                $1 == 0 ? "int" : "boolean", $2);
            codegen_emit_store_variable($2);  // putstatic
        } else {
            // local scope
            int idx = symboltable_allocate_local(symboltable_top(), $2, $1);
            emit_istore(idx);  // istore
        }
      }

    // 賦值語句（變數已存在）
    | ID ASSIGN expression SEMICOLON {
        emit_source_comment();

        int tmp;
        if (symboltable_lookup_const(symboltable_top(), $1, &tmp)) {
            yyerror("assignment error: cannot assign to a constant");
        }

        int idx = symboltable_get_local_index(symboltable_top(), $1);
        if (idx >= 0) {
            emit_istore(idx);
        } else {
            // 若不是 local，預設為 global
            symboltable_insert_global($1, 0);
            codegen_emit_store_variable($1);
        }
      }
    ;


const_decl:
    CONST type ID ASSIGN expression SEMICOLON {
        symboltable_insert_const(symboltable_top(), $3, $2, $5);
      }
    ;

block:
    LBRACE {
        emit_source_comment();
    } decl_or_stmt_list RBRACE {
        emit_source_comment();
    }
  | LBRACE decl_or_stmt_list error {
      yyerrok;
      emit_source_comment();
      if (!emitted_main_epilogue) {
          emit_main_epilogue();
          emitted_main_epilogue = 1;
      }
      if (!emitted_class_closure) {
          finalize_codegen(classname);
          emitted_class_closure = 1;
      }
     }
    | LBRACE error RBRACE {
        yyerrok;
        emit_source_comment();
    }
;

decl_or_stmt_list:
    decl_or_stmt_list decl_or_stmt
    | /* empty */
    ;

decl_or_stmt:
    var_decl
  | const_decl
  | statement
    ;

args_passed:
      /* empty */ { arg_pass_count = 0; }
    | expression {
        arg_pass_types[0] = $1;
        arg_pass_count = 1;
    }
    | args_passed COMMA expression {
        arg_pass_types[arg_pass_count++] = $3;
    }
    ;

param_list:
    param
  | param_list COMMA param
  ;

param:
    type ID {
        int idx = param_index++;
        symboltable_allocate_local(symboltable_top(), $2, $1);
        param_types_temp[param_count_temp++] = $1;
    }
  ;
statement:
      block
    | PRINT expression SEMICOLON {
        emit_source_comment();
    
        // expression 已經先產出值在 stack 上，例如 -c 的結果
        // 現在才 emit getstatic & print
        fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
    
        if ($2 == 0)
            fprintf(out, "invokevirtual void java.io.PrintStream.print(int)\n");
        else if ($2 == 1)
            fprintf(out, "invokevirtual void java.io.PrintStream.print(boolean)\n");
        else if ($2 == 2)
            fprintf(out, "invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
        else
            yyerror("Unsupported print type");
      }
    | PRINT expression_list SEMICOLON {
        emit_source_comment();
        codegen_emit_print("int", NULL);
      }
    | PRINTLN expression_list SEMICOLON {
        emit_source_comment();
        codegen_emit_println("int", NULL);
      }
    | PRINTLN STRING SEMICOLON {
        emit_source_comment();
        codegen_emit_println("java.lang.String", $2);
      }
    | PRINTLN expression SEMICOLON {
        emit_source_comment();
    
        // expression 的值已經在 stack 上
        fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
    
        if ($2 == 0)
            fprintf(out, "invokevirtual void java.io.PrintStream.println(int)\n");
        else if ($2 == 1)
            fprintf(out, "invokevirtual void java.io.PrintStream.println(boolean)\n");
        else if ($2 == 2)
            fprintf(out, "invokevirtual void java.io.PrintStream.println(java.lang.String)\n");
        else
            yyerror("Unsupported println type");
      }
    | PRINTLN STRINGLIT SEMICOLON {
          emit_source_comment();
          fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
          codegen_emit_string($2);
          fprintf(out, "invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
      }
    | RETURN SEMICOLON {
        emit_source_comment();
        if (current_function_return_type != 2) {
            yyerror("type error: return value missing for non-void function");
        }
        codegen_emit_return();
      }
    | RETURN expression SEMICOLON {
        emit_source_comment();
        if (current_function_return_type == 2) {
            yyerror("type error: void function should not return a value");
        } else if ($2 != current_function_return_type) {
            yyerror("type error: return type does not match function declaration");
        }
        codegen_emit_return_value();
      }
    | error SEMICOLON {
        emit_source_comment();
        yyerror("invalid statement");
        yyerrok;
      }
    | IF LPAREN expression RPAREN statement ELSE statement {
        emit_source_comment();
        int label_else = new_label();
        int label_end = new_label();
        codegen_emit_if_eq_zero(label_else);   // if (表達式==0) 跳 else
        codegen_emit_goto(label_end);          // skip else
        codegen_emit_label(label_else);        // ELSE block
        codegen_emit_label(label_end);         // end
      }
    | WHILE LPAREN expression RPAREN statement {
        emit_source_comment();
        int label_else = new_label();
        int label_end = new_label();
        codegen_emit_if_eq_zero(label_else); // false -> else
        codegen_emit_goto(label_end);        // 跳過 else
        codegen_emit_label(label_else);      // else 標籤
        codegen_emit_label(label_end);       // end 標籤
      }
    | ID ASSIGN expression SEMICOLON {
        emit_source_comment();
        int tmp;
        if (symboltable_lookup_const(symboltable_top(), $1, &tmp)) {
            yyerror("assignment error: cannot assign to a constant");
        }

        int idx = symboltable_get_local_index(symboltable_top(), $1);
        if (idx >= 0) emit_istore(idx);
        else codegen_emit_store_variable($1);
      }
    | FOR LPAREN ID ASSIGN expression SEMICOLON expression SEMICOLON ID ASSIGN expression RPAREN statement {
        emit_source_comment();
        int label_start = new_label();
        int label_end = new_label();
        int idx = symboltable_get_local_index(symboltable_top(), $3);
        emit_istore(idx);
        codegen_emit_label(label_start);
        codegen_emit_if_eq_zero(label_end);
        emit_istore(idx);
        codegen_emit_goto(label_start);
        codegen_emit_label(label_end);
      }
    | FOREACH LPAREN ID COLON expression DOTDOT expression RPAREN statement {
        emit_source_comment();
        int label_start = new_label();
        int label_end = new_label();
        int idx = symboltable_allocate_local(symboltable_top(), $3, 0);
        emit_istore(idx);
        codegen_emit_arith_op("isub");
        codegen_emit_if_gt(label_end);
        emit_iload(idx);
        codegen_emit_integer(1);
        codegen_emit_arith_op("iadd");
        emit_istore(idx);
        codegen_emit_goto(label_start);
        codegen_emit_label(label_end);
      }
;

expression_list:
    expression
    | expression_list COMMA expression
    ;

expression:
      INTNUM {
        codegen_emit_integer($1);
        $$ = 0;
      }
    | STRINGLIT {
        codegen_emit_string($1);
        $$ = 2;  // type 2 = string
      }
    | ID {
        int const_val;
        if (symboltable_lookup_const(symboltable_top(), $1, &const_val)) {
            codegen_emit_integer(const_val);
            $$ = 0;
        } else {
            int type = symboltable_lookup(symboltable_top(), $1);
            if (type == -1) {
                yyerror("use of undeclared variable");
            }

            int idx = symboltable_get_local_index(symboltable_top(), $1);
            if (idx >= 0) emit_iload(idx);
            else codegen_emit_load_variable($1);

            $$ = type;  // ← 這樣也省得再呼叫一次 get_type
        }
      }
    | ID LPAREN args_passed RPAREN {
         func_signature* sig = lookup_function($1);
         if (!sig) yyerror("function not declared");
         else if (sig->param_count != arg_pass_count) yyerror("function argument count mismatch");
         else {
           for (int i = 0; i < arg_pass_count; i++) {
             if (sig->param_types[i] != arg_pass_types[i]) {
               yyerror("function argument type mismatch");
               break;
             }
           }
         }
         codegen_emit_function_call($1, arg_pass_count, sig ? (sig->return_type == 0 ? "int" : "boolean") : "int");
         $$ = sig ? sig->return_type : 0;
      }
    | MINUS expression %prec UMINUS {
        if ($2 != 0) yyerror("type error: unary '-' requires int operand");
        codegen_emit_arith_op("ineg"); $$ = 0;
      }
    | LPAREN expression RPAREN { $$ = $2; }
    | expression PLUS expression {
        if ($1 != 0 || $3 != 0) yyerror("type error: '+' requires int operands");
        codegen_emit_arith_op("iadd"); $$ = 0;
      }
    | expression MINUS expression {
        if ($1 != 0 || $3 != 0) yyerror("type error: '-' requires int operands");
        codegen_emit_arith_op("isub"); $$ = 0;
      }
    | expression STAR expression {
        if ($1 != 0 || $3 != 0) yyerror("type error: '*' requires int operands");
        codegen_emit_arith_op("imul"); $$ = 0;
      }
    | expression SLASH expression {
        if ($1 != 0 || $3 != 0) yyerror("type error: '/' requires int operands");
        codegen_emit_arith_op("idiv"); $$ = 0;
      }
    | expression MOD expression {
        if ($1 != 0 || $3 != 0) yyerror("type error: '%' requires int operands");
        codegen_emit_arith_op("irem"); $$ = 0;
      }
    | expression LT expression {
        if ($1 != 0 || $3 != 0) yyerror("type error: '<' requires int operands");
        codegen_emit_relop("<"); $$ = 1;
      }
    | expression LE expression {
        if ($1 != 0 || $3 != 0) yyerror("type error: '<=' requires int operands");
        codegen_emit_relop("<="); $$ = 1;
      }
    | expression EQ expression {
        if ($1 != $3) yyerror("type error: '==' requires same operand types");
        codegen_emit_relop("=="); $$ = 1;
      }
    | expression NE expression {
        if ($1 != $3) yyerror("type error: '!=' requires same operand types");
        codegen_emit_relop("!="); $$ = 1;
      }
    | expression GE expression {
        if ($1 != 0 || $3 != 0) yyerror("type error: '>=' requires int operands");
        codegen_emit_relop(">="); $$ = 1;
      }
    | expression GT expression {
        if ($1 != 0 || $3 != 0) yyerror("type error: '>' requires int operands");
        codegen_emit_relop(">"); $$ = 1;
      }
    | expression AND expression {
        if ($1 != 1 || $3 != 1) yyerror("type error: '&&' requires bool operands");
        codegen_emit_logic_op("&&"); $$ = 1;
      }
    | expression OR expression {
        if ($1 != 1 || $3 != 1) yyerror("type error: '||' requires bool operands");
        codegen_emit_logic_op("||"); $$ = 1;
      }
    | NOT expression {
        if ($2 != 1) yyerror("type error: '!' requires bool operand");
        codegen_emit_logic_op("!"); $$ = 1;
      }

%%



void load_source_lines(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), f)) {
        source_lines[source_line_count++] = strdup(buffer);
    }

    fclose(f);
}

static int last_error_line = -1;
static int emitted_recovery = 0;

void yyerror(const char *msg) {
    if (yylineno == last_error_line) return;
    last_error_line = yylineno;
    had_error = 1;

    fprintf(stderr, "Error at line %d: %s (token: '%s')\n\n", yylineno, msg, yytext);
    
    if (out) {
        fprintf(out, "/* Error recovery: forced class closure */\n");

        if (!emitted_main_epilogue) {
            emit_main_epilogue();         // 補 main 結尾
            emitted_main_epilogue = 1;
        }

        if (!emitted_class_closure) {
            finalize_codegen(classname);  // 補 class 結尾
            emitted_class_closure = 1;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.sd> [output.jasm]\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror(argv[1]);
        return 1;
    }

    yyin = input_file;
    yyin_filename = argv[1];
    const char *output_filename = (argc >= 3) ? argv[2] : "out.jasm";

    init_codegen_file(output_filename);
    classname = get_class_name(argv[1]);
    load_source_lines(argv[1]);

    yyparse();

    printf("\n--- Full Source Code ---\n");
    for (int i = 0; i < source_line_count; ++i) {
        printf("%3d | %s", i + 1, source_lines[i]);
    }

    close_codegen_file();  
    fclose(input_file);

    FILE* bytecode = fopen(output_filename, "r");  
    if (bytecode) {
        char line[1024];
        while (fgets(line, sizeof(line), bytecode)) {
            fputs(line, stdout);
        }
        fclose(bytecode);
    }

    return 0;
}

