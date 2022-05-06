%{
    #include <stdio.h>
    #include <stdlib.h>
%}

 /*Here we will define our tokens and rules for each token  
   Rules are matched with priority such that it will return the lexeme of the first match
 */
 
%%

 /*First we will define the datatypes of the variables, defined first as to be of the highest priority */
int {printf("Integer declartion\n ");}
float {printf("Float declaration\n ");}
char {printf("Character declaration\n ");}
string {printf("String declaration\n ");}
bool {printf("Boolean declaration\n ");}

 /*Resereved keywords for the programming lang, we will not allow for users to use reserved keywords as identifiers later on */
for {printf("For loop\n ");}
while {printf("While loop\n ");}
do {printf("Do while loop\n ");}
break {printf("Break statement\n ");}
continue {printf("Continue statement\n ");}
if {printf("If statement\n ");}
else {printf("Else statement\n ");}
elseif {printf("Else if statement\n ");}
switch {printf("Switch statement\n ");}
case {printf("Case statement\n ");}
default {printf("Default statement\n ");}
constant {printf("Constant declaration\n ");}
return {printf("Return statement\n ");}

 /*Constants*/
["]([^\n\t\r\f\v\ ])*["]  {printf("String\n ");}
[0-9]+  {printf("Integer\n ");}
[0-9]+\.[0-9]+  {printf("Float\n ");}
[']([^\n\t\r\f\v\ ])['] {printf("Character\n ");}
true    {printf("Boolean value true\n ");}
false   {printf("Boolean value false\n ");}

 /*Identifiers*/
[a-zA-Z_][a-zA-Z0-9_]* {printf("Identifier\n ");}

 /*Math Operators*/
\= {printf("Assign\n ");}
\+ {printf("Add\n ");}
\- {printf("Subtract\n ");}
\* {printf("Multiply\n ");}
\/ {printf("Divide\n ");}
\% {printf("Modulus\n ");}
\^ {printf("Exponent\n ");}

 /*Logical Operators*/
"&&" {printf("Logical and\n ");}
"||" {printf("Logical or\n ");}
"!" {printf("Logical not\n ");}

 /*Relational Operators*/
"==" {printf("Equality\n ");}
"!=" {printf("Inequality\n ");}
">" {printf("Greater than\n ");}
"<" {printf("Less than\n ");}
">=" {printf("Greater than or equal to\n ");}
"<=" {printf("Less than or equal to\n ");}

 /*Delimiters*/
\( {printf("Left parenthesis\n ");}
\) {printf("Right parenthesis\n ");}
\[ {printf("Left bracket\n ");}
\] {printf("Right bracket\n ");}
\{ {printf("Left brace\n ");}
\} {printf("Right brace\n ");}
\, {printf("Comma\n ");}
\; {printf("Semicolon\n ");}
\: {printf("Colon\n ");}
 /*Whitespace*/
" " {printf("Whitespace\n ");}
\t+ {printf("Tab\n ");}
\n {printf("Newline\n ");}
%%

int main(void){
    yylex();
    return 0;
}

int yywrap(void){
    return 1;
}