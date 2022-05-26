#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstring>
#include "symbol.h"
#include<stack>
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


class Statement
{
private:
    /* data */
public:
    virtual string compile(compileContext& compile_context) const = 0;
};

class ProgramNode : public Statement
{
public:
	vector<Statement*> statments;
	bool is_main = false;
	virtual string compile(compileContext& compile_context) const override;
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
	inline DeclareVariableStatement(string type, string name)
	{
		this->type = type;
		this->name = name;
	}
	virtual string compile(compileContext& compile_context) const override;

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
class BlockNode : public Statement

{
	public:
	ProgramNode* programNode;
	inline BlockNode(ProgramNode* programNode)
	{
		this->programNode = programNode;
	}
	virtual string compile(compileContext& compile_context) const override;
};
class DeclareFunctionStatement : public Statement
{
	public:
	string returnType;
	string name;
	ParameterList* parameters;
	BlockNode* blockNode;
	inline DeclareFunctionStatement(string returnType, string name, ParameterList* parameters, BlockNode* block)
	{
		this->returnType = returnType;
		this->name = name;
		this->parameters = parameters;
		this->blockNode = block;
	}
	virtual string compile(compileContext& compile_context) const override;
};

