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
    sf::Texture * texture = new sf::Texture();
    texture->loadFromFile("assets/aigle.png");
    for (int i = 0; i < 4; ++i) {
        sf::Sprite * sprite = new sf::Sprite(*texture, sf::IntRect(875 * i, 0, 875, 1198));
        _player.push_back(std::make_pair(texture, sprite));
        _player[i].second->setPosition(0, 0);
        _player[i].second->setScale(0.1, 0.1);
    }
    curr = 0;
}

sm_runner::~sm_runner()
{

}

void sm_runner::update()
{
    _parallax[1].second->move(-2, 0);
    _parallax[2].second->move(-5, 0);
    _parallax[3].second->move(-10, 0);
    _parallax[4].second->move(-20, 0);
    if (_parallax[1].second->getPosition().x < -800)
        _parallax[1].second->setPosition(800, 0);
    if (_parallax[2].second->getPosition().x < -800)
        _parallax[2].second->setPosition(0, 0);
    if (_parallax[3].second->getPosition().x < -800)
        _parallax[3].second->setPosition(0, 0);
    if (_parallax[4].second->getPosition().x < -800)
        _parallax[4].second->setPosition(0, 0);
    curr++;
    if (curr == 4)
        curr = 0;
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
        update();
        for (auto &i : _parallax) {
            window->draw(*i.second);
        }
        window->draw(*_player[curr].second);
        window->display();
    }
}