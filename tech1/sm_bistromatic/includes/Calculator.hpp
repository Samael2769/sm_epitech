/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Calculator
*/

#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_

#include <string>
#include <iostream>

class Calculator {
    public:
        Calculator(std::string &a);
        ~Calculator();
        std::string do_op();
        std::string add(const std::string &, const std::string &);
        std::string sub(const std::string &, const std::string &);
        std::string mul(const std::string &, const std::string &);
        std::string div(const std::string &, const std::string &);
        std::string mod(const std::string &, const std::string &);
    protected:
    private:
        std::string calc;
};

#endif /* !CALCULATOR_HPP_ */
