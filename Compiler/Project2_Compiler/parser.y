%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"

symboltable* global_table = NULL;

int yylex(void);
void yyerror(const char *msg);
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
#define Trace(t) printf(t)
int current_type = -1;
%}

%union {
    int    ival;
    float  fval;
    char*  sval;
}

%token <ival> INTNUM
%token <fval> FLOATNUM
%token <sval> STRING ID
%token BOOL TRUE FALSE CONST VOID
%token INT FLOAT
%token IF ELSE WHILE FOR FOREACH RETURN
%token PRINT PRINTLN READ
%token PLUS MINUS STAR SLASH MOD UMINUS
%token LT LE EQ GE GT NE AND OR NOT
%token ASSIGN INC DEC
%token SEMICOLON COMMA COLON DOTDOT
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE
%type <ival> expression expression_list print_args
%start program
%type <ival> type

%%
for_init_opt:
    ID ASSIGN expression { Trace("Reducing to for_init\n"); }
  | /* empty */ { Trace("Reducing to for_init (empty)\n"); }
;
expression_opt:
    expression { Trace("Reducing to for_condition\n"); }
  | /* empty */ { Trace("Reducing to for_condition (empty)\n"); }
;
for_step_opt:
    ID ASSIGN expression { Trace("Reducing to for_step (assign)\n"); }
  | ID INC { Trace("Reducing to for_step (inc)\n"); }
  | ID DEC { Trace("Reducing to for_step (dec)\n"); }
  | expression { Trace("Reducing to for_step (expr)\n"); }
  | /* empty */ { Trace("Reducing to for_step (empty)\n"); }
;
program:
    decl_list { Trace("Reducing to program\n"); }
    ;

decl_list:
    decl_list declaration { Trace("Reducing to decl_list\n"); }
    | declaration { Trace("Reducing to decl_list\n"); }
    ;

declaration:
      func_decl { Trace("Reducing to func_decl\n"); }
    | var_decl { Trace("Reducing to var_decl\n"); }
    | const_decl { Trace("Reducing to const_decl\n"); }
    ;

func_decl:
      type ID LPAREN param_list_opt RPAREN block { Trace("Reducing to func_decl (typed)\n"); }
    | VOID ID LPAREN param_list_opt RPAREN block { Trace("Reducing to func_decl (void)\n"); }
    ;

type:
      INT    { Trace("Reducing to type (int)\n"); $$ = 0; }
    | FLOAT  { Trace("Reducing to type (float)\n"); $$ = 1; }
    | BOOL   { Trace("Reducing to type (bool)\n"); $$ = 2; }
    | STRING { Trace("Reducing to type (string)\n"); $$ = 3; }
    | VOID   { Trace("Reducing to type (void)\n"); $$ = 4; }
    ;

param_list_opt:
    param_list { Trace("Reducing to param_list_opt\n"); }
    | /* empty */ { Trace("Reducing to param_list_opt (empty)\n"); }
    ;

param_list:
    param { Trace("Reducing to param_list\n"); }
    | param_list COMMA param { Trace("Reducing to param_list\n"); }
    ;

param:
      type ID {
          Trace("Reducing to param\n");
          symboltable_insert(global_table, $2, $1);
      }
    | type ID array_size_list {
          Trace("Reducing to array_param\n");
          symboltable_insert(global_table, $2, $1);
      }
    ;

var_decl:
      type ID SEMICOLON {
        Trace("Reducing to var_decl (single)\n");
        symboltable_insert(global_table, $2, $1);
    }
    | type ID ASSIGN expression SEMICOLON {
        Trace("Reducing to var_decl (init)\n");
        symboltable_insert(global_table, $2, $1);
    }
    | type ID array_size_list SEMICOLON {
        Trace("Reducing to var_decl (array)\n");
        symboltable_insert(global_table, $2, $1); 
    }
    ;

const_decl:
    CONST type ID ASSIGN expression SEMICOLON {
        Trace("Reducing to const_decl\n");
        symboltable_insert(global_table, $3, $2);
    }
    ;

array_size_list:
    array_size { Trace("Reducing to array_size_list\n"); }
    | array_size_list array_size { Trace("Reducing to array_size_list\n"); }
    ;

array_size:
    LBRACK INTNUM RBRACK { Trace("Reducing to array_size\n"); }
    ;

block:
    LBRACE decl_or_stmt_list RBRACE { Trace("Reducing to block\n"); }
    ;

decl_or_stmt_list:
    decl_or_stmt_list decl_or_stmt { Trace("Reducing to decl_or_stmt_list\n"); }
    | /* empty */ { Trace("Reducing to decl_or_stmt_list (empty)\n"); }
    ;

decl_or_stmt:
      var_decl
    | const_decl
    | statement
    ;

statement:
      block { Trace("Reducing to block as statement\n"); }
    | PRINT LPAREN print_args RPAREN SEMICOLON { Trace("Reducing to print_stmt\n"); }
    | PRINTLN LPAREN print_args RPAREN SEMICOLON { Trace("Reducing to println_stmt\n"); }
    | PRINT expression_list SEMICOLON { Trace("Reducing to print_stmt (no parens)\n"); }
    | PRINTLN expression_list SEMICOLON { Trace("Reducing to println_stmt (no parens)\n"); }
    | PRINT SEMICOLON { Trace("Reducing to print_stmt (empty)\n"); }
    | PRINTLN SEMICOLON { Trace("Reducing to println_stmt (empty)\n"); }
    | proc_call_stmt { Trace("Reducing to proc_call_stmt\n"); }
    | READ ID SEMICOLON { Trace("Reducing to read_stmt\n"); }
    | RETURN SEMICOLON { Trace("Reducing to return_stmt (empty)\n"); }
    | RETURN expression SEMICOLON { Trace("Reducing to return_stmt\n"); }
    | IF LPAREN expression RPAREN statement { Trace("Reducing to if_stmt\n"); }
    | IF LPAREN expression RPAREN statement ELSE statement { Trace("Reducing to if_else_stmt\n"); }
    | WHILE LPAREN expression RPAREN statement { Trace("Reducing to while_stmt\n"); }
    | FOREACH LPAREN ID COLON expression DOTDOT expression RPAREN statement { Trace("Reducing to foreach_stmt\n"); }
    | ID ASSIGN expression SEMICOLON { Trace("Reducing to assignment_stmt\n"); }
    | ID INC SEMICOLON { Trace("Reducing to inc_stmt\n"); }
    | ID DEC SEMICOLON { Trace("Reducing to dec_stmt\n"); }
    | FOR LPAREN for_init_opt SEMICOLON expression_opt SEMICOLON for_step_opt RPAREN statement { Trace("Reducing to for_stmt (with options)\n"); }
    | ID LBRACK expression RBRACK ASSIGN expression SEMICOLON { Trace("Reducing to array_assign_stmt\n"); }
    ;

print_args:
    expression_list { Trace("Reducing to print_args\n"); }
    | /* empty */ { Trace("Reducing to print_args (empty)\n"); }
    ;

proc_call_stmt:
    ID LPAREN arg_list_opt RPAREN SEMICOLON { Trace("Reducing to proc_call_stmt\n"); }
    ;

arg_list_opt:
    arg_list { Trace("Reducing to arg_list_opt\n"); }
    | /* empty */ { Trace("Reducing to arg_list_opt (empty)\n"); }
    ;

arg_list:
    expression { Trace("Reducing to arg_list\n"); }
    | arg_list COMMA expression { Trace("Reducing to arg_list\n"); }
    ;

expression_list:
    expression { Trace("Reducing to expression_list\n"); }
    | expression_list COMMA expression { Trace("Reducing to expression_list\n"); }
    ;

expression:
      INTNUM { Trace("Reducing to expression (int)\n"); }
    | FLOATNUM { Trace("Reducing to expression (float)\n"); }
    | ID { Trace("Reducing to expression (id)\n"); }
    | STRING { Trace("Reducing to expression (string)\n"); }
    | TRUE { Trace("Reducing to expression (true)\n"); }
    | FALSE { Trace("Reducing to expression (false)\n"); }
    | expression PLUS expression { Trace("Reducing to expression (+)\n"); }
    | expression MINUS expression { Trace("Reducing to expression (-)\n"); }
    | expression STAR expression { Trace("Reducing to expression (*)\n"); }
    | expression SLASH expression { Trace("Reducing to expression (/)\n"); }
    | expression MOD expression { Trace("Reducing to expression (%%)\n"); }
    | expression LT expression { Trace("Reducing to expression (<)\n"); }
    | expression LE expression { Trace("Reducing to expression (<=)\n"); }
    | expression EQ expression { Trace("Reducing to expression (==)\n"); }
    | expression GE expression { Trace("Reducing to expression (>=)\n"); }
    | expression GT expression { Trace("Reducing to expression (>)\n"); }
    | expression NE expression { Trace("Reducing to expression (!=)\n"); }
    | expression AND expression { Trace("Reducing to expression (&&)\n"); }
    | expression OR expression { Trace("Reducing to expression (||)\n"); }
    | NOT expression { Trace("Reducing to expression (!)\n"); }
    | MINUS expression %prec UMINUS { Trace("Reducing to expression (unary -)\n"); }
    | INC expression { Trace("Reducing to expression (prefix ++)\n"); }
    | DEC expression { Trace("Reducing to expression (prefix --)\n"); }
    | expression INC { Trace("Reducing to expression (postfix ++)\n"); }
    | expression DEC { Trace("Reducing to expression (postfix --)\n"); }
    | ID LPAREN arg_list_opt RPAREN { Trace("Reducing to function_call_expr\n"); }
    | LPAREN expression RPAREN { Trace("Reducing to expression (group)\n"); }
    | ID LBRACK expression RBRACK { Trace("Reducing to array_access_expr\n"); }
    ;

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Error at line %d: %s (token: %s)\n", yylineno, msg, yytext);
}

int main(int argc, char *argv[]) {
    global_table = symboltable_create(256);

    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("fopen");
            return 1;
        }
    } else {
        yyin = stdin;
    }

    int result = yyparse();

    printf("\n=== Symbol Table Dump ===\n");
    symboltable_dump(global_table); 

    return result;
}