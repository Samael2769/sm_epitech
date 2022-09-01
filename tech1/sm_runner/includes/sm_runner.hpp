/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_runner
*/

#ifndef SM_RUNNER_HPP_
#define SM_RUNNER_HPP_

#include "sfml.hpp"
#include <vector>
#include <utility>

class sm_runner {
    public:
        sm_runner();
        ~sm_runner();
        void run();
    protected:
    private:
        sf::RenderWindow * window;
        std::vector<std::pair<sf::Texture * , sf::Sprite *>> _parallax;
};

#endif /* !SM_RUNNER_HPP_ */
