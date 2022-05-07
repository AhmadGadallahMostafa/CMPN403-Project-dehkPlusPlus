%{
#include <stdio.h>
#include <stdlib.h>
File *yyin;
void yyerror(char *s);
int yylex(void);
%}

%token INT FLOAT STRING CHAR BOOL VOID
%token FOR WHILE DO BREAK CONTINUE IF ELSE ELSEIF SWITCH CASE DEFAULT CONSTANT RETURN DEF
%token INT_VALUE FLOAT_VALUE STRING_VALUE CHAR_VALUE BOOL_VALUE_TRUE BOOL_VALUE_FALSE COMMENT
%token IDENTIFIER
%token ASSIGN PLUS MINUS TIMES DIVIDE MODULUS EXPONENT
%token AND OR NOT
%token EQUAL NOTEQUAL GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL
%token LEFT_PAREN RIGHT_PAREN LEFT_BRACKET RIGHT_BRACKET LEFT_BRACE RIGHT_BRACE COMMA SEMICOLON COLON
%token WHITE_SPACE TAB NEWLINE


 /*Defingin assciotaivety and precedence of operators */
%right ASSIGN
%left OR
%left AND 
%left NOT
%left EQUAL NOTEQUAL
%left GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL

%left PLUS MINUS
%left TIMES DIVIDE MODULUS
%right EXPONENT

 /*Defining the grammar */
%start program
%%
program : program statement
| statement;

statement: expr;

expr: variable_declaration
| const_variable_declaration
| variable_assignment
| function_declaration
| function_call
| if_statement
| while_statement
| switch_statement
| break_statement
| continue_statement
| return_statement
| for_statement
| COMMENT

 /*Variable declerations*/
variable_declaration: variable_type IDENTIFIER SEMICOLON
| variable_type IDENTIFIER ASSIGN condtional_expr SEMICOLON;

CONST_VALUE: INT_VALUE | FLOAT_VALUE | STRING_VALUE | CHAR_VALUE | BOOL_VALUE_TRUE | BOOL_VALUE_FALSE;

const_variable_declaration: CONSTANT variable_type IDENTIFIER SEMICOLON
| CONSTANT variable_type IDENTIFIER ASSIGN condtional_expr SEMICOLON;

variable_type: INT | FLOAT | STRING | CHAR | BOOL;

variable_assignment: IDENTIFIER ASSIGN condtional_expr SEMICOLON;

 /*Function declarations */
function_declaration: DEF variable_type IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE
| DEF VOID IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE SEMICOLON;

parameter_list: parameter_list COMMA parameter
| parameter;

parameter: variable_type IDENTIFIER;

/*Function call*/
function_call: IDENTIFIER LEFT_PAREN argument_list RIGHT_PAREN
|  IDENTIFIER ASSIGN IDENTIFIER LEFT_PAREN argument_list RIGHT_PAREN
argument_list: argument_list COMMA argument
| argument;
argument: IDENTIFIER
| CONST_VALUE
| math_expr
| function_call;

/*If statment*/
/*define an unambiguous if statement*/
if_statement: IF LEFT_PAREN condtional_expr RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE
| IF LEFT_PAREN condtional_expr RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE ELSE LEFT_BRACE program RIGHT_BRACE
| IF LEFT_PAREN condtional_expr RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE elseif_expr;

/*elseif statement*/
elseif_expr: ELSEIF LEFT_PAREN condtional_expr RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE
| ELSEIF LEFT_PAREN condtional_expr RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE ELSE LEFT_BRACE program RIGHT_BRACE
| ELSEIF LEFT_PAREN condtional_expr RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE elseif_expr;

/*While statement*/
while_statement: WHILE LEFT_PAREN condtional_expr RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE;

do_statement: DO LEFT_BRACE program RIGHT_BRACE WHILE LEFT_PAREN condtional_expr RIGHT_PAREN SEMICOLON;

condtional_expr: math_expr
| IDENTIFIER
| function_call
| CONST_VALUE;

/*Switch statement*/
switch_statement: SWITCH LEFT_PAREN IDENTIFIER RIGHT_PAREN LEFT_BRACE switch_case_list RIGHT_BRACE;
switch_case_list: switch_case_list switch_case
| switch_case;
switch_case: CASE CONST_VALUE COLON program
| DEFAULT COLON program ;

/*Break statement*/
break_statement: BREAK SEMICOLON;

/*Continue statement*/ 
continue_statement: CONTINUE SEMICOLON;

/*Return statement*/
return_statement: RETURN SEMICOLON
| RETURN condtional_expr SEMICOLON;

/*For statement*/
for_statement: FOR LEFT_PAREN for_init_expr SEMICOLON condtional_expr SEMICOLON for_loop_do RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE;
for_loop_do: for_loop_do COMMA for_loop_do
| for_loop_do
| condtional_expr;

/*we will not allow function calls */
for_init_expr: variable_declaration
| variable_assignment;

/*Math expression*/
math_expr: math_expr OR math_expr
| math_expr AND math_expr
| NOT math_expr
| math_expr EQUAL math_expr
| math_expr NOTEQUAL math_expr
| math_expr GREATER_THAN math_expr
| math_expr GREATER_THAN_EQUAL math_expr
| math_expr LESS_THAN math_expr
| math_expr LESS_THAN_EQUAL math_expr
| math_expr PLUS math_expr
| math_expr MINUS math_expr
| math_expr TIMES math_expr
| math_expr DIVIDE math_expr
| math_expr MODULUS math_expr
| math_expr EXPONENT math_expr
| math_expr
| IDENTIFIER
| CONST_VALUE
| function_call
| LEFT_PAREN math_expr RIGHT_PAREN

%%




%union{
char *stringValue;
char characterValue; 
int integerValue;
float floatValue;
}

