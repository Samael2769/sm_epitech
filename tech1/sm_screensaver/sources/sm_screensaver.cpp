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
    _window->setFramerateLimit(60);
}

sm_screensaver::~sm_screensaver()
{
    
}

void sm_screensaver::update()
{
    int nb = rand() % 10;
    for (int i = 0; i < nb; i++) {
        int type = rand() % 3;
        switch (type) {
            case 0:
                _shapes.push_back(new sf::CircleShape(rand() % 100, rand() % 100));
                break;
            case 1:
                _shapes.push_back(new sf::RectangleShape(sf::Vector2f(rand() % 100, rand() % 100)));
                break;
            case 2:
                _shapes.push_back(new sf::ConvexShape(rand() % 100));
                break;
        }
        _shapes.back()->setPosition(rand() % 800, rand() % 600);
        _shapes.back()->setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        _shapes.back()->setOutlineColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    }
    for (int i = 0; i < _shapes.size(); i++) {
        int r1 = rand() % 2;
        int r2 = rand() % 2;
        int d1 = rand() % 10;
        int d2 = rand() % 10;
        if (r1 == 0)
            d1 *= -1;
        if (r2 == 0)
            d2 *= -1;
        _shapes[i]->move(d1, d2);
    }
}

void sm_screensaver::run()
{
    sf::Clock clock;
    float elapsed = 0.f;
    float dt;
    while (_window->isOpen()) {
        _window->clear();
        dt = clock.restart().asMicroseconds();
        elapsed += dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window->close();
        if (elapsed >= 100000.f)
            update();
        if (elapsed >= 10000000.f) {
            _shapes.clear();
            clock.restart();
            elapsed = 0.f;
        }
        for (int i = 0; i < _shapes.size(); i++)
            _window->draw(*_shapes[i]);
        _window->display();
    }
}