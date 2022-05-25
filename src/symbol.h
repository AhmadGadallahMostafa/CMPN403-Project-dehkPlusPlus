#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct symbol
{
    string name;
    string symbolType;
    string value;
    int line;
    int column;
};

//struct variable that inherits from symbol
struct variable : public symbol
{
    bool isInitialized = false;
    string type;
    bool isConst;
};


class SymbolTable
{
private:
    unordered_map<string, symbol*> table; // string is the identifier and symbot contains the information
    SymbolTable* parent;
public:
    SymbolTable(SymbolTable* parent);
    void addSymbol(symbol* s);
    symbol* getSymbol(string name);
    void print();
};

