#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstring>
#include "symbol.h"
#include<stack>
#include "Result.h"
#include <regex>

using namespace std;

struct compileContext
{
    SymbolTable symbolTable;
	stack<SymbolTable*> tablesStack = stack<SymbolTable*>();
	vector<SymbolTable*> tables;
	SymbolTable* getTopTable() 
	{
		if (tablesStack.empty())
			return nullptr;
		SymbolTable* parentTable = tablesStack.top();
		if (parentTable == nullptr)
		{
			return nullptr;
		}
		else 
		{
			return parentTable;
		}
	}
	void popTable() 
	{
		if (tablesStack.size() > 0)
		{
			tablesStack.pop();
		}
	}
	void pushTable(SymbolTable* table) 
	{
		tablesStack.push(table);
	}
	void addTable(SymbolTable* table) 
	{
		tables.push_back(table);
	}
};

class ConditionalExprStatement;	

class Statement
{
private:
    /* data */
public:
    virtual Result compile(compileContext& compile_context) const = 0;
	virtual void printQuadruple() const = 0;
};

class ProgramNode : public Statement
{
public:
	vector<Statement*> statments;
	bool is_main = false;
	virtual Result compile(compileContext& compile_context) const override;
	virtual void printQuadruple() const override;
	inline void appendStatement(Statement* statement)
	{
		statments.push_back(statement);
	}
};

class DeclareVariableStatement : public Statement
{
	public:
	string type;
	string name;
	ConditionalExprStatement* assignment;
	inline DeclareVariableStatement(string type, string name, ConditionalExprStatement* assignment)
	{
		this->type = type;
		this->name = name;
		this->assignment = assignment;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;

};

class ParameterList
{
public:
	vector<parameter*> parameters;
	inline void appendParameter(parameter* parameter)
	{
		parameters.push_back(parameter);
	}
};
class BlockStatement : public Statement

{
	public:
	ProgramNode* programNode;
	inline BlockStatement(ProgramNode* programNode)
	{
		this->programNode = programNode;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};
class DeclareFunctionStatement : public Statement
{
	public:
	string returnType;
	string name;
	ParameterList* parameters;
	BlockStatement* blockNode;
	inline DeclareFunctionStatement(string returnType, string name, ParameterList* parameters, BlockStatement* block)
	{
		this->returnType = returnType;
		this->name = name;
		this->parameters = parameters;
		this->blockNode = block;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class ConditionalExprStatement : public Statement
{
};

class MathExprStatement : public ConditionalExprStatement
{
	public:
	string op;
	MathExprStatement* left;
	MathExprStatement* right;
	string identifier;
	bool is_identifier;

	inline MathExprStatement(string op, MathExprStatement* left, MathExprStatement* right, bool is_identifier, string identifier)
	{
		this->op = op;
		this->left = left;
		this->right = right;
		this->is_identifier = is_identifier;
		this->identifier = identifier;
	}
	// inline string toString()
	// {
	// 	if(is_identifier)
	// 		return left;
	// 	else
	// 		return left + " " + op + " " + right;
	// }
	void printQuadruple() const override;
	virtual Result compile(compileContext& compile_context) const override;
};
