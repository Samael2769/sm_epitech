/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_radar
*/

#ifndef SM_RADAR_HPP_
#define SM_RADAR_HPP_

#include "sfml.hpp"

class sm_radar {
    public:
        sm_radar();
        ~sm_radar();
        void run();
    protected:
    private:
        sf::RenderWindow * window;
};

#endif /* !SM_RADAR_HPP_ */
