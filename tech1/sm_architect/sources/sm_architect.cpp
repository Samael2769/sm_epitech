/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_architect
*/

#include "sm_architect.hpp"

sm_architect::sm_architect()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "SM ARCHITECT");
}

sm_architect::~sm_architect()
{
    
}

void sm_architect::run()
{
    while (window->isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
        window->clear();
        for (auto &shape : shapes)
            window->draw(*shape.shape);
        window->display();
    }
}