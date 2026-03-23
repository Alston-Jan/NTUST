%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;

void yyerror(const char *s);

%}

%union {
    int int_val;
    double real_val;
    char *id;
}

%token <int_val> INT
%token <real_val> REAL
%token <id> ID

%token FUN MAIN VAR PRINT PRINTLN RETURN FOR
%token INT_TYPE REAL_TYPE
%token PLUS MINUS MUL DIV ASSIGN
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA COLON
%token LBRACKET RBRACKET

%start program

%%

program:
    function_declaration
;

function_declaration:
    FUN MAIN LPAREN RPAREN LBRACE statement_list RBRACE
;

statement_list:
    statement_list statement
    | statement
;

statement:
    variable_declaration SEMICOLON
    | assignment SEMICOLON
    | print_statement SEMICOLON
    | println_statement SEMICOLON
    | RETURN expression SEMICOLON
    | for_statement
;

variable_declaration:
    VAR ID COLON type
    | VAR ID COLON type ASSIGN expression
    | VAR ID COLON type LBRACKET INT RBRACKET
    | VAR ID COLON type LBRACKET INT RBRACKET ASSIGN LBRACE init_list RBRACE
;

type:
    INT_TYPE
    | REAL_TYPE
;

init_list:
    init_list COMMA expression
    | expression
;

assignment:
    ID ASSIGN expression
;

print_statement:
    PRINT LPAREN expression RPAREN
;

println_statement:
    PRINTLN LPAREN expression RPAREN
;

for_statement:
    FOR LPAREN ID COLON ID ASSIGN expression TO expression RPAREN LBRACE statement_list RBRACE
;

expression:
    expression PLUS expression
    | expression MINUS expression
    | expression MUL expression
    | expression DIV expression
    | LPAREN expression RPAREN
    | INT
    | REAL
    | ID
    | ID LBRACKET expression RBRACKET
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }
    yyparse();
    return 0;
}
