
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 1 "parser.y"

    #include "symbol.h"
#include "statments.h"



/* Line 1676 of yacc.c  */
#line 47 "y.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     STRING = 260,
     CHAR = 261,
     BOOL = 262,
     VOID = 263,
     FOR = 264,
     WHILE = 265,
     DO = 266,
     BREAK = 267,
     CONTINUE = 268,
     IF = 269,
     ELSE = 270,
     ELSEIF = 271,
     SWITCH = 272,
     CASE = 273,
     DEFAULT = 274,
     CONSTANT = 275,
     RETURN = 276,
     DEF = 277,
     INT_VALUE = 278,
     FLOAT_VALUE = 279,
     STRING_VALUE = 280,
     CHAR_VALUE = 281,
     BOOL_VALUE_TRUE = 282,
     BOOL_VALUE_FALSE = 283,
     COMMENT = 284,
     IDENTIFIER = 285,
     ASSIGN = 286,
     PLUS = 287,
     MINUS = 288,
     TIMES = 289,
     DIVIDE = 290,
     MODULUS = 291,
     EXPONENT = 292,
     AND = 293,
     OR = 294,
     NOT = 295,
     EQUAL = 296,
     NOTEQUAL = 297,
     GREATER_THAN = 298,
     GREATER_THAN_EQUAL = 299,
     LESS_THAN = 300,
     LESS_THAN_EQUAL = 301,
     LEFT_PAREN = 302,
     RIGHT_PAREN = 303,
     LEFT_BRACE = 304,
     RIGHT_BRACE = 305,
     COMMA = 306,
     SEMICOLON = 307,
     COLON = 308
   };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define STRING 260
#define CHAR 261
#define BOOL 262
#define VOID 263
#define FOR 264
#define WHILE 265
#define DO 266
#define BREAK 267
#define CONTINUE 268
#define IF 269
#define ELSE 270
#define ELSEIF 271
#define SWITCH 272
#define CASE 273
#define DEFAULT 274
#define CONSTANT 275
#define RETURN 276
#define DEF 277
#define INT_VALUE 278
#define FLOAT_VALUE 279
#define STRING_VALUE 280
#define CHAR_VALUE 281
#define BOOL_VALUE_TRUE 282
#define BOOL_VALUE_FALSE 283
#define COMMENT 284
#define IDENTIFIER 285
#define ASSIGN 286
#define PLUS 287
#define MINUS 288
#define TIMES 289
#define DIVIDE 290
#define MODULUS 291
#define EXPONENT 292
#define AND 293
#define OR 294
#define NOT 295
#define EQUAL 296
#define NOTEQUAL 297
#define GREATER_THAN 298
#define GREATER_THAN_EQUAL 299
#define LESS_THAN 300
#define LESS_THAN_EQUAL 301
#define LEFT_PAREN 302
#define RIGHT_PAREN 303
#define LEFT_BRACE 304
#define RIGHT_BRACE 305
#define COMMA 306
#define SEMICOLON 307
#define COLON 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 59 "parser.y"

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



/* Line 1676 of yacc.c  */
#line 190 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


