#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "symbol.h"
#include<stack>
using namespace std;

struct compileContext
{
    SymbolTable symbolTable;
	stack<SymbolTable*> tablesStack = stack<SymbolTable*>();
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
	bool is_main;
	ProgramNode()
	{
		this->statments = vector<Statement*>();
		this->is_main = false;
	}
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
	DeclareVariableStatement(string type, string name)
	{
		this->type = type;
		this->name = name;
	}
	virtual string compile(compileContext& compile_context) const override;

};
