/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Shapes
*/

#ifndef SHAPES_HPP_
#define SHAPES_HPP_

#include <string>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

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
