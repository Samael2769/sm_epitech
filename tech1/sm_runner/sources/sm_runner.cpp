/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_runner
*/

#include "sm_runner.hpp"

sm_runner::sm_runner()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 500), "Sm Runner");
    for (int i = 0; i < 5; i++) {
        sf::Texture * texture = new sf::Texture();
        sf::Sprite * sprite = new sf::Sprite();
        texture->loadFromFile("assets/" + std::to_string(i + 1) + ".png");
        sprite->setTexture(*texture);
        sprite->setPosition(0, 0);
        sprite->setScale(3, 3);
        _parallax.push_back(std::make_pair(texture, sprite));
    }
}

sm_runner::~sm_runner()
{
    
}

void sm_runner::run()
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
        for (auto &i : _parallax) {
            window->draw(*i.second);
        }
        window->display();
    }
}