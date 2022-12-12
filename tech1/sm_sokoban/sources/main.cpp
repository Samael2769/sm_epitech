/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "mySokoban.hpp"

int main(int ac, char **av)
{
    mySokoban sokoban;
    sokoban.setMap(av[1]);
    sokoban.run();
    return 0;
}