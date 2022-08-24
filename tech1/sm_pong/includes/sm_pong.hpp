/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_pong
*/

#ifndef SM_PONG_HPP_
#define SM_PONG_HPP_

#include "sfml.hpp"
#include <vector>
#include <iostream>
#include <utility>
#include <string>

class sm_pong {
    public:
        sm_pong();
        ~sm_pong();
        void run();
        void update();
    protected:
    private:
        std::pair<sf::Texture, sf::Sprite> _background;
        std::vector<sf::RectangleShape> _paddles;
        sf::CircleShape _ball;
        sf::RenderWindow *_window;
        int _speed;
        int _mulplicatorX;
        int _mulplicatorY;
        int scoreP1;
        int scoreP2;
};

#endif /* !SM_PONG_HPP_ */
