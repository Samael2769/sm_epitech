/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_runner
*/

#include "sm_runner.hpp"
#include <iostream>

sm_runner::sm_runner()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 500), "Sm Runner");
    window->setFramerateLimit(60);
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
    _MoveLeft = false;
    _MoveRight = false;
    _isJumping = false;
    map_time = 0;
    elapsed = 0;
    elapsed2 = 0;

    std::ifstream file("assets/map");
    std::string line;
    while (std::getline(file, line)) {
        _map.push_back(line);
    }
    map_iterator = 0;
    cnt = 0;
}

sm_runner::~sm_runner()
{

}

void sm_runner::update()
{
    if (elapsed >= 100000) {
        _parallax[1].second->move(-2, 0);
        _parallax[2].second->move(-5, 0);
        _parallax[3].second->move(-10, 0);
        _parallax[4].second->move(-20, 0);
        for (int i = 0; i < _enemies.size(); i++) {
            _enemies[i]->update();
            if (_enemies[i]->_wasp.second->getPosition().x < 0) {
                _enemies.erase(_enemies.begin() + i);
            }
            if (_enemies[i]->_wasp.second->getGlobalBounds().intersects(_player[curr].second->getGlobalBounds())) {
                std::cout << "You died" << std::endl;
                exit(0);
            }
        }
        elapsed = 0;
    }
    if (_parallax[1].second->getPosition().x < -800)
        _parallax[1].second->setPosition(800, 0);
    if (_parallax[2].second->getPosition().x < -800)
        _parallax[2].second->setPosition(0, 0);
    if (_parallax[3].second->getPosition().x < -800)
        _parallax[3].second->setPosition(0, 0);
    if (_parallax[4].second->getPosition().x < -800)
        _parallax[4].second->setPosition(0, 0);
    if (elapsed2 >= 10000) {
        curr++;
        if (curr >= 4)
            curr = 0;
        elapsed2 = 0;
    }
    if (_isJumping && _player[curr].second->getPosition().y > 0)
        for (int i = 0; i < 4; i++)
            _player[i].second->move(0, -10);
    if (!_isJumping && _player[curr].second->getPosition().y < 500 - 1198 * 0.1)
        for (int i = 0; i < 4; i++)
            _player[i].second->move(0, 20);
    if (_MoveLeft && _player[curr].second->getPosition().x >= 0)
        for (int i = 0; i < 4; i++)
            _player[i].second->move(-15, 0);
    if (_MoveRight && _player[curr].second->getPosition().x <= 800)
        for (int i = 0; i < 4; i++)
            _player[i].second->move(15, 0);

    if (map_time >= 2000000) {
        for (int i = 0; i < _map.size(); ++i) {
            if(_map[i][map_iterator] == 'o') {
                Wasp * wasp = new Wasp(true, 800, i * 100);
                _enemies.push_back(wasp);
            }
            if(_map[i][map_iterator] == 'p') {
                Wasp * wasp = new Wasp(false, 800, i * 100);
                _enemies.push_back(wasp);
                cnt = 1;
            }
            if (_map[i][map_iterator] == '!' && cnt == 1) {
                for (int j = 0; j < _enemies.size(); j++) {
                    if (_enemies[j]->_type == false) {
                        cnt = 1;
                        break;
                    }
                    cnt = 3;
                }
                if (cnt == 3) {
                    std::cout << "You won" << std::endl;
                    exit(0);
                }
            }
        }
        map_iterator++;
        map_time = 0;
    }
}

void sm_runner::run()
{
    sf::Clock clock;
    float dt = 0;
    elapsed = 0;
    elapsed2 = 0;
    while (window->isOpen()) {
        sf::Event event;
        dt = clock.restart().asMicroseconds();
        elapsed += dt;
        elapsed2 += dt;
        map_time += dt;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space && _player[curr].second->getPosition().y >= 0) {
                    _isJumping = true;
                }
                if (event.key.code == sf::Keyboard::D && _player[curr].second->getPosition().x < 800)
                    _MoveRight = true;
                if (event.key.code == sf::Keyboard::Q && _player[curr].second->getPosition().x >= 0)
                    _MoveLeft = true;
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    _isJumping = false;
                }
                if (event.key.code == sf::Keyboard::D)
                    _MoveRight = false;
                if (event.key.code == sf::Keyboard::Q)
                    _MoveLeft = false;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
        window->clear();
        update();
        for (auto &i : _parallax) {
            window->draw(*i.second);
        }
        for (auto &i : _enemies) {
            window->draw(*i->_wasp.second);
        }
        window->draw(*_player[curr].second);
        window->display();
    }
}