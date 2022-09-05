/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_radar
*/

#include "sm_radar.hpp"

sm_radar::sm_radar()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 500), "Sm Radar");
}

sm_radar::~sm_radar()
{
    
}

void sm_radar::run()
{
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
        window->clear();
        window->display();
    }
}