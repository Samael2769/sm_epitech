/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_bsq.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    sm_bsq bsq(av[1]);
    try {
        bsq.run();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}