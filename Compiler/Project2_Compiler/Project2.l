
%x COMMENT

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"
#include "parser.tab.h"

extern YYSTYPE yylval;
#define YY_USER_INIT yylineno = 1;

char current_line[1024];
int last_printed_line = -1;
int col_index = 0;

#define YY_USER_ACTION \
    if (yytext[0] == '\n') { \
        current_line[col_index] = '\0'; \
        printf("[Line %d] %s\n", yylineno - 1, current_line); \
        col_index = 0; \
        current_line[0] = '\0'; \
    } else { \
        size_t len = strlen(yytext); \
        if (col_index + len < sizeof(current_line) - 1) { \
            memcpy(current_line + col_index, yytext, len); \
            col_index += len; \
            current_line[col_index] = '\0'; \
        } \
    }

#define print_line() \
    if (last_printed_line != yylineno) { \
        last_printed_line = yylineno; \
    }

#define token(s,t) { print_line(); printf("<%s>\n", s); fflush(stdout); return t; }
#define tokenval(s,t,val) { print_line(); printf("<%s:%s>\n", s, val); fflush(stdout); yylval.sval = strdup(val); return t; }
%}

%option yylineno

DIGIT   [0-9]
ID      [a-zA-Z_][a-zA-Z_0-9]*
NUM     {DIGIT}+
STRING  \"([^\\\"]|\\.)*\"

%%

"const"        { token("CONST", CONST); }
"int"          { token("INT", INT); }
"float"        { token("FLOAT", FLOAT); }
"bool"         { token("BOOL", BOOL); }
"string"       { token("STRING", STRING); }
"true"         { token("TRUE", TRUE); }
"false"        { token("FALSE", FALSE); }
"void"         { token("VOID", VOID); }

"if"           { token("IF", IF); }
"else"         { token("ELSE", ELSE); }
"while"        { token("WHILE", WHILE); }
"for"          { token("FOR", FOR); }
"foreach"      { token("FOREACH", FOREACH); }
"return"       { token("RETURN", RETURN); }

"print"        { token("PRINT", PRINT); }
"println"      { token("PRINTLN", PRINTLN); }
"read"         { token("READ", READ); }

"++"           { token("++", INC); }
"--"           { token("--", DEC); }
"+"            { token("+", PLUS); }
"-"            { token("-", MINUS); }
"*"            { token("*", STAR); }
"/"            { token("/", SLASH); }
"%"            { token("%", MOD); }
"<="           { token("<=", LE); }
"<"            { token("<", LT); }
"=="           { token("==", EQ); }
">="           { token(">=", GE); }
">"            { token(">", GT); }
"!="           { token("!=", NE); }
"&&"           { token("&&", AND); }
"||"           { token("||", OR); }
"!"            { token("!", NOT); }
"="            { token("=", ASSIGN); }

";"            { token(";", SEMICOLON); }
","            { token(",", COMMA); }
":"            { token(":", COLON); }
".."           { token("..", DOTDOT); }
"("            { token("(", LPAREN); }
")"            { token(")", RPAREN); }
"["            { token("[", LBRACK); }
"]"            { token("]", RBRACK); }
"{"            { token("{", LBRACE); }
"}"            { token("}", RBRACE); }

{NUM}"."{NUM}  { yylval.fval = atof(yytext); token("FLOATNUM", FLOATNUM); }
{NUM}          { yylval.ival = atoi(yytext); token("INTNUM", INTNUM); }
{STRING}       {
                  char* val = strdup(yytext);
                  val[strlen(val)-1] = '\0';
                  tokenval("STRING", STRING, val + 1);
              }
{ID}           { tokenval("ID", ID, yytext); }

"//".*         { print_line(); printf("<COMMENT>\n"); fflush(stdout); }
"/*"           { BEGIN(COMMENT); }
<COMMENT>[^*\n]* { /* skip */ }
<COMMENT>"*"+[^*/\n]* { /* skip */ }
<COMMENT>"*/"   { BEGIN(INITIAL); print_line(); printf("<MULTILINE_COMMENT>\n"); fflush(stdout); }
<COMMENT>\n     { /* handled by YY_USER_ACTION */ }

[\t\r ]+       { /* skip whitespace */ }
\n              { /* handled in YY_USER_ACTION */ }
.                { print_line(); printf("Unknown character: %s\n", yytext); }

%%

int yywrap(void) {
    return 1;
}
