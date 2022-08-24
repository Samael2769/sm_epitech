/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_screensaver
*/

#ifndef SM_SCREENSAVER_HPP_
#define SM_SCREENSAVER_HPP_

#include "sfml.hpp"

class sm_screensaver {
    public:
        sm_screensaver();
        ~sm_screensaver();
        void run();
        void update();
    protected:
    private:
        sf::RenderWindow *_window;
};

#endif /* !SM_SCREENSAVER_HPP_ */
