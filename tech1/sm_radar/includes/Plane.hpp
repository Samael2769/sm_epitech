/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "sfml.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <cmath>

class Plane {
    public:
        Plane(sf::Vector2f pos, sf::Vector2f dest);
        ~Plane();
        void update();
        void draw(sf::RenderWindow *window);
        int collide(Plane &other);
        bool dir_change;
        float getSpeed();
    protected:
    private:
        std::pair<sf::Texture *, sf::Sprite *> sprite;
        sf::CircleShape *zone;
        sf::CircleShape *danger;
        sf::Vector2f dest;
};

#endif /* !PLANE_HPP_ */
