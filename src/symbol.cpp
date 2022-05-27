#include "symbol.h"

SymbolTable::SymbolTable(SymbolTable* parent)
{
    if(parent == nullptr)
    {
        this->parent = nullptr;
    }
    else
    {
        this->parent = parent;
    }
}



Result SymbolTable::addSymbol(symbol* s)
{
    //check if the symbol already exists
    if (table.find(s->name) != table.end())
    {
        //if variable is already declared
        return Result("", "Symbol already declared in same scope", true);
    }
    else
    {
        //if it doesn't, add it to the table
        table[s->name] = s;
        return Result ("Symbol %s added", "", false);
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
        if (it->second->symbolType == "variable")
        {
            variable* v = (variable*)it->second;
            cout << "variable " << it->first << " " << v->type << " " << v->isConst << " " << v->value << endl;
        }
        else if (it->second->symbolType == "functionSymbol")
        {
            functionSymbol* f = (functionSymbol*)it->second;
            cout << "functionSymbol " << it->first << " " << f->returnType << endl;
        }
        else if (it->second->symbolType == "parameter")
        {
            parameter* p = (parameter*)it->second;
            cout << "parameter " << it->first << " " << p->type << endl;
        }
        //cout << it->first << " " << it->second->symbolType << " " << it->second->line << " " << it->second->column << endl;
    }
}

void SymbolTable::removeSymbol(string name)
{
    table.erase(name);
}