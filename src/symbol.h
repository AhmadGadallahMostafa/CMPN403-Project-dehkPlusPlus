#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "Result.h"
using namespace std;

struct LiteralVal
{
    string type;
    string value;
    inline LiteralVal(string type, string value)
    {
        this->type = type;
        this->value = value;
    }
};


struct symbol
{
    string name;
    string symbolType;
    int line;
    int column;
};

//struct variable that inherits from symbol
struct variable : public symbol
{
    bool isInitialized = false;
    string type;
    bool isConst;
    string value;
};

struct parameter : public symbol
{
    string type;
    parameter(string type, string name):symbol()
    {
        symbolType = "parameter";
        this->type = type;
        this->name = name;
    }
};

struct functionSymbol : symbol
{
    string returnType;
    vector<parameter*> parameters;
};


class SymbolTable
{
private:
    unordered_map<string, symbol*> table; // string is the identifier and symbot contains the information
    SymbolTable* parent;
public:
    SymbolTable(SymbolTable* parent);
    Result addSymbol(symbol* s);
    symbol* getSymbol(string name);
    void removeSymbol(string name);
    void print();
};

