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
int main(int argc, char** argv)
{
    //get the file name from the command line
    if (argc != 2)
    {
        cout << "Usage: ./compiler <filename>" << endl;
        return 1;
    }
    //open the file
    yyin = fopen(argv[1], "r");
    int result = yyparse();
    if (result == 0)
    {
        cout << "Parsing successful" << endl;
        cout << "Compiling..." << endl;
        Result r = programptr->compile(compile_context);

        //output to file if no error
        if (!r.isError())
        {
            ofstream outfile;
            outfile.open(argv[1]);
            outfile << "Quadruples:" << endl;
            std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
            std::cout.rdbuf(outfile.rdbuf()); //redirect std::cout to out.txt!
            programptr->printQuadruple();
            outfile << "--------------------------------------------------"<<endl;
            outfile << "Symbol table:" << endl;
            compile_context.tablesStack.top()->print();
            outfile.close();
            std::cout.rdbuf(coutbuf); //reset to standard output again
            cout << "Compile successful" << endl;
            cout << "Compiled successfully" << endl;
            cout << "--------------------------------------------------"<<endl;
            cout << "Quadruples:" << endl;
            programptr->printQuadruple();
            cout << "--------------------------------------------------"<<endl;
            cout << "Symbol table:" << endl;
            compile_context.tablesStack.top()->print();
        }
        else 
        {
            ofstream outfile;
            outfile.open(argv[1]);
            std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
            std::cout.rdbuf(outfile.rdbuf()); //redirect std::cout to out.txt!
            cout << "Compile failed" << endl;
            r.printError();
            outfile.close();
            std::cout.rdbuf(coutbuf); //reset to standard output again
            cout << "Compile failed" << endl;
            r.printError();
        }
    }
    else
    {   
        ofstream outfile;
        outfile.open(argv[1]);
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(outfile.rdbuf()); //redirect std::cout to out.txt!
        cout << "Parsing failed" << endl;
        std::cout.rdbuf(coutbuf); //reset to standard output again
        cout << "Parsing failed" << endl;
    }
}