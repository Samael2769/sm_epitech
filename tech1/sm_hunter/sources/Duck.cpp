/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Duck
*/

#include "Duck.hpp"
#include <iostream>

// 1129 - 394

Duck::Duck(int type, int level)
{
    life = 1 * level;
    speed = 10 * level;
    current = 0;
    texture.loadFromFile("assets/duck.png");
    death.loadFromFile("assets/explosion.png");
    switch (type) {
        case 0:
            duck.push_back(sf::Sprite(texture, sf::IntRect(95, 170, 100, 100)));
            duck.push_back(sf::Sprite(texture, sf::IntRect(420, 170, 90, 100)));
            duck.push_back(sf::Sprite(death));
            depX = -1;
            depY = -1;
            pos = sf::Vector2f(800, 600);
            break;
        case 1:
            duck.push_back(sf::Sprite(texture, sf::IntRect(190, 170, 100, 100)));
            duck.push_back(sf::Sprite(texture, sf::IntRect(285, 170, 100, 100)));
            duck.push_back(sf::Sprite(death));
            depX = 1;
            depY = -1;
            pos = sf::Vector2f(0, 600);
            break;
        case 2:
            duck.push_back(sf::Sprite(texture, sf::IntRect(525, 170, 100, 100)));
            duck.push_back(sf::Sprite(texture, sf::IntRect(940, 170, 100, 100)));
            duck.push_back(sf::Sprite(death));
            depX = -1;
            depY = 0;
            pos = sf::Vector2f(1000, 200);
            break;
        case 3:
            duck.push_back(sf::Sprite(texture, sf::IntRect(660, 170, 100, 100)));
            duck.push_back(sf::Sprite(texture, sf::IntRect(797, 170, 100, 100)));
            duck.push_back(sf::Sprite(death));
            depX = 1;
            depY = 0;
            pos = sf::Vector2f(0, 200);
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
    if (current != 2) {
        current++;
        if (current > 1)
            current = 0;
    }
}

void Duck::move()
{
    for (int i = 0; i < duck.size(); i++) {
        duck[i].move(depX * speed, depY * speed);
        pos = duck[i].getPosition();
    }
}