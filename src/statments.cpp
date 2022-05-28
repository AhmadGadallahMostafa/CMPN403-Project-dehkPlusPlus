#include "statments.h"

Result DeclareVariableStatement::compile(compileContext& compile_context) const
{
	//create varaible
	variable* var = new variable();
	var->name = this->name;
	var->symbolType = "variable";
	var->type = this->type;
	var->isConst = this->is_const;
	//prepare return result
	Result compileVarResult = Result("","",false);
	// if var was declared with assignment
	// then compile the assignment
	if (this->assignment != nullptr)
	{
		var->isInitialized = true;
		Result compileAssignmentResult = this->assignment->compile(compile_context);
		compileVarResult.addResult(compileAssignmentResult);
		//if compiling math expr had any errors then return error 
		if (compileVarResult.isError())
		{
			return compileVarResult;
		}
		//if compiling math expr had no errors then check type of mathexpr before assigning
		MathExprStatement* mathExpr = (MathExprStatement*)this->assignment;
		if (mathExpr->mathExpression->type != var->type)
		{
			compileVarResult.setError("Type of variable "+var->name +" is not equal to type of the expression");
			return compileVarResult;
		}
		//if type of mathexpr and type of variable match then assign value
		var->value = mathExpr->mathExpression->getMathExpressionValue();
		var->valueExpression = mathExpr->mathExpression;
	}
	else
	{
		var->isInitialized = false;
	}
	Result declareVarResult = compile_context.getTopTable()->addSymbol(var);
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
		symbol->type = param->type;
		symbol->isConst = false;
		symbol->symbolType = param->symbolType;
		if (param->conditionalExpr != nullptr)
		{
			symbol->isInitialized = true;
			Result compileConditionalExprResult = param->conditionalExpr->compile(compile_context);
			compileResult.addResult(compileConditionalExprResult);
			if (compileResult.isError())
			{
				return compileResult;
			}
			MathExprStatement* mathExpr = (MathExprStatement*)param->conditionalExpr;
			if (mathExpr->mathExpression->type != symbol->type)
			{
				compileResult.setError("Type of variable "+param->name +" is not equal to type of the expression");
				return compileResult;
			}
			symbol->value = mathExpr->mathExpression->getMathExpressionValue();
			symbol->valueExpression = mathExpr->mathExpression;
		}
		else
		{
			symbol->isInitialized = false;
		}
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
	Result result = Result("","",false);
	for (auto operand : this->mathExpression->operands)
	{
		variable* v = dynamic_cast<variable*>(operand);
		if (v != nullptr)
		{
			symbol* varFromTable = compile_context.getTopTable()->getSymbol(v->name);
			if (varFromTable == nullptr)
			{
				result.setError("Variable"+v->name+" not declared");
				return result;
			}
			else
			{
				v = static_cast<variable*>(varFromTable);
				mathExpression->type = v->type;
			}
		}
	}
	return result;
}
Result MathExprStatement::appendExpression(MathExprStatement* mathExpression, operatorSymbol* op)
{
	Result result = this->mathExpression->appendMathExpr(mathExpression->mathExpression, op);
	return result;
}

void MathExprStatement::printQuadruple() const
{
	return;
}

Result DeclareIfStatement::compile(compileContext& compile_context) const
{
	Result compileResult = Result("", "", false);
	Result r = this->conditionalExpr->compile(compile_context);
	compile_context.getTopTable()->removeSymbol(r.getResult());
	compileResult.addResult(r);
	if (compileResult.isError())
	{
		return compileResult;
	}
	SymbolTable* table = new SymbolTable(compile_context.getTopTable());
	compile_context.addTable(table);
	compile_context.pushTable(table);
	r = this->ifBlock->compile(compile_context);
	compileResult.addResult(r);
	printQuadruple();
	if (this->elIf != nullptr)
	{
		r = this->elIf->compile(compile_context);
		compileResult.addResult(r);
	}
	if (this->elseBlock != nullptr)
	{
		SymbolTable* table = new SymbolTable(compile_context.getTopTable());
		compile_context.addTable(table);
		compile_context.pushTable(table);
		r = this->elseBlock->compile(compile_context);
		compileResult.addResult(r);
	}
	return compileResult;
}
void DeclareIfStatement::printQuadruple() const
{
	cout << "If" << endl;
	this->conditionalExpr->printQuadruple();
	cout << "Goto" << endl;
	this->ifBlock->printQuadruple();
	if (this->elseBlock != nullptr)
	{
		cout << "Else" << endl;
		this->elseBlock->printQuadruple();
	}
}

Result DeclareAssignStatement::compile(compileContext& compile_context) const
{
	Result compileResult = Result("", "", false);
	symbol* var = compile_context.getTopTable()->getSymbol(this->identifier);
	if (var == nullptr)
	{
		compileResult.setError("Variable " + this->identifier + " not declared");
		return compileResult;
	}
	variable* v = static_cast<variable*>(var);
	Result r = this->conditionalExpr->compile(compile_context);
	compileResult.addResult(r);
	if (compileResult.isError())
	{
		return compileResult;
	}
	MathExprStatement* mathExpr = (MathExprStatement*)this->conditionalExpr;
	if (mathExpr->mathExpression->type != v->type)
	{
		compileResult.setError("Type mismatch "+v->name+ " is of type "+v->type+" and value assigned is of type "+mathExpr->mathExpression->type);
		return compileResult;
	}
	v->value = mathExpr->mathExpression->getMathExpressionValue();
	v->valueExpression = mathExpr->mathExpression;
	return compileResult;	
}

void DeclareAssignStatement::printQuadruple() const
{
	cout << "Assign: " << this->identifier << endl;
	this->conditionalExpr->printQuadruple();
}

Result DeclareWhileStatement::compile(compileContext& compile_context)const
{
	Result compileResult = Result("", "", false);
	SymbolTable* table = new SymbolTable(compile_context.getTopTable());
	compile_context.addTable(table);
	compile_context.pushTable(table);
	Result r = this->conditionalExpr->compile(compile_context);
	compileResult.addResult(r);
	if (compileResult.isError())
	{
		return compileResult;
	}
	r = this->block->compile(compile_context);
	compileResult.addResult(r);
	printQuadruple();
	return compileResult;
}

void DeclareWhileStatement::printQuadruple() const
{
	cout << "While" << endl;
	this->conditionalExpr->printQuadruple();
	cout << "Goto" << endl;
	this->block->printQuadruple();
}

Result DeclareDoWhileStatement::compile(compileContext& compile_context) const
{
	Result compileResult = Result("", "", false);
	SymbolTable* table = new SymbolTable(compile_context.getTopTable());
	compile_context.addTable(table);
	compile_context.pushTable(table);
	Result r = this->block->compile(compile_context);
	compileResult.addResult(r);
	if (compileResult.isError())
	{
		return compileResult;
	}
	r = this->conditionalExpr->compile(compile_context);
	compileResult.addResult(r);
	printQuadruple();
	return compileResult;
}

void DeclareDoWhileStatement::printQuadruple() const
{
	cout << "Do" << endl;
	this->block->printQuadruple();
	cout << "While" << endl;
	this->conditionalExpr->printQuadruple();
}

Result SwitchCase::compile(compileContext& compile_context) const
{
	Result compileResult = Result("", "", false);
	SymbolTable* table = new SymbolTable(compile_context.getTopTable());
	compile_context.addTable(table);
	compile_context.pushTable(table);
	Result r = this->block->compile(compile_context);
	compileResult.addResult(r);
	if (compileResult.isError())
	{
		return compileResult;
	}
	return compileResult;
}

void SwitchCase::printQuadruple() const
{
	cout << "Case " << this->switchCaseValue->value << endl;
	cout << "Goto" << endl;
	this->block->printQuadruple();
}

Result DeclareSwitchStatement::compile(compileContext& compile_context) const 
{
	Result compileResult = Result("","",false);
	symbol *s = compile_context.getTopTable()->getSymbol(this->identifier);
	if (s == nullptr)
	{
		compileResult.setError("Variable " + this->identifier + " not declared");
		return compileResult;
	}
	variable* v = static_cast<variable*>(s);
	SymbolTable* table = new SymbolTable(compile_context.getTopTable());
	compile_context.addTable(table);
	compile_context.pushTable(table);
	for (auto switchCase : this->switchCaseList->switchCases)
	{
		if (switchCase->switchCaseValue->type != v->type)
		{
			compileResult.setError("Type mismatch " + v->name + " is of type " + v->type + " can't be used to switch " + switchCase->switchCaseValue->type);
			return compileResult;
		}
		Result r = switchCase->compile(compile_context);
		compileResult.addResult(r);
	}
	if (compileResult.isError())
	{
		return compileResult;
	}
	printQuadruple();
	return compileResult;
}

void DeclareSwitchStatement::printQuadruple() const
{
	cout << "Switch " << this->identifier << endl;
	for (auto switchCase : this->switchCaseList->switchCases)
	{
		switchCase->printQuadruple();
	}
}

Result ForInitExpression::compile(compileContext& compile_context) const
{
	Result compileResult = Result("", "", false);
	//if expression was a variable declaration
	if(type != "")
	{
		variable* v = new variable();
		v->name = identifier;
		v->type = type;
		v->symbolType = "variable";
		v->isConst = false;
		if (conditionalExpr != nullptr)
		{
			Result r = conditionalExpr->compile(compile_context);
			compileResult.addResult(r);
			if (compileResult.isError())
			{
				return compileResult;
			}
			MathExprStatement* mathExpr = (MathExprStatement*)conditionalExpr;
			if (mathExpr->mathExpression->type != v->type)
			{
				compileResult.setError("Type mismatch " + v->name + " is of type " + v->type + " and value assigned is of type " + mathExpr->mathExpression->type);
				return compileResult;
			}
			v->value = mathExpr->mathExpression->getMathExpressionValue();
			v->valueExpression = mathExpr->mathExpression;
		}
		Result addResult = compile_context.getTopTable()->addSymbol(v);
		compileResult.addResult(addResult);
		if (compileResult.isError())
		{
			return compileResult;
		}
	}	
	else if(type == "" && identifier != "")
	{
		//variable was already declared before
		symbol* s = compile_context.getTopTable()->getSymbol(identifier);
		if (s == nullptr)
		{
			compileResult.setError("Variable " + identifier + " not declared");
			return compileResult;
		}
		variable* v = static_cast<variable*>(s);
		if(conditionalExpr != nullptr)
		{
			Result r = conditionalExpr->compile(compile_context);
			compileResult.addResult(r);
			if (compileResult.isError())
			{
				return compileResult;
			}
			MathExprStatement* mathExpr = (MathExprStatement*)conditionalExpr;
			if (mathExpr->mathExpression->type != v->type)
			{
				compileResult.setError("Type mismatch " + v->name + " is of type " + v->type + " and value assigned is of type " + mathExpr->mathExpression->type);
				return compileResult;
			}
			v->value = mathExpr->mathExpression->getMathExpressionValue();
			v->valueExpression = mathExpr->mathExpression;
		}
	}
	else
	{
		if (conditionalExpr!= nullptr)
		{
			Result r = conditionalExpr->compile(compile_context);
			compileResult.addResult(r);
			if (compileResult.isError())
			{
				return compileResult;
			}
		}
	}
	return compileResult;
}

void ForInitExpression::printQuadruple() const
{
	if (type != "")
	{
		cout << "Declare " << identifier << " " << type << endl;
	}
	else if (type == "" && identifier != "")
	{
		cout << "Assign " << identifier << endl;
	}
	else
	{
		this->conditionalExpr->printQuadruple();
	}
}

Result ForFinalExpression::compile(compileContext& compile_context) const
{
	Result compileResult = Result("", "", false);
	if (identifier != "")
	{
		//variable was already declared before
		symbol* s = compile_context.getTopTable()->getSymbol(identifier);
		if (s == nullptr)
		{
			compileResult.setError("Variable " + identifier + " not declared");
			return compileResult;
		}
		variable* v = static_cast<variable*>(s);
		if(conditionalExpr != nullptr)
		{
			Result r = conditionalExpr->compile(compile_context);
			compileResult.addResult(r);
			if (compileResult.isError())
			{
				return compileResult;
			}
			MathExprStatement* mathExpr = (MathExprStatement*)conditionalExpr;
			if (mathExpr->mathExpression->type != v->type)
			{
				compileResult.setError("Type mismatch " + v->name + " is of type " + v->type + " and value assigned is of type " + mathExpr->mathExpression->type);
				return compileResult;
			}
			v->value = mathExpr->mathExpression->getMathExpressionValue();
			v->valueExpression = mathExpr->mathExpression;
		}
	}
	else if (conditionalExpr != nullptr)
	{
		Result r = conditionalExpr->compile(compile_context);
		compileResult.addResult(r);
		if (compileResult.isError())
		{
			return compileResult;
		}
	}
	return compileResult;
} 

void ForFinalExpression::printQuadruple() const
{
	if (identifier != "")
	{
		cout << "Assign " << identifier << endl;
	}
	else if (conditionalExpr != nullptr)
	{
		this->conditionalExpr->printQuadruple();
	}
}

Result DeclareForStatement::compile(compileContext& compile_context)const
{
	Result compileResult = Result("", "", false);
	SymbolTable* table = new SymbolTable(compile_context.getTopTable());
	compile_context.addTable(table);
	compile_context.pushTable(table);
	Result r = forInitExpression->compile(compile_context);
	compileResult.addResult(r);
	if (compileResult.isError())
	{
		return compileResult;
	}
	r = conditionalExpr->compile(compile_context);
	compileResult.addResult(r);
	if (compileResult.isError())
	{
		return compileResult;
	}
	for (auto forDo : forLoopDo->forFinalExpressions)
	{
		r = forDo->compile(compile_context);
		compileResult.addResult(r);
		if (compileResult.isError())
		{
			return compileResult;
		}
	}
	r = block->compile(compile_context);
	compileResult.addResult(r);
	if (compileResult.isError())
	{
		return compileResult;
	}
	printQuadruple();
	return compileResult;
}

void DeclareForStatement::printQuadruple() const
{
	cout << "DeclareFor " << endl;
	forInitExpression->printQuadruple();
	conditionalExpr->printQuadruple();
	for (auto forDo : forLoopDo->forFinalExpressions)
	{
		forDo->printQuadruple();
	}
	block->printQuadruple();
}