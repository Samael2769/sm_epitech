/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_screensaver.hpp"

int main()
{
    srand(time(NULL));
    sm_screensaver screensaver;
    screensaver.run();
    return 0;
}