/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_pushswap
*/

#include "sm_pushswap.hpp"
#include <algorithm>

sm_pushswap::sm_pushswap(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        _tab.push_back(atoi(av[i]));
    }
}

sm_pushswap::~sm_pushswap()
{
    
}

void sm_pushswap::sort()
{
    std::sort(_tab.begin(), _tab.end());
}

void sm_pushswap::print()
{
    for (int i = 0; i < _tab.size(); i++) {
        std::cout << _tab[i] << " ";
    }
    std::cout << std::endl;
}