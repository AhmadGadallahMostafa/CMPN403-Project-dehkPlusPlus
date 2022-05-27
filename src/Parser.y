%code requires{
    #include "symbol.h"
#include "statments.h"
}
%{
#include <stdlib.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "symbol.h"
#include "statments.h"
void yyerror(char *s);
int yylex(void);


ProgramNode* programptr = nullptr;
%}

%token <stringValue>INT FLOAT STRING CHAR BOOL VOID
%token FOR WHILE DO BREAK CONTINUE IF ELSE ELSEIF SWITCH CASE DEFAULT CONSTANT RETURN DEF
%token INT_VALUE FLOAT_VALUE STRING_VALUE CHAR_VALUE BOOL_VALUE_TRUE BOOL_VALUE_FALSE COMMENT
%token <stringValue>IDENTIFIER
%token ASSIGN <stringValue>PLUS MINUS TIMES DIVIDE MODULUS EXPONENT
%token AND OR NOT
%token EQUAL NOTEQUAL GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL
%token LEFT_PAREN RIGHT_PAREN LEFT_BRACE RIGHT_BRACE COMMA SEMICOLON COLON

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

%start program
%type <programptr_val> program
%type <statement_val> statement
%type <declare_variableStatement_val> variable_declaration
%type <stringValue> variable_type
%type <parameter_val> parameter
%type <parameter_list_val> parameter_list
%type <declare_functionStatement_val> function_declaration
%type <block_node_val> block
%type <conditional_expr_statement_val> condtional_expr
%type <math_expr_statement_val> math_expr



%union{
    char *stringValue;
    char charValue; 
    int integerValue;
    float floatValue;
    ProgramNode* programptr_val;
    Statement* statement_val;
    DeclareVariableStatement* declare_variableStatement_val;
    parameter* parameter_val;
    ParameterList* parameter_list_val;
    DeclareFunctionStatement* declare_functionStatement_val;
    BlockStatement* block_node_val;
    ConditionalExprStatement* conditional_expr_statement_val;
    MathExprStatement* math_expr_statement_val;
}

 /*Defining the grammar */

%%
program : 

program statement           
{
  $1->appendStatement($2);
}
|
{
  $$ = new ProgramNode();
  if (programptr == nullptr)
  {
    programptr = $$;
    programptr -> is_main = true;
  }
}
/* |
statement
{
  printf("stmt\n");
} */
;

block:
LEFT_BRACE program RIGHT_BRACE
{
  $$ = new BlockStatement($2);
}
;

statement: expr;

expr: 
  function_declaration
| const_variable_declaration
| variable_assignment
| variable_declaration //$$ 
| function_call
| if_statement
| do_statement
| while_statement
| switch_statement
| break_statement
| continue_statement
| return_statement
| for_statement
| block
| COMMENT

 /*Variable declerations*/
variable_declaration:
variable_type IDENTIFIER SEMICOLON     
{ 
    $$ = new DeclareVariableStatement($1,$2, nullptr);
    printf("Found var declaration \n");
}
| variable_type IDENTIFIER ASSIGN condtional_expr SEMICOLON
{
    $$ = new DeclareVariableStatement($1,$2, $4);
    printf("Found var declaration with assing\n");
};

CONST_VALUE: INT_VALUE | FLOAT_VALUE | STRING_VALUE | CHAR_VALUE | BOOL_VALUE_TRUE | BOOL_VALUE_FALSE;

const_variable_declaration: CONSTANT variable_type IDENTIFIER ASSIGN condtional_expr SEMICOLON;

variable_type: INT | FLOAT | STRING | CHAR | BOOL;

variable_assignment: IDENTIFIER ASSIGN condtional_expr SEMICOLON;

 /*Function declarations */
function_declaration:
  DEF variable_type IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN block
  {
    $$ = new DeclareFunctionStatement($2,$3,$5,$7);
    printf("Found function declaration \n");
  }
| DEF VOID IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN block SEMICOLON;

parameter_list: 
  parameter_list COMMA parameter 
  {
    $$->appendParameter($3);
  }
| parameter                       {$$ = new ParameterList();$$->appendParameter($1);}
  
| ;

parameter: 
  variable_type IDENTIFIER                              {$$ = new parameter($1,$2);
  printf("Found parameter\n");}
| variable_type IDENTIFIER ASSIGN condtional_expr;

/*Function call*/
function_call: IDENTIFIER LEFT_PAREN args_list RIGHT_PAREN SEMICOLON;

function_call_in_expr: IDENTIFIER LEFT_PAREN args_list RIGHT_PAREN;

args_list: argument_list
| ;

argument_list: argument_list COMMA argument
| argument;

argument: condtional_expr
|DEFAULT IDENTIFIER ASSIGN condtional_expr;

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

condtional_expr: 
  math_expr               {$$ = $1;}
| function_call_in_expr
;

/*Switch statement*/
switch_statement: SWITCH LEFT_PAREN IDENTIFIER RIGHT_PAREN LEFT_BRACE switch_case_list RIGHT_BRACE;
switch_case_list: switch_case_list switch_case
| switch_case;
switch_case: CASE switch_case_value COLON LEFT_BRACE program RIGHT_BRACE
| DEFAULT COLON LEFT_BRACE program RIGHT_BRACE;

switch_case_value: INT_VALUE | CHAR_VALUE | BOOL_VALUE_TRUE | BOOL_VALUE_FALSE;

/*Break statement*/
break_statement: BREAK SEMICOLON;

/*Continue statement*/ 
continue_statement: CONTINUE SEMICOLON;

/*Return statement*/
return_statement: RETURN SEMICOLON
| RETURN condtional_expr SEMICOLON;

/*For statement*/
for_statement: FOR LEFT_PAREN for_init_expr SEMICOLON condtional_expr SEMICOLON for_loop_do RIGHT_PAREN LEFT_BRACE program RIGHT_BRACE;
for_loop_do: final_expr COMMA final_expr
| final_expr

final_expr: condtional_expr 
|IDENTIFIER ASSIGN condtional_expr
|;

for_init_expr: variable_type IDENTIFIER 
| variable_type IDENTIFIER ASSIGN condtional_expr
| IDENTIFIER ASSIGN condtional_expr
| condtional_expr
| ;

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
| math_expr PLUS math_expr                {$$ = new MathExprStatement($2,$1,$3,false,"");}
| math_expr MINUS math_expr
| math_expr TIMES math_expr
| math_expr DIVIDE math_expr
| math_expr MODULUS math_expr
| math_expr EXPONENT math_expr
| LEFT_PAREN math_expr RIGHT_PAREN
| IDENTIFIER                                {$$=new MathExprStatement("",nullptr,nullptr,true,$1);printf("assigntment\n");}
| CONST_VALUE
;

%%
void yyerror (char* s)
{
    printf("%s\n", s);
}

/* int yyerror (char* s)
{
return yyerror(string(s));
} */
/* int main (void)
{

    yyin = fopen("test.txt", "r");
    if (yyin == NULL)
    {
        printf("File not found\n");
        return 1;
    }
    else
    {
        printf(">>> Test.txt ...\n\n");
        FILE *testFile;
        char ch;
        testFile= fopen("test.txt", "r");
        while ((ch = fgetc(testFile)) != EOF)
        {
            printf("%c", ch);
        }
        yyparse();
    }
    fclose(yyin);
    return 0;
} */

