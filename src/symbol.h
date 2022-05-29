#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
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
    vector<string> printQuadruple();
};

struct LiteralVal : public symbol
{
    string type;
    string value;
    inline LiteralVal(string type, string value)
    {
        this->type = type;
        this->value = value;
        this->symbolType = "literalVal";
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
    void addParameters(vector<parameter*>& parameter)
    {
       this->parameters = parameter;
    }
    virtual void print() override
    {
        cout << "functionSymbol " << name << " " << returnType << endl;
    }
    string printQuadruple();
};

struct operatorSymbol
{
    string op;
    operatorSymbol(string op)
    {
        this->op = op;
    }
    static string getOpQuadruple(string operatorS, string op1, string op2)
    {
        if (operatorS == "+")
        {
            return "ADD";
        }
        else if (operatorS == "-")
        {
            return "SUB";
        }
        else if (operatorS == "*")
        {
            return "MUL";
        }
        else if (operatorS == "/")
        {
            return "DIV";
        }
        else if (operatorS == "==")
        {
            return "EQ";
        }
        else if (operatorS == "!=")
        {
            return "NE";
        }
        else if (operatorS == "<")
        {
            return "LT";
        }
        else if (operatorS == ">")
        {
            return "GT";
        }
        else if (operatorS == "<=")
        {
            return "LE";
        }
        else if (operatorS == ">=")
        {
            return "GE";
        }
        else if (operatorS == "&&")
        {
            return "AND";
        }
        else if (operatorS == "||")
        {
            return "OR";
        }
        else if (operatorS == "!")
        {
            return "NOT";
        }
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
    vector<string> printQuadruple();
    Result appendOperator(operatorSymbol* op)
    {
        ops.push_back(op);
        return Result("", "", true);
    }
    Result appendMathExpr(MathExpression* mathExpression, operatorSymbol* op)
    {
        // if (this->type != mathExpression->type)
        // {
        //     return Result("", "Type mismatch", false);
        // }
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
    vector<SymbolTable*> children;
public:
    SymbolTable(SymbolTable* parent);
    Result addSymbol(symbol* s);
    symbol* getSymbol(string name);
    void addChild(SymbolTable* child);
    void removeSymbol(string name);
    void print();
    void printToFile(ofstream& file);
};

