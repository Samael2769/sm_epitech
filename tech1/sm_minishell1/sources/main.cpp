/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_shell.hpp"

int main(int ac, char **av, char **env)
{
    sm_shell shell(env);
    shell.run();
    return 0;
}