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
    result += r.result + "\n";
    error += r.error + "\n";
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

void Result::printError()
{
    if (is_error)
    {
        std::cout << error << std::endl;
    }
}
// void Result::setStatement(Statement* statement)
// {
//     this->statement = statement;
// }

// Statement* Result::getStatement()
// {
//     return statement;
// }