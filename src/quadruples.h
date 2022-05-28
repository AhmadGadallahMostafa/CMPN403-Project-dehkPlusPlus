#pragma once
#include <string>

#include <unordered_map>
using namespace std;

unordered_map<string, int> operators;
operators.insert(pair<string, int>("=", 0));
operators.insert(pair<string, int>("+", 1));
operators.insert(pair<string, int>("-", 2));
operators.insert(pair<string, int>("*", 3));
operators.insert(pair<string, int>("/", 4));
operators.insert(pair<string, int>("%", 5));
operators.insert(pair<string, int>("^", 6));
operators.insert(pair<string, int>("&&", 7));
operators.insert(pair<string, int>("||", 8));
operators.insert(pair<string, int>("!", 9));
operators.insert(pair<string, int>("==", 10));
operators.insert(pair<string, int>("!=", 11));
operators.insert(pair<string, int>("<", 12));
operators.insert(pair<string, int>("<=", 13));
operators.insert(pair<string, int>(">", 14));
operators.insert(pair<string, int>(">=", 15));



// void printQuadruple(string op, string left, string right, string result)
// {
//     int op_code = operators[op];
// switch(op_code) {
//   case x:
//     // code block
//     break;
//   case y:
//     // code block
//     break;
//   default:
//     // code block
// }
// }