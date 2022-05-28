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
%token <stringValue>INT_VALUE FLOAT_VALUE STRING_VALUE CHAR_VALUE BOOL_VALUE_TRUE BOOL_VALUE_FALSE COMMENT
%token <stringValue>IDENTIFIER
%token <stringValue>ASSIGN PLUS MINUS TIMES DIVIDE MODULUS EXPONENT
%token  <stringValue>AND OR NOT
%token  <stringValue>EQUAL NOTEQUAL GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL
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
%type <declare_variableStatement_val> const_variable_declaration
%type <stringValue> variable_type
%type <parameter_val> parameter
%type <parameter_list_val> parameter_list
%type <declare_functionStatement_val> function_declaration
%type <block_node_val> block
%type <conditional_expr_statement_val> condtional_expr
%type <math_expr_statement_val> math_expr
%type <literal_val> CONST_VALUE
%type <declare_ifStatement_val> if_statement
%type <declare_ifStatement_val> elseif_expr
%type <declare_assignStatement_val> variable_assignment
%type <declare_whileStatement_val> while_statement
%type <declare_doWhileStatement_val> do_statement
%type <switch_case_val> switch_case
%type <switch_case_list_val> switch_case_list
%type <literal_val> switch_case_value
%type <declare_switchStatement_val> switch_statement
%type <for_init_expr_val> for_init_expr
%type <for_final_expr_val> final_expr
%type <for_loop_do_val>for_loop_do
%type <declare_forStatement_val> for_statement

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
    LiteralVal* literal_val;
    DeclareIfStatement* declare_ifStatement_val;
    MathExpression* math_expr_val;
    operatorSymbol* operator_val;
    DeclareAssignStatement* declare_assignStatement_val;
    DeclareWhileStatement* declare_whileStatement_val;
    DeclareDoWhileStatement* declare_doWhileStatement_val;
    SwitchCase* switch_case_val;
    SwitchCaseList* switch_case_list_val;
    DeclareSwitchStatement* declare_switchStatement_val;
    ForInitExpression* for_init_expr_val;
    ForFinalExpression* for_final_expr_val;
    ForLoopDo* for_loop_do_val;
    DeclareForStatement* declare_forStatement_val;
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
    $$ = new DeclareVariableStatement($1,$2, nullptr, false);
}
| variable_type IDENTIFIER ASSIGN condtional_expr SEMICOLON
{
    $$ = new DeclareVariableStatement($1,$2, $4, false);
};

CONST_VALUE: INT_VALUE  {$$ = new LiteralVal("int", $1);}
| FLOAT_VALUE           {$$ = new LiteralVal("float", $1);}
| STRING_VALUE          {$$ = new LiteralVal("string", $1);}
| CHAR_VALUE            {$$ = new LiteralVal("char", $1);}
| BOOL_VALUE_TRUE       {$$ = new LiteralVal("bool", $1);}
| BOOL_VALUE_FALSE      {$$ = new LiteralVal("bool", $1);}
; 

const_variable_declaration: CONSTANT variable_type IDENTIFIER ASSIGN condtional_expr SEMICOLON  {$$ = new DeclareVariableStatement($2,$3, $5, true);};

variable_type: INT | FLOAT | STRING | CHAR | BOOL;

variable_assignment: 
IDENTIFIER ASSIGN condtional_expr SEMICOLON
{
    $$ = new DeclareAssignStatement($1, $3);
}
;
 /*Function declarations */
function_declaration:
  DEF variable_type IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN block
  {
    $$ = new DeclareFunctionStatement($2,$3,$5,$7);
  }
| DEF VOID IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN block 
{
    $$ = new DeclareFunctionStatement("void",$3,$5,$7);
}
;

parameter_list: 
  parameter_list COMMA parameter 
  {
    $$->appendParameter($3);
  }
| parameter                       {$$ = new ParameterList();$$->appendParameter($1);}
  
| ;

parameter: 
  variable_type IDENTIFIER                              {$$ = new parameter($1,$2,nullptr);}
| variable_type IDENTIFIER ASSIGN condtional_expr       {$$ = new parameter($1,$2,$4);}
;

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
if_statement: 
  IF LEFT_PAREN condtional_expr RIGHT_PAREN block   
  {
    $$ = new DeclareIfStatement($3,$5,nullptr,nullptr);
  }            
| IF LEFT_PAREN condtional_expr RIGHT_PAREN block ELSE block
  {
      $$ = new DeclareIfStatement($3,$5,$7,nullptr);
  }
| IF LEFT_PAREN condtional_expr RIGHT_PAREN block elseif_expr
  {
      $$ = new DeclareIfStatement($3,$5,nullptr,$6);
  }
;

/*elseif statement*/
elseif_expr: 
  ELSEIF LEFT_PAREN condtional_expr RIGHT_PAREN block
  {
    $$ = new DeclareIfStatement($3,$5,nullptr,nullptr);
  }
| ELSEIF LEFT_PAREN condtional_expr RIGHT_PAREN block ELSE block
  {
      $$ = new DeclareIfStatement($3,$5,$7,nullptr);
  }
| ELSEIF LEFT_PAREN condtional_expr RIGHT_PAREN block elseif_expr
  {
      $$ = new DeclareIfStatement($3,$5,nullptr,$6);
  }

/*While statement*/
while_statement: WHILE LEFT_PAREN condtional_expr RIGHT_PAREN block
  {
    $$ = new DeclareWhileStatement($3,$5);
  };
do_statement: DO block WHILE LEFT_PAREN condtional_expr RIGHT_PAREN SEMICOLON
{
    $$ = new DeclareDoWhileStatement($5,$2);
};


condtional_expr: 
  math_expr               {$$ = $1;}
| function_call_in_expr
;

/*Switch statement*/
switch_statement: SWITCH LEFT_PAREN IDENTIFIER RIGHT_PAREN LEFT_BRACE switch_case_list RIGHT_BRACE{$$ = new DeclareSwitchStatement($3,$6);};

switch_case_list: 
  switch_case_list switch_case       {$$->appendSwitchCase($2);}
| switch_case                        {$$ = new SwitchCaseList();$$->appendSwitchCase($1);}

switch_case: 
  CASE switch_case_value COLON block  {$$ = new SwitchCase($2,$4);}
| DEFAULT COLON block                 {$$ = new SwitchCase(nullptr,$3);}

switch_case_value: 
  INT_VALUE           {$$ = new LiteralVal("int", $1);}
| CHAR_VALUE          {$$ = new LiteralVal("char", $1);}
| BOOL_VALUE_TRUE     {$$ = new LiteralVal("bool", $1);}
| BOOL_VALUE_FALSE    {$$ = new LiteralVal("bool", $1);}

/*Break statement*/
break_statement: BREAK SEMICOLON;

/*Continue statement*/ 
continue_statement: CONTINUE SEMICOLON;

/*Return statement*/
return_statement: RETURN SEMICOLON
| RETURN condtional_expr SEMICOLON;

/*For statement*/
for_statement: FOR LEFT_PAREN for_init_expr SEMICOLON condtional_expr SEMICOLON for_loop_do RIGHT_PAREN block
{
  $$ = new DeclareForStatement($3,$7,$5,$9);
};

for_loop_do: 
  final_expr COMMA final_expr
  {
    $$->appendForFinalExpression($1);
    $$->appendForFinalExpression($3);
  }
| final_expr
{
  $$ = new ForLoopDo();
  $$->appendForFinalExpression($1);
};

final_expr: 
condtional_expr 
{
  $$ = new ForFinalExpression($1, "");
}
|IDENTIFIER ASSIGN condtional_expr
{
  $$ = new ForFinalExpression($3, $1);
}
|;

for_init_expr: 
  variable_type IDENTIFIER
  {
    $$ = new ForInitExpression($1, $2, nullptr);
  }
| variable_type IDENTIFIER ASSIGN condtional_expr
  {
    $$ = new ForInitExpression($1, $2, $4);
  }
| IDENTIFIER ASSIGN condtional_expr
  {
    $$ = new ForInitExpression(nullptr, $1, $3);
  }
| condtional_expr
  {
    $$ = new ForInitExpression(nullptr, nullptr, $1);
  }
| ;

/*Math expression*/
math_expr: 
  math_expr OR math_expr
{
operatorSymbol* op = new operatorSymbol($2);
$1->appendExpression($3, op);$$ = $1;
}
| math_expr AND math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| NOT math_expr
{
  operatorSymbol* op = new operatorSymbol($1);
  $$->appendExpression($2, op);
}
| math_expr EQUAL math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr NOTEQUAL math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr GREATER_THAN math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr GREATER_THAN_EQUAL math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr LESS_THAN math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr LESS_THAN_EQUAL math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr PLUS math_expr                
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr MINUS math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr TIMES math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  printf("%s\n", $2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr DIVIDE math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr MODULUS math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| math_expr EXPONENT math_expr
{
  operatorSymbol* op = new operatorSymbol($2);
  $1->appendExpression($3, op);$$ = $1;
}
| LEFT_PAREN math_expr RIGHT_PAREN
| IDENTIFIER                                
{
  MathExpression* expr = new MathExpression($1);
  $$ = new MathExprStatement(nullptr,expr);
}
| CONST_VALUE                               
{
  MathExpression* expr = new MathExpression($1);
  $$ = new MathExprStatement(nullptr,expr);
}
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

