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
    std::cout << "Duck created" << std::endl;
    life = 1 * level;
    speed = 10 * level;
    current = 0;
    texture.loadFromFile("assets/duck.png");
    switch (type) {
        case 0:
            duck.push_back(sf::Sprite(texture, sf::IntRect(95, 170, 90, 100)));
            duck.push_back(sf::Sprite(texture, sf::IntRect(420, 170, 90, 100)));
            //duck.push_back(std::make_pair(sf::Texture(), sf::Sprite()));
            //duck[0].first.loadFromFile("assets/duck.png");
            //duck[0].second.setTexture(duck[0].first);
            //duck[0].second.setTextureRect(sf::IntRect(95, 170, 90, 100));
            //duck.push_back(std::make_pair(sf::Texture(), sf::Sprite()));
            //duck[1].second.setTexture(duck[0].first);
            //duck[1].second.setTextureRect(sf::IntRect(420, 170, 90, 100));
            break;
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