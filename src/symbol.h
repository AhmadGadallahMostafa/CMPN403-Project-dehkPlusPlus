#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "Result.h"
using namespace std;
struct MathExpression;
class ConditionalExprStatement;
struct symbol
{
    string name;
    string symbolType;
    int line;
    int column;
    virtual void print() {
        cout << "Symbol " << name << " " << symbolType << endl;
    }
};

//struct variable that inherits from symbol
struct variable : public symbol
{
    bool isInitialized = false;
    string type;
    bool isConst;
    string value;
    MathExpression* valueExpression;
    virtual void print() override
    {
        cout << "variable " << name << " " << type << " " << isConst << " " << value << endl;
    }
};

struct LiteralVal : public symbol
{
    string type;
    string value;
    inline LiteralVal(string type, string value)
    {
        this->type = type;
        this->value = value;
    }
    virtual void print() override
    {
        cout << "literal " << name << " " << type << " " << value << endl;
    }
};

struct parameter : public symbol
{
    string type;
    ConditionalExprStatement* conditionalExpr;
    parameter(string type, string name, ConditionalExprStatement* conditional)
    {
        this->type = type;
        this->name = name;
        this->symbolType = "parameter";
        this->conditionalExpr = conditional;
    }
    virtual void print() override
    {
        cout << "parameter " << name << " " << type << endl;
    }
    
};

struct functionSymbol : symbol
{
    string returnType;
    vector<parameter*> parameters;
    virtual void print() override
    {
        cout << "functionSymbol " << name << " " << returnType << endl;
    }
};

struct operatorSymbol
{
    string op;
    operatorSymbol(string op)
    {
        this->op = op;
    }
};

struct MathExpression
{
    public:
    vector<operatorSymbol*>ops;
    vector<symbol*>operands;
    string type;
    MathExpression(symbol* operand)
    {
        operands.push_back(operand);
        LiteralVal* literal = dynamic_cast<LiteralVal*>(operand);
        if (literal!=nullptr) {
            type = literal->type;
        }
    }
    MathExpression(string idnetifier)
    {
        variable* var = new variable();
        var->name = idnetifier;
        operands.push_back(var);
    }
    std::string getMathExpressionValue()
    {
        std::string result = "";
        for(int i = 0; i < operands.size(); i++)
        {
            if (operands[i]->name =="")
            {
                LiteralVal* val = static_cast<LiteralVal*>(operands[i]);
                result += val->value;
            }
            else
            {
                result += operands[i]->name;
            }
            if(i < ops.size())
            {
                result += ops[i]->op;
            }
        }
        return result;
    }
    std::string getMathExpressionQuadruple()
    {
        std::string result = "";
        for(int i = 0; i < operands.size(); i++)
        {
            if(i < ops.size())
            {
                if (ops[i]->op == "+") result += " ADD ";
                else if (ops[i]->op == "-") result += " SUB ";
                else if (ops[i]->op == "*") result += " MUL ";
                else if (ops[i]->op == "/") result += " DIV ";
                else if (ops[i]->op == "%") result += " MOD ";
                else if (ops[i]->op == "==") result += " EQ ";
                else if (ops[i]->op == "!=") result += " NE ";
                else if (ops[i]->op == "<") result += " LT ";
                else if (ops[i]->op == ">") result += " GT ";
                else if (ops[i]->op == "<=") result += " LE ";
                else if (ops[i]->op == ">=") result += " GE ";
                else if (ops[i]->op == "&&") result += " AND ";
                else if (ops[i]->op == "||") result += " OR ";
            }
            if (operands[i]->name =="")
            {
                LiteralVal* val = static_cast<LiteralVal*>(operands[i]);
                result += val->value;
            }
            else
            {
                result += operands[i]->name;

            }

        }
        return result;
    }
    Result appendMathExpr(MathExpression* mathExpression, operatorSymbol* op)
    {
        if (this->type != mathExpression->type)
        {
            return Result("", "Type mismatch", false);
        }
        this->operands.insert(this->operands.end(), mathExpression->operands.begin(), mathExpression->operands.end());
        this->ops.push_back(op);
        this->ops.insert(this->ops.end(), mathExpression->ops.begin(), mathExpression->ops.end());
        return Result("", "", true);
    }
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

