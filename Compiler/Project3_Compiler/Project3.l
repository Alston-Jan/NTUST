%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char current_line[1024];  // 儲存當前原始碼行
int current_pos = 0;

#define token(s,t) { return t; }

%}

%%

"int"       { token("INT", INT); }
"bool"      { token("BOOL", BOOL); }
"true"      { token("TRUE", TRUE); }
"false"     { token("FALSE", FALSE); }
"const"     { token("CONST", CONST); }
"void"      { token("VOID", VOID); }
"if"        { token("IF", IF); }
"else"      { token("ELSE", ELSE); }
"while"     { token("WHILE", WHILE); }
"for"       { token("FOR", FOR); }
"foreach"   { token("FOREACH", FOREACH); }
"return"    { token("RETURN", RETURN); }
"print"     { token("PRINT", PRINT); }
"println"   { token("PRINTLN", PRINTLN); }

"+"         { token("+", PLUS); }
"-"         { token("-", MINUS); }
"*"         { token("*", STAR); }
"/"         { token("/", SLASH); }
"%"         { token("%", MOD); }
"<"         { token("<", LT); }
"<="        { token("<=", LE); }
"=="        { token("==", EQ); }
">="        { token(">=", GE); }
">"         { token(">", GT); }
"!="        { token("!=", NE); }
"&&"        { token("&&", AND); }
"||"        { token("||", OR); }
"!"         { token("!", NOT); }

"="         { token("=", ASSIGN); }
";"         { token(";", SEMICOLON); }
","         { token(",", COMMA); }
":"         { token(":", COLON); }
".."        { token("..", DOTDOT); }
"("         { token("(", LPAREN); }
")"         { token(")", RPAREN); }
"{"         { token("{", LBRACE); }
"}"         { token("}", RBRACE); }

\"[^\"]*\" {
    yytext[yyleng - 1] = '\0'; 
    yylval.sval = strdup(yytext + 1); 
    return STRINGLIT;
}

[0-9]+         {
    yylval.ival = atoi(yytext);
    token("INTNUM", INTNUM);
}

[a-zA-Z_][a-zA-Z_0-9]* {
    yylval.sval = strdup(yytext);
    token("ID", ID);
}

[ \t\r]+      { /* skip whitespace */ }
\n {
    current_line[current_pos] = '\0';  // 儲存當前行內容（若你還需要原始碼）
    current_pos = 0;                   // 重設行內字元位置
    yylineno++;                        // 換行
}
. { printf("Unknown character: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}