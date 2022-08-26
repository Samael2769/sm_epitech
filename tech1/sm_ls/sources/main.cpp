/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_ls.hpp"

int main(int ac, char **av)
{
    sm_ls ls;
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-')
            ls.add_opt(av[i]);
        else
            ls.add_path(av[i]);
    }
    try {
        ls.run();
    } catch (std::exception &e) {
        std::cerr << "sm_ls: " << e.what() << std::endl;
    }
}