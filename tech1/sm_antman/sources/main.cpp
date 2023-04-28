/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_antman.hpp"
#include "sm_giantman.hpp"

int main(int ac, char **av)
{
    if (ac != 5) {
        std::cout << "Usage: ./antman (-c compress_file) (-d decompress_file) -t file_type" << std::endl;
        return 0;
    }
    if (av[1][1] == 'c')
        sm_antman antman(av[2], std::stoi(av[4]));
    if (av[1][1] == 'd')
        sm_giantman giantman(av[2], std::stoi(av[4]));
    return 0;
}