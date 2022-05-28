#include "symbol.h"
#include "statments.h"
#include <fstream>
#include "Result.h"

using namespace std;
int yyparse();
extern "C" int yylex();
extern FILE* yyin;
extern ProgramNode* programptr;
compileContext compile_context = {nullptr, stack<SymbolTable*>()};
int main()
{

    yyin = fopen("test.txt", "r");
    int result = yyparse();
    if (result == 0)
    {
        cout << "Parsing successful" << endl;
        cout << "Compiling..." << endl;
        programptr->compile(compile_context).printError();

        int i = 0;
        for (auto t: compile_context.tables)
        {
            cout<<"table num" << i << endl;
            t->print();
            i++;
        }
    }
    else
    {
        cout << "Parsing failed" << endl;
    }
    // SymbolTable table1 = SymbolTable(nullptr);
    // symbol s1;
    // s1.name = "a";
    // s1.type = "int";
    // s1.value = "1";
    // s1.line = 1;
    // s1.column = 1;
    // table1.addSymbol(&s1);
    // symbol s2;
    // s2.name = "b";
    // s2.type = "int";
    // s2.value = "2";
    // s2.line = 1;
    // s2.column = 1;
    // table1.addSymbol(&s2);
    // SymbolTable table2 = SymbolTable(&table1);
    // symbol s3;
    // s3.name = "c";
    // s3.type = "int";
    // s3.value = "3";
    // s3.line = 1;
    // s3.column = 1;
    // table2.addSymbol(&s3);
    // symbol* s4 = table2.getSymbol("a");
    // symbol* s5 = table2.getSymbol("c");
    // symbol* s6 = table1.getSymbol("c");
    // cout << s4->name << " " << s4->type << " " << s4->value << endl;
    // cout << s5->name << " " << s5->type << " " << s5->value << endl;
    // if(s6 == nullptr)
    // {
    //     cout << "not found in scope" << endl;
    // }
    // else
    // {
    //     cout << s6->name << " " << s6->type << " " << s6->value << endl;
    // }
    // compileContext compile_context = {nullptr,stack<SymbolTable*>()};
    // ProgramNode program = ProgramNode(vector<Statement*>(),false);
    // program.appendStatement(new DeclareVariableStatement("int","a"));
    // program.compile(compile_context);
    // int x =5;
}