%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <string.h>
    #include "y.tab.h"
%}

/*Here we will define our tokens and rules for each token  
   Rules are matched with priority such that it will return the lexeme of the first match
 */
%%

 /*First we will define the datatypes of the variables, defined first as to be of the highest priority */
int {return INT;}
float {return FLOAT;}
char {return CHAR;}
string {return STRING;}
bool {return BOOL;}
void {return VOID;}

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
[0-9]+  {yylval.integerValue = atoi(yytext); return INT_VALUE;}
[0-9]+\.[0-9]+  { yylval.floatValue = atof(yytext); return FLOAT_VALUE;}
["]([^\n\t\r\f\v\ ])*["]  {yylval.stringValue = yytext; return STRING_VALUE;}
[']([^\n\t\r\f\v\ ])['] { yylval.charValue = yytext[1]; return CHAR_VALUE;}
true    {return BOOL_VALUE_TRUE;}
false   {return BOOL_VALUE_FALSE;}
#.*#    {return COMMENT;}

 /*Identifiers*/
[a-zA-Z_][a-zA-Z0-9_]* {return IDENTIFIER;}

 /*Math Operators*/
\= {return ASSIGN;}
\+ {return PLUS;}
\- {return MINUS;}
\* {return TIMES;}
\/ {return DIVIDE;}
\% {return MODULUS;}
\^ {return EXPONENT;}

 /*Logical Operators*/
"&&" {return AND;}
"||" {return OR;}
"!"  {return NOT;}

 /*Relational Operators*/
"==" {return EQUAL;}
"!=" {return NOTEQUAL;}
">"  {return GREATER_THAN;}
"<"  {return LESS_THAN;}
">=" {return GREATER_THAN_EQUAL;}
"<=" {return LESS_THAN_EQUAL;}

 /*Delimiters*/
\( {return LEFT_PAREN;}
\) {return RIGHT_PAREN;}
\{ {return LEFT_BRACE;}
\} {return RIGHT_BRACE;}
\, {return COMMA;}
\; {return SEMICOLON;}
\: {return COLON;} 
 /*Whitespace*/
\n  {return NEWLINE;}
%%


int yywrap(void){
    return 1;
}