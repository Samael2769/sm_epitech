/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_bistromatic
*/

#include "sm_bistromatic.hpp"

sm_bistromatic::sm_bistromatic(std::string op, std::string base_nb, std::string base_op): calc(Calculator(op))
{
    this->base_nb = base_nb;
    this->base_op = base_op;
}

sm_bistromatic::~sm_bistromatic()
{
    
}

void sm_bistromatic::run()
{
    try {
        calc.convertBase(base_nb, base_op);
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        exit(84);
    }
    std::cout << calc.do_op() << std::endl;
}