#include "symbol.h"

SymbolTable::SymbolTable(SymbolTable* parent)
{
    this->parent = parent;
}



void SymbolTable::addSymbol(symbol* s)
{
    //check if the symbol already exists
    if (table.find(s->name) != table.end())
    {
        //if variable is already declared
        throw "Error: variable " + s->name + " already declared";
    }
    else
    {
        //if it doesn't, add it to the table
        table[s->name] = s;
    }
}
symbol* SymbolTable::getSymbol(string name)
{
    //check if the symbol exists in the current scope
    if (table.find(name) != table.end())
    {
        return table[name];
    }
    else
    {
        //if it doesn't, check if it exists in the parent scope
        if (parent != nullptr)
        {
            return parent->getSymbol(name);
        }
        else
        {
            //if it doesn't, throw an error
            return nullptr;
        }
    }
}
void SymbolTable::print()
{
    for (auto it = table.begin(); it != table.end(); it++)
    {
        cout << it->first << " " << it->second->symbolType << " " << it->second->value << endl;
    }
}