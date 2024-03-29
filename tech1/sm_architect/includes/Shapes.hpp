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
        std::string getName() { return name; };
        void move(std::string x, std::string y) {
            shape->setPosition(std::stoi(x), std::stoi(y));
        };
        void show_name(sf::RenderWindow *window);
        void drag(sf::RenderWindow *window);
        void Trigger() { isDragged = true; }
        void Untrigger() { isDragged = false; }
        bool getTrigger() { return isDragged; }
        sf::Shape *shape; 
    protected:
    private:
        std::string name;
        bool isDragged;
};

#endif /* !SHAPES_HPP_ */
