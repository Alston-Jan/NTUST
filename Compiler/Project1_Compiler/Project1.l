%{
#define LIST     strcat(buf,yytext)
#define STRLIST strcat(stringBuf,yytext)
#define tokenChar(t) {LIST; printf("<'%s'>\n",t);}
#define token(t) {LIST; printf("<%s>\n",#t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",#t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",#t,s);}
#define LINEFEED {printf("%d: %s", linenum++, buf);buf[0] = '\0';}

#define MAX_LINE_LENG 256
#define MAX_STRING_LENG 256
#define MAX_SYMBOL_COUNT 4096

#include "symboltable.h"

int linenum = 1;
char buf[MAX_LINE_LENG];
char stringBuf[MAX_STRING_LENG];

symboltable* st;

%}

%x COMMENT
%x STRING

A [Aa]
B [Bb]
C [Cc]
D [Dd]
E [Ee]
F [Ff]
G [Gg]
H [Hh]
I [Ii]
J [Jj]
K [Kk]
L [Ll]
M [Mm]
N [Nn]
O [Oo]
P [Pp]
Q [Qq]
R [Rr]
S [Ss]
T [Tt]
U [Uu]
V [Vv]
W [Ww]
X [Xx]
Y [Yy]
Z [Zz]

%%
    /* Delimiters */
[.,:;()\[\]{}] {
    tokenChar(yytext);
}

    /* Arithmetic, Relational, and Logical Operators */
"++" { tokenChar(yytext); }
"--" { tokenChar(yytext); }
"+"  { tokenChar(yytext); }
"-"  { tokenChar(yytext); }
"*"  { tokenChar(yytext); }
"/"  { tokenChar(yytext); }
"%"  { tokenChar(yytext); }

"<=" { tokenChar(yytext); }
">=" { tokenChar(yytext); }
"==" { tokenChar(yytext); }
"!=" { tokenChar(yytext); }
"<"  { tokenChar(yytext); }
">"  { tokenChar(yytext); }

"&&" { tokenChar(yytext); }
"||" { tokenChar(yytext); }
"!"  { tokenChar(yytext); }

"="  { tokenChar(yytext); }

    /* '/*' Style Comment */
"/*" {
    LIST;
    BEGIN(COMMENT);
}
<COMMENT>"*/" {
    LIST;
    BEGIN(INITIAL);
}
<COMMENT>\n {
    LIST;
    LINEFEED;
}
<COMMENT>. {
    LIST;
}

    /* '//' Style Comment' */
"//".* {
    LIST;
}

    /* Keyword */
{B}{O}{O}{L}    {token(BOOL);}
{B}{R}{E}{A}{K}    {token(BREAK);}
{C}{H}{A}{R}    {token(CHAR);}
{C}{A}{S}{E}    {token(CASE);}
{C}{O}{N}{S}{T}    {token(CONST);}
{C}{O}{N}{T}{I}{N}{U}{E}    {token(CONTINUE);}
{D}{E}{F}{A}{U}{L}{T}    {token(DEFAULT);}
{D}{O}    {token(DO);}
{D}{O}{U}{B}{L}{E}      {token(DOUBLE);}
{E}{L}{S}{E}    {token(ELSE);}
{E}{X}{T}{E}{R}{N}    {token(EXTERN);}
{F}{A}{L}{S}{E}    {token(FALSE);}
{F}{L}{O}{A}{T}    {token(FLOAT);}
{F}{O}{R}    {token(FOR);}
{F}{O}{R}{E}{A}{C}{H}    {token(FOREACH);}
{I}{F}    {token(IF);}
{I}{N}{T}    {token(INT);}
{P}{R}{I}{N}{T}    {token(PRINT);}
{P}{R}{I}{N}{T}{L}{N}    {token(PRINTLN);}
{R}{E}{A}{D}    {token(READ);}
{R}{E}{T}{U}{R}{N}    {token(RETURN);}
{S}{T}{R}{I}{N}{G}    {token(STRING);}
{S}{W}{I}{T}{C}{H}    {token(SWITCH);}
{T}{R}{U}{E}    {token(TRUE);}
{V}{O}{I}{D}    {token(VOID);}
{W}{H}{I}{L}{E}    {token(WHILE);}

    /* Identifier */
[A-Za-z][A-Za-z0-9]* {
    tokenString(ID, yytext);
    symboltable_insert(st, yytext);
}

    /* Real */
[+\-]?[0-9]+\.[0-9]+([Ee][+\-]?[1-9][0-9]*)? {
    tokenString(real, yytext);
}
[+\-][0-9]+ {
    tokenString(real, yytext);
}

    /* Integer */
[0-9]+ {
    tokenInteger(integer, atoi(yytext));
}

    /* String */
\" {
    LIST;
    stringBuf[0] = '\0';
    BEGIN(STRING);
}
<STRING>\"{2} {
    LIST;
    strcat(stringBuf,"\"");
}
<STRING>\" {
    tokenString(string, stringBuf);
    BEGIN(INITIAL);
}
<STRING>[^\"\n]* {
    LIST;
    STRLIST;
}
<STRING>\n {
    printf("%d:%s\n", linenum, buf);
    printf("bad line ending, string not closed\n");
    exit(-1);
}


\n {
    LIST;
    LINEFEED;
}

[ \t]+ {
    LIST;
}

. {
    LIST;
    printf("%d:%s\n", linenum+1, buf);
    printf("bad character:'%s'\n",yytext);
    exit(-1);
}
%%

int yywrap() { return 1; }

int main() {
    st = symboltable_create(MAX_SYMBOL_COUNT);
    
    yylex();
    LINEFEED;

    printf("\nSymbol Table:\n");
    symboltable_dump(st);

    return 0;
}