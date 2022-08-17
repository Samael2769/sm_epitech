/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Duck
*/

#include "Duck.hpp"
#include <iostream>

// 1129 - 394

Duck::Duck(int type, int level, sf::Vector2f pos)
{
    std::cout << "Duck created" << std::endl;
    life = 1 * level;
    speed = 20 * level;
    current = 0;
    texture.loadFromFile("assets/duck.png");
    this->pos = pos;
    switch (type) {
        case 0:
            duck.push_back(sf::Sprite(texture, sf::IntRect(95, 170, 100, 100)));
            duck.push_back(sf::Sprite(texture, sf::IntRect(420, 170, 90, 100)));
            depX = -1;
            depY = -1;
            break;
        case 1:
            duck.push_back(sf::Sprite(texture, sf::IntRect(190, 170, 100, 100)));
            duck.push_back(sf::Sprite(texture, sf::IntRect(285, 170, 100, 100)));
            depX = 1;
            depY = -1;
            break;
        case 2:
            duck.push_back(sf::Sprite(texture, sf::IntRect(525, 170, 100, 100)));
            duck.push_back(sf::Sprite(texture, sf::IntRect(940, 170, 100, 100)));
            depX = -1;
            depY = 0;
            break;
        case 3:
            duck.push_back(sf::Sprite(texture, sf::IntRect(660, 170, 100, 100)));
            duck.push_back(sf::Sprite(texture, sf::IntRect(797, 170, 100, 100)));
            depX = 1;
            depY = 0;
            break;
        default:
            throw std::runtime_error("Invalid duck type");
    }
    for (int i = 0; i < duck.size(); i++) {
        duck[i].setPosition(pos.x, pos.y);
    }
}

Duck::~Duck()
{
}

void Duck::update()
{
    current++;
    if (current > 1)
        current = 0;
}

void Duck::move()
{
    for (int i = 0; i < duck.size(); i++) {
        duck[i].move(depX * speed, depY * speed);
    }
}