/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include "bsq.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage: ./bsq file" << std::endl;
        return (84);
    }
    bsq bsq;
    std::string line;
    std::ifstream myfile (av[1]);
    int i = 0;
    if (myfile.is_open()) {
        while(getline(myfile,line)) {
            if (i == 0) {
                bsq.rows = std::stoi(line);
                ++i;
                continue;
            }
            bsq.map.push_back(line);
            ++i;
        }
        myfile.close();
    }
    else {
        std::cout << "Unable to open file" << std::endl;
        return 84;
    }
    bsq.cols = bsq.map[0].size();
    bsq.findMax();
    bsq.fillMap();
    bsq.printMap();
    return 0;
}