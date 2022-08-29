/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Shapes
*/

#ifndef SHAPES_HPP_
#define SHAPES_HPP_

#include "sfml.hpp"
#include <string>
#include <iostream>
#include <vector>

class Shapes {
    public:
        Shapes(sf::Shape *shape, std::string name);
        ~Shapes();

        sf::Shape *shape; 
    protected:
    private:
        std::string name;
};

#endif /* !SHAPES_HPP_ */
