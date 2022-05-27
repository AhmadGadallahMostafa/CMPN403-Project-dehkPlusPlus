#include "statments.h"

Result DeclareVariableStatement::compile(compileContext& compile_context) const
{
	variable* symbol = new variable();
	symbol->name = this->name;
	symbol->symbolType = "variable";
	symbol->type = this->type;
	symbol->isConst = false;
	Result result = Result("","",false);
	Result compileVarResult = Result("","",false);
	if (this->assignment != nullptr)
	{
		symbol->isInitialized = true;
		Result compileAssignmentResult = this->assignment->compile(compile_context);
		result.addResult(compileAssignmentResult);
		if (compileAssignmentResult.isError())
		{
			return compileAssignmentResult;
		}
		else
		{
			MathExprStatement* mathExpr = (MathExprStatement*)this->assignment;
			symbol->value = result.getResult();
			compile_context.getTopTable()->removeSymbol(symbol->value);
			
		}
	}
	else
	{
		symbol->isInitialized = false;
	}
	compileVarResult.addResult(result);
	Result declareVarResult = compile_context.getTopTable()->addSymbol(symbol);
	compileVarResult.addResult(declareVarResult);
	return compileVarResult;
}
void DeclareVariableStatement::printQuadruple() const
{
	cout << "DeclareVariableStatement" << endl;
	cout << "name: " << this->name << endl;
	cout << "type: " << this->type << endl;
	if (this->assignment != nullptr)
	{
		cout << "assignment: " << endl;
		this->assignment->printQuadruple();
	}
	else
	{
		cout << "assignment: null" << endl;
	}
}

Result ProgramNode::compile(compileContext& compile_context) const
{
	Result compileResult = Result("", "", false);
	if (is_main)
	{
		SymbolTable* parentTable = compile_context.getTopTable();
		SymbolTable* table = new SymbolTable(parentTable);
		compile_context.addTable(table);
		compile_context.pushTable(table);
	}
	for (auto Statement : statments)
	{
		Result result = Statement->compile(compile_context);
		//when compiling statments if there is an error, stop compiling
		if (result.isError())
		{
			return result;
		}
		compileResult.addResult(result);
	}
	if (!is_main)
	{
		compile_context.popTable();
	}
	return compileResult;
}
void ProgramNode::printQuadruple() const
{
	for (auto Statement : statments)
	{
		Statement->printQuadruple();
	}
}

Result DeclareFunctionStatement::compile(compileContext& compile_context) const
{
	Result compileResult = Result("", "", false);
	functionSymbol* symbol = new functionSymbol();
	symbol->name = this->name;
	symbol->symbolType = "functionSymbol";
	symbol->returnType = this->returnType;
	//add functionSymbol to symbol table 
	Result r = compile_context.getTopTable()->addSymbol(symbol);
	compileResult.addResult(r);
	//if compile result is error, return it
	if (compileResult.isError())
	{
		return compileResult;
	}
	SymbolTable *table = new SymbolTable(compile_context.getTopTable());
	compile_context.addTable(table);
	compile_context.pushTable(table);
	//add functionSymbol parameters to its scopes
	for (auto param : this->parameters->parameters)
	{
		variable* symbol = new variable();
		symbol->name = param->name;
		symbol->symbolType = "variable";
		symbol->type = param->type;
		symbol->isConst = false;
		Result result = compile_context.getTopTable()->addSymbol(symbol);
		compileResult.addResult(result);
		//if compile result is error, return it
		if (compileResult.isError())
		{
			return compileResult;
		}
	}
	r = this->blockNode->compile(compile_context);
	compileResult.addResult(r);
	return compileResult;
}
void DeclareFunctionStatement::printQuadruple() const
{
	cout << "Function: " << this->name << endl;
	cout << "Parameters: ";
	for (auto param : this->parameters->parameters)
	{
		cout << param->name << " ";
	}
	cout << endl;
	this->blockNode->printQuadruple();
}

Result BlockStatement::compile(compileContext& compile_context) const
{
	Result result = Result("","",false);
	Result compileResult = programNode->compile(compile_context);
	result.addResult(compileResult);
	return result;
}
void BlockStatement::printQuadruple() const
{
	programNode->printQuadruple();
}

Result MathExprStatement::compile(compileContext& compile_context) const
{
	Result compileResult = Result("", "", false);
	if (is_identifier)
	{
		symbol* s = compile_context.getTopTable()->getSymbol(this->identifier);
		if (s == nullptr)
		{
			compileResult.setError("Identifier " + this->identifier + " not found");
			return compileResult;
		}
		compileResult.setResult(this->identifier);
		return compileResult;
	}
	else if (is_const_val)
	{
		compileResult.setResult(this->op+this->identifier);
		return compileResult;
	}
	else 
	{
	string left =  this->left->compile(compile_context).getResult();
	//regex for checking if the left is a variable
	string left_regex= ("^[a-zA-Z_][a-zA-Z0-9_]*$");
	symbol* leftOperand = compile_context.getTopTable()->getSymbol(left); 
	//after getting temp leftOperand remove it form table
	if(!regex_match(left, regex(left_regex)))
	{
		compile_context.getTopTable()->removeSymbol(left);
	}
	symbol* rightOperand = compile_context.getTopTable()->getSymbol(this->right->identifier);
	if (leftOperand == nullptr)
	{
		compileResult.setError("Identifier " + this->left->identifier + " not found");
		return compileResult;
	}
	if (rightOperand == nullptr)
	{
		if (this->right->is_const_val)
		{
			compileResult.setResult(leftOperand->name+this->op + this->right->identifier);
			return compileResult;
		}
		else
		{
			compileResult.setError("Identifier " + this->right->identifier + " not found");
			return compileResult;
		}
	}
	variable* leftVar = static_cast<variable*>(leftOperand);
	variable* rightVar = static_cast<variable*>(rightOperand);
	if (leftVar->type != rightVar->type)
	{
		compileResult.setError("Type mismatch");
		return compileResult;
	}
	variable* temp = new variable();
	temp->name = leftOperand->name + this->op + rightOperand->name;
	temp->symbolType = "variable";
	temp->type = leftVar->type;
	temp->isConst = false;
	Result result = compile_context.getTopTable()->addSymbol(temp);
	result.setResult(leftOperand->name + this->op + rightOperand->name);
	compileResult.addResult(result);
	this->printQuadruple();
	return compileResult;
	}
}

void MathExprStatement::printQuadruple() const
{
	if (this->is_identifier)
	{
		std::cout << "Assign " << this->identifier << " " << this->left->identifier << std::endl;
	}
	else
	{
		std::cout << "mov\teax, " << this->left->identifier << std::endl;
		std::cout << "mov\tedx, " << this->right->identifier << std::endl;
		std::cout << "add\teax, edx" << std::endl;
	}
}