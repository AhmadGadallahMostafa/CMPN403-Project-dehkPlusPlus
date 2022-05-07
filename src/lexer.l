%{
    #include <stdio.h>
    #include <stdlib.h>
%}

 /*Here we will define our tokens and rules for each token  
   Rules are matched with priority such that it will return the lexeme of the first match
 */
%%

 /*First we will define the datatypes of the variables, defined first as to be of the highest priority */
int {printf("Integer declartion\n "); return INT;}
float {printf("Float declaration\n "); return FLOAT;}
char {printf("Character declaration\n "); return CHAR;}
string {printf("String declaration\n "); return STRING;}
bool {printf("Boolean declaration\n "); return BOOL;}

 /*Resereved keywords for the programming lang, we will not allow for users to use reserved keywords as identifiers later on */
for {printf("For loop\n "); return FOR;}
while {printf("While loop\n "); return WHILE;}
do {printf("Do while loop\n "); return DO;}
break {printf("Break statement\n "); return BREAK;}
continue {printf("Continue statement\n "); return CONTINUE;}
if {printf("If statement\n "); return IF;}
else {printf("Else statement\n "); return ELSE;}
elseif {printf("Else if statement\n "); return ELSEIF;}
switch {printf("Switch statement\n "); return SWITCH;}
case {printf("Case statement\n "); return CASE;}
default {printf("Default statement\n "); return DEFAULT;}
constant {printf("Constant declaration\n "); return CONSTANT;}
return {printf("Return statement\n "); return RETURN;}

 /*Constants*/
[0-9]+  {printf("Integer\n "); yylval.integerValue = atoi(yytext); return INT_VALUE;}
[0-9]+\.[0-9]+  {printf("Float\n "); yylval.floatValue = atof(yytext); return FLOAT_VALUE;}
["]([^\n\t\r\f\v\ ])*["]  {printf("String\n "); yylval.stringValue = yytext; return STRING_VALUE;}
[']([^\n\t\r\f\v\ ])['] {printf("Character\n "); yylval.charValue = yytext[1]; return CHAR_VALUE;}
true    {printf("Boolean value true\n "); return BOOL_VALUE_TRUE;}
false   {printf("Boolean value false\n "); return BOOL_VALUE_FALSE;}
#.*#      {printf("Comment\n "); return COMMENT;}

 /*Identifiers*/
[a-zA-Z_][a-zA-Z0-9_]* {printf("Identifier\n "); return IDENTIFIER;}

 /*Math Operators*/
\= {printf("Assign\n "); return ASSIGN;}
\+ {printf("Add\n "); return ADD;}
\- {printf("Subtract\n "); return SUBTRACT;}
\* {printf("Multiply\n "); return MULTIPLY;}
\/ {printf("Divide\n "); return DIVIDE;}
\% {printf("Modulus\n "); return MODULUS;}
\^ {printf("Exponent\n "); return EXPONENT;}

 /*Logical Operators*/
"&&" {printf("Logical and\n "); return AND;}
"||" {printf("Logical or\n "); return OR;}
"!" {printf("Logical not\n "); return NOT;}

 /*Relational Operators*/
"==" {printf("Equality\n "); return EQUAL;}
"!=" {printf("Inequality\n "); return NOT_EQUAL;}
">" {printf("Greater than\n "); return GREATER_THAN;}
"<" {printf("Less than\n "); return LESS_THAN;}
">=" {printf("Greater than or equal to\n "); return GREATER_THAN_EQUAL;}
"<=" {printf("Less than or equal to\n "); return LESS_THAN_EQUAL;}

 /*Delimiters*/
\( {printf("Left parenthesis\n "); return LEFT_PAREN;}
\) {printf("Right parenthesis\n "); return RIGHT_PAREN;}
\[ {printf("Left bracket\n "); return LEFT_BRACKET;}
\] {printf("Right bracket\n "); return RIGHT_BRACKET;}
\{ {printf("Left brace\n "); return LEFT_BRACE;}
\} {printf("Right brace\n "); return RIGHT_BRACE;}
\, {printf("Comma\n "); return COMMA;}
\; {printf("Semicolon\n "); return SEMICOLON;}
\: {printf("Colon\n "); return COLON;} 
 /*Whitespace*/
" " {printf("Whitespace\n "); return WHITESPACE;}
\t+ {printf("Tab\n "); return TAB;}
\n {printf("Newline\n "); return NEWLINE;}
. {printf("Error\n ");}
%%

int main(void){
    yylex();
    return 0;
}

int yywrap(void){
    return 1;
}