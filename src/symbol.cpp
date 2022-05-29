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
            std::cout << "variable " << it->first << " " << v->type << " " << v->isConst << " " << v->value << endl;
        }
        else if (it->second->symbolType == "functionSymbol")
        {
            functionSymbol* f = (functionSymbol*)it->second;
            std::cout << "functionSymbol " << it->first << " " << f->returnType << endl;
        }
        else if (it->second->symbolType == "parameter")
        {
            variable* p = static_cast<variable*>(it->second);
            std::cout << "parameter " << it->first << " " << p->type <<" "<<p->value<< endl;
        }
        //cout << it->first << " " << it->second->symbolType << " " << it->second->line << " " << it->second->column << endl;
    }
}

void SymbolTable::printToFile(ofstream& file)
{
    for (auto it = table.begin(); it != table.end(); it++)
    {
        if (it->second->symbolType == "variable")
        {
            variable* v = (variable*)it->second;
            std::cout << "variable " << it->first << " " << v->type << " " << v->isConst << " " << v->value << endl;
        }
        else if (it->second->symbolType == "functionSymbol")
        {
            functionSymbol* f = (functionSymbol*)it->second;
            std::cout << "functionSymbol " << it->first << " " << f->returnType << endl;
        }
        else if (it->second->symbolType == "parameter")
        {
            variable* p = static_cast<variable*>(it->second);
            std::cout << "parameter " << it->first << " " << p->type <<" "<<p->value<< endl;
        }
        //cout << it->first << " " << it->second->symbolType << " " << it->second->line << " " << it->second->column << endl;
    }
}

void SymbolTable::addChild(SymbolTable* child)
{
    children.push_back(child);
}

vector<string> MathExpression::printQuadruple()
{
    stack<string> temps;
    string finalResult;
    vector<string> quadruple;
    int quadrupleCounter = 0;
    stack<symbol*> symbols;
    stack<operatorSymbol*> opsStack;
    for(auto s: this->operands)
    {
        symbols.push(s);
    }
    for(auto s: this->ops)
    {
        opsStack.push(s);
    }
    while (opsStack.size()>0)
    {
        operatorSymbol* op = opsStack.top();
        opsStack.pop();
        if (op->op != "!")
        {
            if (temps.size()>0)
            {
                string prevTemp = temps.top();
                temps.pop();
                symbol* s = symbols.top();
                symbols.pop();
                quadrupleCounter++;
                string temp = "t" + to_string(quadrupleCounter);
                if (s->symbolType == "literalVal")
                {
                    LiteralVal* val = (LiteralVal*)s;
                    quadruple.push_back(op->getOpQuadruple(op->op,prevTemp, val->value)+" "+temp+" "+prevTemp+" "+val->value);
                }
                else
                quadruple.push_back(op->getOpQuadruple(op->op, prevTemp, s->name)+" "+temp+" "+prevTemp+" "+s->name);
                finalResult = temp;
            }
            else
            {
            symbol* operand2 = symbols.top();
            symbols.pop();
            string op2String;
            if (operand2->symbolType=="literalVal")
            {
                LiteralVal* val = (LiteralVal*)operand2;
                op2String = val->value;
            }
            else
            {
                op2String = operand2->name;
            }
            symbol* operand1 = symbols.top();
            symbols.pop();
            string op1String;
            if (operand1->symbolType=="literalVal")
            {
                LiteralVal* val = (LiteralVal*)operand1;
                op1String = val->value;
            }
            else
            {
                op1String = operand1->name;
            }
            quadrupleCounter++;
            string temp = "t" + to_string(quadrupleCounter);
            temps.push(temp);
            quadruple.push_back(op->getOpQuadruple(op->op, op1String, op2String)+" "+temp+" "+op1String+" "+op2String);
            finalResult = temp;
            }
        }
    }
    return quadruple;
}

