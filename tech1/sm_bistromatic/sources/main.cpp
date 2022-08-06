/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_bistromatic.hpp"

int main(int ac, char **av)
{
    sm_bistromatic bistromatic(av[0]);
    bistromatic.run();
}