/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_radar
*/

#ifndef SM_RADAR_HPP_
#define SM_RADAR_HPP_

#include "sfml.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include "Plane.hpp"

class sm_radar {
    public:
        sm_radar();
        ~sm_radar();
        void run();
    protected:
    private:
        sf::RenderWindow * window;
        std::vector<std::pair<sf::Texture *, sf::Sprite *>> sprites;
        std::vector<Plane *> planes;
};

#endif /* !SM_RADAR_HPP_ */
