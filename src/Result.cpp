#include"Result.h"

std::string Result::getResult()
{
    return result;
}

bool Result::isError()
{
    return is_error;
}

void Result::addResult(Result& r)
{
    result += r.result;
    error += r.error;
    is_error = r.is_error;
}

void Result::setError(std::string error)
{
    this->error = error;
    is_error = true;
}

void Result::setResult(std::string result)
{
    this->result = result;
}

// void Result::setStatement(Statement* statement)
// {
//     this->statement = statement;
// }

// Statement* Result::getStatement()
// {
//     return statement;
// }