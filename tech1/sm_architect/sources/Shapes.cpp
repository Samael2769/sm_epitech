/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Shapes
*/

#include "Shapes.hpp"

Shapes::Shapes(sf::Shape *shape, std::string name)
{
    this->shape = shape;
    this->name = name;
}

Shapes::~Shapes()
{
}
