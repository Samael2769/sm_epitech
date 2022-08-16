/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_hunter
*/

#ifndef SM_HUNTER_HPP_
#define SM_HUNTER_HPP_

#include <iostream>

#include <utility>

#include "Duck.hpp"

class sm_hunter {
    public:
        sm_hunter();
        ~sm_hunter();
        void run();
    protected:
    private:
        sf::RenderWindow *window;
        std::pair<sf::Texture, sf::Sprite> background;
        std::vector<Duck *> ducks;
};

#endif /* !SM_HUNTER_HPP_ */
