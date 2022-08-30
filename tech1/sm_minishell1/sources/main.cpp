/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_shell.hpp"
#include "Fork.hpp"

int test(void * data)
{
    std::string *str = (std::string *)data;
    std::cout << *str << std::endl;
    return 1;
}

int main()
{
    std::string * data = new std::string("test");
    Fork * fork = new Fork(data, test);
    fork->process();
    std::cout << fork->getStatus() << std::endl;
    return 0;
}