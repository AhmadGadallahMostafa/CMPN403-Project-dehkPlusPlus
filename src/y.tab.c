
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 5 "parser.y"

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


/* Line 189 of yacc.c  */
#line 89 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 1 "parser.y"

    #include "symbol.h"
#include "statments.h"



/* Line 209 of yacc.c  */
#line 120 "y.tab.c"

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

/* Line 214 of yacc.c  */
#line 55 "parser.y"

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



/* Line 214 of yacc.c  */
#line 261 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 273 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   617

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  223

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    43,    47,    53,    55,    57,    59,    61,    63,    65,
      72,    74,    76,    78,    80,    82,    87,    95,   104,   108,
     110,   111,   114,   119,   125,   130,   132,   133,   137,   139,
     141,   146,   154,   166,   175,   183,   195,   204,   212,   222,
     224,   226,   234,   237,   239,   246,   252,   254,   256,   258,
     260,   263,   266,   269,   273,   285,   289,   291,   293,   297,
     298,   301,   306,   310,   312,   313,   317,   321,   324,   328,
     332,   336,   340,   344,   348,   352,   356,   360,   364,   368,
     372,   376,   378
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    55,    57,    -1,    -1,    49,    55,    50,
      -1,    58,    -1,    64,    -1,    61,    -1,    63,    -1,    59,
      -1,    67,    -1,    72,    -1,    75,    -1,    74,    -1,    77,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    56,
      -1,    29,    -1,    62,    30,    52,    -1,    62,    30,    31,
      76,    52,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    -1,    20,    62,    30,    31,    76,
      52,    -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,
       7,    -1,    30,    31,    76,    52,    -1,    22,    62,    30,
      47,    65,    48,    56,    -1,    22,     8,    30,    47,    65,
      48,    56,    52,    -1,    65,    51,    66,    -1,    66,    -1,
      -1,    62,    30,    -1,    62,    30,    31,    76,    -1,    30,
      47,    69,    48,    52,    -1,    30,    47,    69,    48,    -1,
      70,    -1,    -1,    70,    51,    71,    -1,    71,    -1,    76,
      -1,    19,    30,    31,    76,    -1,    14,    47,    76,    48,
      49,    55,    50,    -1,    14,    47,    76,    48,    49,    55,
      50,    15,    49,    55,    50,    -1,    14,    47,    76,    48,
      49,    55,    50,    73,    -1,    16,    47,    76,    48,    49,
      55,    50,    -1,    16,    47,    76,    48,    49,    55,    50,
      15,    49,    55,    50,    -1,    16,    47,    76,    48,    49,
      55,    50,    73,    -1,    10,    47,    76,    48,    49,    55,
      50,    -1,    11,    49,    55,    50,    10,    47,    76,    48,
      52,    -1,    88,    -1,    68,    -1,    17,    47,    30,    48,
      49,    78,    50,    -1,    78,    79,    -1,    79,    -1,    18,
      80,    53,    49,    55,    50,    -1,    19,    53,    49,    55,
      50,    -1,    23,    -1,    26,    -1,    27,    -1,    28,    -1,
      12,    52,    -1,    13,    52,    -1,    21,    52,    -1,    21,
      76,    52,    -1,     9,    47,    87,    52,    76,    52,    85,
      48,    49,    55,    50,    -1,    86,    51,    86,    -1,    86,
      -1,    76,    -1,    30,    31,    76,    -1,    -1,    62,    30,
      -1,    62,    30,    31,    76,    -1,    30,    31,    76,    -1,
      76,    -1,    -1,    88,    39,    88,    -1,    88,    38,    88,
      -1,    40,    88,    -1,    88,    41,    88,    -1,    88,    42,
      88,    -1,    88,    43,    88,    -1,    88,    44,    88,    -1,
      88,    45,    88,    -1,    88,    46,    88,    -1,    88,    32,
      88,    -1,    88,    33,    88,    -1,    88,    34,    88,    -1,
      88,    35,    88,    -1,    88,    36,    88,    -1,    88,    37,
      88,    -1,    47,    88,    48,    -1,    30,    -1,    60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    81,    97,   103,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   124,   129,   135,   135,   135,   135,   135,   135,   137,
     139,   139,   139,   139,   139,   141,   145,   150,   153,   157,
     159,   162,   164,   167,   169,   171,   172,   174,   175,   177,
     178,   182,   183,   184,   187,   188,   189,   192,   194,   197,
     198,   202,   203,   204,   205,   206,   208,   208,   208,   208,
     211,   214,   217,   218,   221,   222,   223,   225,   226,   227,
     229,   230,   231,   232,   233,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING", "CHAR", "BOOL",
  "VOID", "FOR", "WHILE", "DO", "BREAK", "CONTINUE", "IF", "ELSE",
  "ELSEIF", "SWITCH", "CASE", "DEFAULT", "CONSTANT", "RETURN", "DEF",
  "INT_VALUE", "FLOAT_VALUE", "STRING_VALUE", "CHAR_VALUE",
  "BOOL_VALUE_TRUE", "BOOL_VALUE_FALSE", "COMMENT", "IDENTIFIER", "ASSIGN",
  "PLUS", "MINUS", "TIMES", "DIVIDE", "MODULUS", "EXPONENT", "AND", "OR",
  "NOT", "EQUAL", "NOTEQUAL", "GREATER_THAN", "GREATER_THAN_EQUAL",
  "LESS_THAN", "LESS_THAN_EQUAL", "LEFT_PAREN", "RIGHT_PAREN",
  "LEFT_BRACE", "RIGHT_BRACE", "COMMA", "SEMICOLON", "COLON", "$accept",
  "program", "block", "statement", "expr", "variable_declaration",
  "CONST_VALUE", "const_variable_declaration", "variable_type",
  "variable_assignment", "function_declaration", "parameter_list",
  "parameter", "function_call", "function_call_in_expr", "args_list",
  "argument_list", "argument", "if_statement", "elseif_expr",
  "while_statement", "do_statement", "condtional_expr", "switch_statement",
  "switch_case_list", "switch_case", "switch_case_value",
  "break_statement", "continue_statement", "return_statement",
  "for_statement", "for_loop_do", "final_expr", "for_init_expr",
  "math_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    61,
      62,    62,    62,    62,    62,    63,    64,    64,    65,    65,
      65,    66,    66,    67,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    72,    73,    73,    73,    74,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      81,    82,    83,    83,    84,    85,    85,    86,    86,    86,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     1,     1,     1,     1,     1,     1,     6,
       1,     1,     1,     1,     1,     4,     7,     8,     3,     1,
       0,     2,     4,     5,     4,     1,     0,     3,     1,     1,
       4,     7,    11,     8,     7,    11,     8,     7,     9,     1,
       1,     7,     2,     1,     6,     5,     1,     1,     1,     1,
       2,     2,     2,     3,    11,     3,     1,     1,     3,     0,
       2,     4,     3,     1,     0,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    30,    31,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
       3,    19,     2,     5,     9,     7,     0,     8,     6,    10,
      11,    13,    12,    14,    15,    16,    17,    18,    84,     0,
       3,    70,    71,     0,     0,     0,    23,    24,    25,    26,
      27,    28,   101,     0,     0,    72,   102,    60,     0,    59,
       0,     0,     0,    46,     0,     0,   101,     0,    83,     0,
       0,     0,     0,     0,     0,    46,   101,    87,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
      48,    49,     4,     0,    21,     0,    80,     0,     0,     0,
       0,     0,     0,     0,   100,    94,    95,    96,    97,    98,
      99,    86,    85,    88,    89,    90,    91,    92,    93,    40,
      40,    35,     0,     0,     0,     0,    82,     0,     0,     3,
       0,     3,     0,     0,    44,     0,     0,    39,     0,     0,
      43,    47,    22,    81,    79,     0,     0,     0,     0,     0,
       0,    63,    29,    41,     0,     0,     0,    50,   101,    77,
       0,    76,    57,     0,    51,    66,    67,    68,    69,     0,
       0,    61,    62,     0,     0,    38,    36,     0,     0,    79,
       0,     0,     0,    53,     0,     3,    42,    37,    78,     3,
      75,    58,     3,     0,     3,     0,     0,     0,     0,     0,
      65,    74,    52,     0,    64,     3,     0,    54,     0,    56,
       3,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    21,    22,    23,    24,    56,    25,    26,    27,
      28,   146,   147,    29,    57,    98,    99,   100,    30,   193,
      31,    32,   101,    33,   160,   161,   179,    34,    35,    36,
      37,   170,   171,    69,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -96
static const yytype_int16 yypact[] =
{
     -96,    29,   -96,   -96,   -96,   -96,   -96,   -96,   -16,   -10,
     -22,   -31,    39,    46,    51,     4,    78,   106,   -96,   -28,
     -96,   -96,   -96,   -96,   -96,   -96,    69,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,    49,    40,
     -96,   -96,   -96,    40,    77,    85,   -96,   -96,   -96,   -96,
     -96,   -96,    53,   485,   485,   -96,   -96,   -96,    68,   526,
      93,    94,    40,   166,   198,   -26,   -25,    98,   -96,    80,
      81,   229,    83,    87,   102,   166,   -96,   556,   509,   -96,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,    89,    90,    86,   118,    92,    99,
     -96,   -96,   -96,    40,   -96,    40,   120,    40,   100,   157,
     121,   122,    40,   125,   -96,   -19,   -19,   132,   132,   132,
     132,   556,   541,   571,   571,   110,   110,   110,   110,     4,
       4,   -96,   145,   126,   166,   128,   -96,    40,   129,   -96,
     130,   -96,    64,   131,   -96,   156,    -3,   -96,    33,    40,
     -96,   -96,   -96,   -96,   493,   260,    40,   291,    34,   134,
      -6,   -96,   -96,   167,   148,     4,   148,   -96,   -17,   -96,
     151,   163,   -96,   168,    70,   -96,   -96,   -96,   -96,   164,
     172,   -96,   -96,    40,   170,   -96,   -96,    40,   174,   493,
     173,   175,   179,   -96,   180,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,    40,   -96,   322,   353,   384,   182,   415,
     -96,   -96,   -96,   188,   -96,   -96,   446,    79,   195,   -96,
     -96,   477,   -96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   -20,   -95,   -96,   -96,   -96,   -96,   -96,   -13,   -96,
     -96,   101,    88,   -96,   -96,   177,   -96,   111,   -96,    37,
     -96,   -96,   -15,   -96,   -96,    95,   -96,   -96,   -96,   -96,
     -96,   -96,    67,   -96,    73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      64,    58,    45,    62,    61,   103,   105,     3,     4,     5,
       6,     7,   158,   159,   187,    82,    83,    84,    85,    63,
      71,    41,    75,    68,    70,    67,   104,    40,    72,     2,
      75,    38,     3,     4,     5,     6,     7,    39,     8,     9,
      10,    11,    12,    13,   181,   164,    14,    96,   165,    15,
      16,    17,     3,     4,     5,     6,     7,   175,    18,    19,
     176,   177,   178,    46,    47,    48,    49,    50,    51,   184,
      52,   186,    46,    47,    48,    49,    50,    51,    20,    66,
      53,   166,   158,   159,   165,   191,   192,    54,   135,    53,
     136,    42,   138,    43,   218,   192,    54,   143,    44,    65,
      75,    46,    47,    48,    49,    50,    51,    73,    52,     3,
       4,     5,     6,     7,    60,    74,   145,   145,    53,   155,
      79,   157,   153,    94,    95,    54,    77,    78,   106,   108,
      55,   110,   107,   112,   167,   111,   129,   130,   131,   169,
     133,   173,    80,    81,    82,    83,    84,    85,   132,   139,
     134,   137,   145,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   140,   196,    85,
     141,   142,   198,   144,   169,   205,   149,   156,   150,   206,
     152,   154,   207,   162,   209,    97,   163,   180,   208,    46,
      47,    48,    49,    50,    51,   216,    52,    20,   183,   188,
     221,     3,     4,     5,     6,     7,    53,     8,     9,    10,
      11,    12,    13,    54,   189,    14,   190,   194,    15,    16,
      17,   195,   197,   199,   202,   201,   203,    18,    19,   204,
     213,   148,     3,     4,     5,     6,     7,   215,     8,     9,
      10,    11,    12,    13,   220,   151,    14,    20,   102,    15,
      16,    17,   113,   185,   219,   182,   200,     0,    18,    19,
       0,     0,     0,     3,     4,     5,     6,     7,     0,     8,
       9,    10,    11,    12,    13,     0,     0,    14,    20,   109,
      15,    16,    17,     0,     0,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     3,     4,     5,     6,     7,     0,
       8,     9,    10,    11,    12,    13,     0,     0,    14,    20,
     172,    15,    16,    17,     0,     0,     0,     0,     0,     0,
      18,    19,     0,     0,     0,     3,     4,     5,     6,     7,
       0,     8,     9,    10,    11,    12,    13,     0,     0,    14,
      20,   174,    15,    16,    17,     0,     0,     0,     0,     0,
       0,    18,    19,     0,     0,     0,     3,     4,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    20,   210,    15,    16,    17,     0,     0,     0,     0,
       0,     0,    18,    19,     0,     0,     0,     3,     4,     5,
       6,     7,     0,     8,     9,    10,    11,    12,    13,     0,
       0,    14,    20,   211,    15,    16,    17,     0,     0,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     3,     4,
       5,     6,     7,     0,     8,     9,    10,    11,    12,    13,
       0,     0,    14,    20,   212,    15,    16,    17,     0,     0,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     3,
       4,     5,     6,     7,     0,     8,     9,    10,    11,    12,
      13,     0,     0,    14,    20,   214,    15,    16,    17,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       3,     4,     5,     6,     7,     0,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    20,   217,    15,    16,    17,
       0,     0,     0,     0,     0,     0,    18,    19,    46,    47,
      48,    49,    50,    51,     0,    76,    46,    47,    48,    49,
      50,    51,     0,   168,     0,    53,    20,   222,     0,     0,
       0,     0,    54,    53,     0,     0,     0,     0,     0,     0,
      54,    80,    81,    82,    83,    84,    85,    86,    87,     0,
      88,    89,    90,    91,    92,    93,     0,   114,    80,    81,
      82,    83,    84,    85,    86,    87,     0,    88,    89,    90,
      91,    92,    93,    80,    81,    82,    83,    84,    85,    86,
       0,     0,    88,    89,    90,    91,    92,    93,    80,    81,
      82,    83,    84,    85,     0,     0,     0,    88,    89,    90,
      91,    92,    93,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    90,    91,    92,    93
};

static const yytype_int16 yycheck[] =
{
      20,    16,    15,    31,    17,    31,    31,     3,     4,     5,
       6,     7,    18,    19,    31,    34,    35,    36,    37,    47,
      40,    52,    47,    38,    39,    38,    52,    49,    43,     0,
      47,    47,     3,     4,     5,     6,     7,    47,     9,    10,
      11,    12,    13,    14,    50,    48,    17,    62,    51,    20,
      21,    22,     3,     4,     5,     6,     7,    23,    29,    30,
      26,    27,    28,    23,    24,    25,    26,    27,    28,   164,
      30,   166,    23,    24,    25,    26,    27,    28,    49,    30,
      40,    48,    18,    19,    51,    15,    16,    47,   103,    40,
     105,    52,   107,    47,    15,    16,    47,   112,    47,    30,
      47,    23,    24,    25,    26,    27,    28,    30,    30,     3,
       4,     5,     6,     7,     8,    30,   129,   130,    40,   139,
      52,   141,   137,    30,    30,    47,    53,    54,    30,    48,
      52,    48,    52,    31,   149,    48,    47,    47,    52,   154,
      48,   156,    32,    33,    34,    35,    36,    37,    30,    49,
      51,    31,   165,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    10,   183,    37,
      49,    49,   187,    48,   189,   195,    31,    47,    52,   199,
      52,    52,   202,    52,   204,    19,    30,    53,   203,    23,
      24,    25,    26,    27,    28,   215,    30,    49,    31,    48,
     220,     3,     4,     5,     6,     7,    40,     9,    10,    11,
      12,    13,    14,    47,    51,    17,    48,    53,    20,    21,
      22,    49,    52,    49,    49,    52,    47,    29,    30,    49,
      48,   130,     3,     4,     5,     6,     7,    49,     9,    10,
      11,    12,    13,    14,    49,   134,    17,    49,    50,    20,
      21,    22,    75,   165,   217,   160,   189,    -1,    29,    30,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    -1,    -1,    17,    49,    50,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    -1,    -1,    17,    49,
      50,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      49,    50,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    -1,    -1,
      17,    49,    50,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    -1,
      -1,    17,    49,    50,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      -1,    -1,    17,    49,    50,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    -1,    -1,    17,    49,    50,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    -1,    -1,    17,    49,    50,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    23,    24,
      25,    26,    27,    28,    -1,    30,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    40,    49,    50,    -1,    -1,
      -1,    -1,    47,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    -1,    48,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    43,    44,    45,    46,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,     0,     3,     4,     5,     6,     7,     9,    10,
      11,    12,    13,    14,    17,    20,    21,    22,    29,    30,
      49,    56,    57,    58,    59,    61,    62,    63,    64,    67,
      72,    74,    75,    77,    81,    82,    83,    84,    47,    47,
      49,    52,    52,    47,    47,    62,    23,    24,    25,    26,
      27,    28,    30,    40,    47,    52,    60,    68,    76,    88,
       8,    62,    31,    47,    55,    30,    30,    62,    76,    87,
      76,    55,    76,    30,    30,    47,    30,    88,    88,    52,
      32,    33,    34,    35,    36,    37,    38,    39,    41,    42,
      43,    44,    45,    46,    30,    30,    76,    19,    69,    70,
      71,    76,    50,    31,    52,    31,    30,    52,    48,    50,
      48,    48,    31,    69,    48,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    47,
      47,    52,    30,    48,    51,    76,    76,    31,    76,    49,
      10,    49,    49,    76,    48,    62,    65,    66,    65,    31,
      52,    71,    52,    76,    52,    55,    47,    55,    18,    19,
      78,    79,    52,    30,    48,    51,    48,    76,    30,    76,
      85,    86,    50,    76,    50,    23,    26,    27,    28,    80,
      53,    50,    79,    31,    56,    66,    56,    31,    48,    51,
      48,    15,    16,    73,    53,    49,    76,    52,    76,    49,
      86,    52,    49,    47,    49,    55,    55,    55,    76,    55,
      50,    50,    50,    48,    50,    49,    55,    50,    15,    73,
      49,    55,    50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    {
  (yyvsp[(1) - (2)].programptr_val)->appendStatement((yyvsp[(2) - (2)].statement_val));
}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {
  (yyval.programptr_val) = new ProgramNode();
  if (programptr == nullptr)
  {
    programptr = (yyval.programptr_val);
    programptr -> is_main = true;
  }
}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {
  (yyval.block_node_val) = new BlockStatement((yyvsp[(2) - (3)].programptr_val));
}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    { 
    (yyval.declare_variableStatement_val) = new DeclareVariableStatement((yyvsp[(1) - (3)].stringValue),(yyvsp[(2) - (3)].stringValue), nullptr);
    printf("Found var declaration \n");
}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {
    (yyval.declare_variableStatement_val) = new DeclareVariableStatement((yyvsp[(1) - (5)].stringValue),(yyvsp[(2) - (5)].stringValue), (yyvsp[(4) - (5)].conditional_expr_statement_val));
    printf("Found var declaration with assing\n");
}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {
    (yyval.declare_functionStatement_val) = new DeclareFunctionStatement((yyvsp[(2) - (7)].stringValue),(yyvsp[(3) - (7)].stringValue),(yyvsp[(5) - (7)].parameter_list_val),(yyvsp[(7) - (7)].block_node_val));
    printf("Found function declaration \n");
  }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {
    (yyval.parameter_list_val)->appendParameter((yyvsp[(3) - (3)].parameter_val));
  }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyval.parameter_list_val) = new ParameterList();(yyval.parameter_list_val)->appendParameter((yyvsp[(1) - (1)].parameter_val));}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {(yyval.parameter_val) = new parameter((yyvsp[(1) - (2)].stringValue),(yyvsp[(2) - (2)].stringValue));
  printf("Found parameter\n");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {(yyval.conditional_expr_statement_val) = (yyvsp[(1) - (1)].math_expr_statement_val);}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    {(yyval.math_expr_statement_val) = new MathExprStatement((yyvsp[(2) - (3)].stringValue),(yyvsp[(1) - (3)].math_expr_statement_val),(yyvsp[(3) - (3)].math_expr_statement_val),false,"");}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    {(yyval.math_expr_statement_val)=new MathExprStatement("",nullptr,nullptr,true,(yyvsp[(1) - (1)].stringValue));printf("assigntment\n");}
    break;



/* Line 1455 of yacc.c  */
#line 1855 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 256 "parser.y"

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


