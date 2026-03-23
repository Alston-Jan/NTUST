%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%
"fun"       { return FUN; }
"main"      { return MAIN; }
"var"       { return VAR; }
"int"       { return INT_TYPE; }
"real"      { return REAL_TYPE; }
"print"     { return PRINT; }
"println"   { return PRINTLN; }
"ret"       { return RETURN; }
"for"       { return FOR; }
":"         { return COLON; }
"["         { return LBRACKET; }
"]"         { return RBRACKET; }
[0-9]+"."[0-9]+ { yylval.real_val = atof(yytext); return REAL; }
[0-9]+      { yylval.int_val = atoi(yytext); return INT; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.id = strdup(yytext); return ID; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"="         { return ASSIGN; }
"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
";"         { return SEMICOLON; }
","         { return COMMA; }
"\n"        { /* ignore newline */ }
[ \t]       { /* ignore whitespace */ }
.           { /* ignore any other character */ }
%%
