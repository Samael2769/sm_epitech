/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_world.hpp"

int main()
{
    int intMap[Max_Y][Max_X] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    sm_world *world = new sm_world(800, 600, intMap);
    world->create2DMap(intMap);
    world->run();
    return 0;
}