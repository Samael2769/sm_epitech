/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_navy.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    sm_navy navy;
    if (ac == 2) {
        navy.setType(1);
        navy.setBoatFile(av[1]);
    } else {
        navy.setType(2);
        navy.setBoatFile(av[2]);
    }
    navy.run();
    return 0;
}