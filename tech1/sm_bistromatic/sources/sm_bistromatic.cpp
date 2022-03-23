/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include "sm_bistromatic.hpp"

int engine(sm_bistromatic &bistro)
{
    std::cout << infin_mult("12", "2") << std::endl;
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && std::string(av[1]) == "-h") {
        std::cout << "Hello World" << std::endl;
        return 0;
    } else if (ac == 4) {
        sm_bistromatic bistro(std::stoi(av[3]), av[1], av[2]);
        std::getline(std::cin, bistro.calc);
        if (engine(bistro) != 0)
            return 84;
        return 0;
    }
    return 84;
}