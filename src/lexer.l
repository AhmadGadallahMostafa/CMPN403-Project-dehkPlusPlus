%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <string.h>
    #include "y.tab.h"
    #include "symbol.h"
#include "statments.h"
int yyerror(char *s);
extern "C" int yylex(void);
%}
%option yylineno
/*Here we will define our tokens and rules for each token  
   Rules are matched with priority such that it will return the lexeme of the first match
 */
%%

 /*First we will define the datatypes of the variables, defined first as to be of the highest priority */
int {yylval.stringValue = "int"; return INT;}
float {yylval.stringValue = "float"; return FLOAT;}
char { yylval.stringValue = "char";return CHAR;}
string { yylval.stringValue = "string";return STRING;}
bool { yylval.stringValue = "bool";return BOOL;}
void { yylval.stringValue = "void";return VOID;}

 /*Resereved keywords for the programming lang, we will not allow for users to use reserved keywords as identifiers later on */
for {return FOR;}
while {return WHILE;}
do {return DO;}
break {return BREAK;}
continue { return CONTINUE;}
if {return IF;}
else {return ELSE;}
elseif {return ELSEIF;}
switch {return SWITCH;}
case {return CASE;}
default {return DEFAULT;}
constant {return CONSTANT;}
return {return RETURN;}
def {return DEF;}


 /*Constants*/
[0-9]+  {yylval.stringValue = strdup(yytext); return INT_VALUE;}
[0-9]+\.[0-9]+  { yylval.stringValue = strdup(yytext); return FLOAT_VALUE;}
["]([^\n\t\r\f\v\ ])*["]  {yylval.stringValue = strdup(yytext); return STRING_VALUE;}
[']([^\n\t\r\f\v\ ])['] { yylval.charValue = yytext[1]; return CHAR_VALUE;}
true    {return BOOL_VALUE_TRUE;}
false   {return BOOL_VALUE_FALSE;}
#.*#    {return COMMENT;}

 /*Identifiers*/
[a-zA-Z_][a-zA-Z0-9_]* {yylval.stringValue = strdup(yytext); return IDENTIFIER;}

 /*Math Operators*/
\= {yylval.stringValue="=";return ASSIGN;}
\+ {yylval.stringValue="+";return PLUS;}
\- {yylval.stringValue="-";return MINUS;}
\* {yylval.stringValue="*";return TIMES;}
\/ {yylval.stringValue="/";return DIVIDE;}
\% {yylval.stringValue="%";return MODULUS;}
\^ {yylval.stringValue="^";return EXPONENT;}

 /*Logical Operators*/
"&&" {yylval.stringValue="&&";return AND;}
"||" {yylval.stringValue="||";return OR;}
"!"  {yylval.stringValue="!";return NOT;}

 /*Relational Operators*/
"==" {yylval.stringValue="==";return EQUAL;}
"!=" {yylval.stringValue="!=";return NOTEQUAL;}
">"  {yylval.stringValue=">";return GREATER_THAN;}
"<"  {yylval.stringValue="<";return LESS_THAN;}
">=" {yylval.stringValue=">=";return GREATER_THAN_EQUAL;}
"<=" {yylval.stringValue="<=";return LESS_THAN_EQUAL;}

 /*Delimiters*/
\( {return LEFT_PAREN;}
\) {return RIGHT_PAREN;}
\{ {return LEFT_BRACE;}
\} {return RIGHT_BRACE;}
\, {return COMMA;}
\; {return SEMICOLON;}
\: {return COLON;} 
 /*Whitespace*/
 [ \t\r\n]+                          ; /* ignore whitespace */
%%


int yywrap(void){
    return 1;
}