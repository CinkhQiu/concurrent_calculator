#include "Calculator.h"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <stack>
#include <vector>
#include <string>

// 一个仅支持整数 + - * / 的简化表达式求值器
int Calculator::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.size() != 3)
        throw std::runtime_error("Only format 'a <op> b' is supported");

    int lhs = std::stoi(tokens[0]);
    std::string op = tokens[1];
    int rhs = std::stoi(tokens[2]);

    if (op == "+") return lhs + rhs;
    if (op == "-") return lhs - rhs;
    if (op == "*") return lhs * rhs;
    if (op == "/") {
        if (rhs == 0) throw std::runtime_error("Division by zero");
        return lhs / rhs;
    }

    throw std::runtime_error("Unknown operator: " + op);
}