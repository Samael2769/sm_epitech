/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_pushswap.hpp"

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cout << "Usage: ./push_swap [nbr1] [nbr2] [nbr3] ..." << std::endl;
        return (0);
    }
    sm_pushswap pushswap(ac, av);
    pushswap.sort();
    pushswap.print();
    return (0);
}