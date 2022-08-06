/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_bistromatic
*/

#include "sm_bistromatic.hpp"

sm_bistromatic::sm_bistromatic(std::string op): calc(Calculator(op))
{
}

sm_bistromatic::~sm_bistromatic()
{
    
}

void sm_bistromatic::run()
{
    std::cout << calc.do_op() << std::endl;
}