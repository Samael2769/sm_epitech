/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Duck
*/

#ifndef DUCK_HPP_
#define DUCK_HPP_

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Duck {
    public:
        Duck(int type, int level);
        ~Duck();
        void update();
        void move();
        int current;
        sf::Texture texture;
        sf::Texture death;
        std::vector<sf::Sprite> duck;
        int speed;
        int life;
        int depX;
        int depY;
        sf::Vector2f pos;
    protected:
    private:
};

#endif /* !DUCK_HPP_ */
