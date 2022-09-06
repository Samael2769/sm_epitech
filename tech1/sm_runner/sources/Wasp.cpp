/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Wasp
*/

#include "Wasp.hpp"

Wasp::Wasp(bool type, float x, float y)
{
    _type = type;
    if (type == true) {
        _wasp.first = new sf::Texture();
        _wasp.first->loadFromFile("assets/enemi.png");
        _wasp.second = new sf::Sprite(*_wasp.first);
        _wasp.second->setPosition(x, y);
        _wasp.second->setScale(0.05, 0.05);
    } else {
        _wasp.first = new sf::Texture();
        _wasp.first->loadFromFile("assets/boss.png");
        _wasp.second = new sf::Sprite(*_wasp.first);
        _wasp.second->setPosition(x, y);
        _wasp.second->setScale(0.2, 0.2);
    }
}

Wasp::~Wasp()
{
}

void Wasp::update()
{
    _wasp.second->move(-20, 0);
}