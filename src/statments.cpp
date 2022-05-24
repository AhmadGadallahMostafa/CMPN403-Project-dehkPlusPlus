#include "statments.h"

string DeclareVariableStatement::compile(compileContext& compile_context) const
{
	auto s = compile_context.getTopTable()->getSymbol(this->name);
	if (s != nullptr)
	{
		return ("Variable " + this->name + " is already defined");
	}
	else
	{
		variable* symbol = new variable();
		symbol->name = this->name;
		symbol->symbolType = "variable";
		symbol->type = this->type;
		symbol->isConst = false;
		compile_context.getTopTable()->addSymbol(symbol);
	}
	return "variable " + this->name + " declared";
}

string ProgramNode::compile(compileContext& compile_context) const
{
	string result = "";
	SymbolTable* parentTable = compile_context.getTopTable();
	SymbolTable table = new SymbolTable(parentTable);
	compile_context.pushTable(&table);
	for (auto Statement : statments)
	{
		result += Statement->compile(compile_context);
	}
	compile_context.popTable();
	return result;
}
