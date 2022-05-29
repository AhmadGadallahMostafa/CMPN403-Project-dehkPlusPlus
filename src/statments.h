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
	vector<string> tempQuadruple;
	vector<string> quadruple;
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
	void addQuadruple(vector<string>& quadruple) 
	{
		this->quadruple.insert(this->quadruple.end(), quadruple.begin(), quadruple.end());
	}
	void addTempQuadruple(vector<string>& quadruple) 
	{
		this->tempQuadruple.insert(this->tempQuadruple.end(), quadruple.begin(), quadruple.end());
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
	bool is_const = false;
	ConditionalExprStatement* assignment;
	inline DeclareVariableStatement(string type, string name, ConditionalExprStatement* assignment, bool is_const)
	{
		this->type = type;
		this->name = name;
		this->assignment = assignment;
		this->is_const = is_const;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;

};


class AssignValueStatement : public Statement
{
	public:
	string name;
	ConditionalExprStatement* assignment;
	inline AssignValueStatement(string name, ConditionalExprStatement* assignment)
	{
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
	operatorSymbol* op;
	MathExpression* mathExpression;

	inline MathExprStatement(operatorSymbol* op,MathExpression* mathExpression)
	{
		this->op = op;
		this->mathExpression = mathExpression;
	}
	Result appendExpression(MathExprStatement* mathExpression, operatorSymbol* op);
	void printQuadruple() const override;
	virtual Result compile(compileContext& compile_context) const override;
};

class DeclareIfStatement : public ConditionalExprStatement
{
	public:
	ConditionalExprStatement* conditionalExpr;
	BlockStatement* ifBlock;
	BlockStatement* elseBlock;
	DeclareIfStatement* elIf;

	inline DeclareIfStatement(ConditionalExprStatement* conditionalExpr, BlockStatement* ifBlock, BlockStatement* elseBlock, DeclareIfStatement* elIf)
	{
		this->conditionalExpr = conditionalExpr;
		this->ifBlock = ifBlock;
		this->elseBlock = elseBlock;
		this->elIf = elIf;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class DeclareAssignStatement : public ConditionalExprStatement
{
	public:
	string identifier;
	ConditionalExprStatement* conditionalExpr;
	inline DeclareAssignStatement(string identifier, ConditionalExprStatement* conditionalExpr)
	{
		this->identifier = identifier;
		this->conditionalExpr = conditionalExpr;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class DeclareWhileStatement : public ConditionalExprStatement
{
	public:
	ConditionalExprStatement* conditionalExpr;
	BlockStatement* block;
	inline DeclareWhileStatement(ConditionalExprStatement* conditionalExpr, BlockStatement* block)
	{
		this->conditionalExpr = conditionalExpr;
		this->block = block;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class DeclareDoWhileStatement : public ConditionalExprStatement
{
	public:
	ConditionalExprStatement* conditionalExpr;
	BlockStatement* block;
	inline DeclareDoWhileStatement(ConditionalExprStatement* conditionalExpr, BlockStatement* block)
	{
		this->conditionalExpr = conditionalExpr;
		this->block = block;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class SwitchCase : public Statement
{
	public:
	LiteralVal* switchCaseValue;
	BlockStatement* block;
	inline SwitchCase(LiteralVal* switchCaseValue, BlockStatement* block)
	{
		this->switchCaseValue = switchCaseValue;
		if (switchCaseValue == nullptr)
		{
			switchCaseValue = new LiteralVal("default", "default");
		}
		this->block = block;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class SwitchCaseList
{
	public:
	vector<SwitchCase*> switchCases;
	inline void appendSwitchCase(SwitchCase* switchCase)
	{
		switchCases.push_back(switchCase);
	}
};

class DeclareSwitchStatement : Statement
{
	public:
	string identifier;
	SwitchCaseList* switchCaseList;
	inline DeclareSwitchStatement(string identifier, SwitchCaseList* switchCaseList)
	{
		this->identifier = identifier;
		this->switchCaseList = switchCaseList;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;

};

class ForInitExpression : public ConditionalExprStatement
{
	public:
	string identifier="";
	string type="";
	ConditionalExprStatement* conditionalExpr;
	inline ForInitExpression(string type, string identifier, ConditionalExprStatement* conditionalExpr)
	{
		this->identifier = identifier;
		this->conditionalExpr = conditionalExpr;
		this->type = type;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class ForFinalExpression : public ConditionalExprStatement
{
	public:
	ConditionalExprStatement* conditionalExpr;
	string identifier="";
	inline ForFinalExpression(ConditionalExprStatement* conditionalExpr, string identifier)
	{
		this->conditionalExpr = conditionalExpr;
		this->identifier = identifier;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class ForLoopDo 
{
	public:
	vector<ForFinalExpression*> forFinalExpressions;
	inline void appendForFinalExpression(ForFinalExpression* forFinalExpression)
	{
		forFinalExpressions.push_back(forFinalExpression);
	}
};

class DeclareForStatement : Statement
{
	public:
	ForInitExpression* forInitExpression;
	ForLoopDo* forLoopDo;
	ConditionalExprStatement* conditionalExpr;
	BlockStatement* block;
	inline DeclareForStatement(ForInitExpression* forInitExpression, ForLoopDo* forLoopDo, ConditionalExprStatement* conditionalExpr,BlockStatement* block)
	{
		this->forInitExpression = forInitExpression;
		this->forLoopDo = forLoopDo;
		this->block = block;
		this->conditionalExpr = conditionalExpr;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class ArgumentList
{
	public:
	vector<ConditionalExprStatement*> arguments;
	inline void appendArgument(ConditionalExprStatement* argument)
	{
		arguments.push_back(argument);
	}
};

class FunctionCall : public ConditionalExprStatement
{
	public:
	string identifier;
	ArgumentList* argumentList;
	inline FunctionCall(string identifier, ArgumentList* argumentList)
	{
		this->identifier = identifier;
		this->argumentList = argumentList;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};

class ReturnStatment : public ConditionalExprStatement
{
	public:
	ConditionalExprStatement* conditionalExpr;
	inline ReturnStatment(ConditionalExprStatement* conditionalExpr)
	{
		this->conditionalExpr = conditionalExpr;
	}
	virtual Result compile(compileContext& compile_context) const override;
	void printQuadruple() const override;
};