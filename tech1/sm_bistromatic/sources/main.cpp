/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_bistromatic.hpp"


static const std::string usage = {
    "USAGE\n"\
    "    ./sm_bistromatic op base_nb base_op\n"\
    "base_nb: 0123456789\n"\
    "base_op: +-*/%\n"\
    "DESCRIPTION\n"\
};

int main(int ac, char **av)
{
    if (ac != 4) {
        std::cout << usage;
        return (84);
    }
    sm_bistromatic bistromatic(av[1], av[2], av[3]);
    bistromatic.run();
}