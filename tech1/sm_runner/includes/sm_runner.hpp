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

//3500 1198

class sm_runner {
    public:
        sm_runner();
        ~sm_runner();
        void run();
        void update();
    protected:
    private:
        sf::RenderWindow * window;
        std::vector<std::pair<sf::Texture * , sf::Sprite *>> _parallax;
        std::vector<std::pair<sf::Texture * , sf::Sprite *>> _player;
        int curr;
        bool _isJumping;
        float elapsed;
        float elapsed2;
        bool _MoveRight;
        bool _MoveLeft;
};

#endif /* !SM_RUNNER_HPP_ */
