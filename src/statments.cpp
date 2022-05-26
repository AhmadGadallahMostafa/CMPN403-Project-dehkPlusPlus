#include "statments.h"

string DeclareVariableStatement::compile(compileContext& compile_context) const
{
	SymbolTable* currentScope = compile_context.getTopTable();
	symbol* s = currentScope->getSymbol(this->name);

		variable* symbol = new variable();
		symbol->name = this->name;
		symbol->symbolType = "variable";
		symbol->type = this->type;
		symbol->isConst = false;
		return compile_context.getTopTable()->addSymbol(symbol);
}

string ProgramNode::compile(compileContext& compile_context) const
{
	string result = "";
	if (is_main)
	{
		SymbolTable* parentTable = compile_context.getTopTable();
		SymbolTable* table = new SymbolTable(parentTable);
		compile_context.addTable(table);
		compile_context.pushTable(table);
	}
	for (auto Statement : statments)
	{
		result += Statement->compile(compile_context);
	}
	if (!is_main)
	{
		compile_context.popTable();
	}
	return result;
}

string DeclareFunctionStatement::compile(compileContext& compile_context) const
{
	auto s = compile_context.getTopTable()->getSymbol(this->name);
	string r = "";
	if (s != nullptr)
	{
		return ("Function " + this->name + " is already defined \n");
	}
	else
	{
		function* symbol = new function();
		symbol->name = this->name;
		symbol->symbolType = "function";
		symbol->returnType = this->returnType;
		compile_context.getTopTable()->addSymbol(symbol);
		SymbolTable *table = new SymbolTable(compile_context.getTopTable());
		compile_context.addTable(table);
		compile_context.pushTable(table);
		for (auto param : this->parameters->parameters)
		{
			// auto s = compile_context.getTopTable()->getSymbol(param->name);
			variable* symbol = new variable();
			symbol->name = param->name;
			symbol->symbolType = "variable";
			symbol->type = param->type;
			symbol->isConst = false;
			compile_context.getTopTable()->addSymbol(symbol);
		}
		r = this->blockNode->compile(compile_context);
	}
	return "function " + this->name + " declared \n"+ r ;
}

string BlockNode::compile(compileContext& compile_context) const
{
	string result = "";
	result = programNode->compile(compile_context);
	return result;
}
