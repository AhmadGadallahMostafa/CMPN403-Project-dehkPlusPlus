#pragma once 
#include <string>
#include<iostream>
class Result
{
private:
    std::string result;
    std::string error;
    bool is_error;
    //Statement* statement;
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
    void printError();
    // void setStatement(Statement* statement);
    // Statement* getStatement();
};

