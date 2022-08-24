/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_screensaver
*/

#include "sm_screensaver.hpp"

sm_screensaver::sm_screensaver()
{
    _window = new sf::RenderWindow(sf::VideoMode(800, 600), "Screensaver");
}

sm_screensaver::~sm_screensaver()
{
    
}

void sm_screensaver::update()
{
    
}

void sm_screensaver::run()
{
    while (_window->isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window->close();
        _window->clear();
        _window->display();
    }
}