/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_screensaver
*/

#ifndef SM_SCREENSAVER_HPP_
#define SM_SCREENSAVER_HPP_

#include "sfml.hpp"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>

class sm_screensaver {
    public:
        sm_screensaver();
        ~sm_screensaver();
        void run();
        void update();
    protected:
    private:
        sf::RenderWindow *_window;
        std::vector<sf::Shape *> _shapes;
};

#endif /* !SM_SCREENSAVER_HPP_ */
