/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_pong
*/

#include "sm_pong.hpp"
#include <cmath>

sm_pong::sm_pong()
{
    _background = std::make_pair(sf::Texture(), sf::Sprite());
    _background.first.loadFromFile("assets/background.png");
    _background.second.setTexture(_background.first);
    _background.second.setPosition(0, 0);
    _window = new sf::RenderWindow(sf::VideoMode(800, 600), "sm_Pong");
    _window->setMouseCursorVisible(false);
    _paddles.push_back(sf::RectangleShape(sf::Vector2f(100, 20)));
    _paddles[0].setPosition(40, 200);
    _paddles[0].setFillColor(sf::Color::White);
    _paddles[0].setOrigin(50, 10);
    _paddles[0].rotate(90);
    _paddles.push_back(sf::RectangleShape(sf::Vector2f(100, 20)));
    _paddles[1].setPosition(780, 200);
    _paddles[1].setOrigin(50, 10);
    _paddles[1].rotate(90);
    _paddles[1].setFillColor(sf::Color::White);
    _ball = sf::CircleShape(20);
    _ball.setOrigin(10, 10);
    _ball.setPosition(390, 280);
    _ball.setFillColor(sf::Color::White);
    _speed = 0;
    _mulplicatorX = 0;
    _mulplicatorY = 0;
    scoreP1 = 0;
    scoreP2 = 0;
}

sm_pong::~sm_pong()
{
    
}

//find if there is collision between the rectangle and the circle
bool collision(sf::RectangleShape &a, sf::CircleShape &b)
{
    if (a.getGlobalBounds().intersects(b.getGlobalBounds()))
        return true;
    return false;
}

void sm_pong::update()
{
    if (sf::Mouse::getPosition(*_window).x < 400)
        _paddles[0].setPosition(sf::Mouse::getPosition(*_window).x, sf::Mouse::getPosition(*_window).y);
    for (int i = 0; i < _paddles.size(); i++) {
        if (collision(_paddles[i], _ball)) {
            if (_mulplicatorX == 0) {
                if (i == 0)
                    _mulplicatorX = 1;
                else
                    _mulplicatorX = -1;
                if (_ball.getPosition().y < _paddles[i].getPosition().y)
                    _mulplicatorY = -1;
                else
                    _mulplicatorY = 1;
            }else
                _mulplicatorX = -_mulplicatorX;
            _speed+=1;
        }
    }
    if (_ball.getPosition().x < 0 ) {
        _ball.setPosition(390, 280);
        _paddles[1].setPosition(780, 200);
        _paddles[0].setPosition(40, 200);
        _speed = 0;
        scoreP2++;
    }
    if (_ball.getPosition().x > 800) {
        _ball.setPosition(390, 280);
        _paddles[0].setPosition(40, 200);
        _paddles[1].setPosition(780, 200);
        _speed = 0;
        scoreP1++;
    }
    if (_ball.getPosition().y >= 600 || _ball.getPosition().y <= 0) {
        _mulplicatorY = -_mulplicatorY;
        _speed -= 1;
    }
    int x = 0;
    int y = 0;
    if (_paddles[1].getPosition().y >= _ball.getPosition().y)
        y = -7;
    if (_paddles[1].getPosition().y <= _ball.getPosition().y)
        y = 7;
    if (_paddles[1].getPosition().x >= _ball.getPosition().x)
        x = -7;
    if (_paddles[1].getPosition().x <= _ball.getPosition().x)
        x = 7;
    if (!collision(_paddles[1], _ball)) {
        if(_paddles[1].getPosition().x > 400)
            _paddles[1].move(sf::Vector2f(x, y));
        else
            _paddles[1].move(sf::Vector2f(0, y));
    }
    _ball.move(sf::Vector2f(_speed * _mulplicatorX, _speed * _mulplicatorY));
}

void sm_pong::run()
{
    sf::Text scoreP1Text;
    sf::Text scoreP2Text;
    sf::Font font;
    font.loadFromFile("assets/font.ttf");
    scoreP1Text.setFont(font);
    scoreP2Text.setFont(font);
    scoreP1Text.setString(std::to_string(scoreP1));
    scoreP2Text.setString(std::to_string(scoreP2));
    scoreP1Text.setCharacterSize(50);
    scoreP2Text.setCharacterSize(50);
    scoreP1Text.setPosition(50, 50);
    scoreP2Text.setPosition(750, 50);
    while (_window->isOpen()) {
        _window->clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window->close();
        update();
        scoreP1Text.setString(std::to_string(scoreP1));
        scoreP2Text.setString(std::to_string(scoreP2));
        _window->draw(_background.second);
        for (auto &paddle : _paddles)
            _window->draw(paddle);
        _window->draw(_ball);
        _window->draw(scoreP1Text);
        _window->draw(scoreP2Text);
        _window->display();
        if (scoreP1 == 10) {
            std::cout << "Player 1 wins" << std::endl;
            _window->close();
        }
        if (scoreP2 == 10) {
            std::cout << "Player 2 wins" << std::endl;
            _window->close();
        }
    }
}