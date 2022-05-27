#pragma once 
#include <string>

class Result
{
private:
    std::string result;
    std::string error;
    bool is_error;
public:
    Result(std::string r, std::string error,bool isError)
    {
        this->result = r;
        this->error = error;
        this->is_error = isError;
    }  
    std::string getResult();
    bool isError();
    void addResult(Result& r);
    void setError(std::string error);
    void setResult(std::string result);
};

