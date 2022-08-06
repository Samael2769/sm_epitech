/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Calculator
*/

#include "Calculator.hpp"

Calculator::Calculator(std::string &a)
{
    calc = a;
}

Calculator::~Calculator()
{
}

std::string Calculator::do_op()
{
    std::string res = add("1", "2");
    return res;
}

std::string Calculator::add(const std::string &a, const std::string &b)
{
    return a + b;
}

std::string Calculator::sub(const std::string &a, const std::string &b)
{
    return a + b;
}

std::string Calculator::mul(const std::string &a, const std::string &b)
{
    return a + b;
}

std::string Calculator::div(const std::string &a, const std::string &b)
{
    return a + b;
}

std::string Calculator::mod(const std::string &a, const std::string &b)
{
    return a + b;
}