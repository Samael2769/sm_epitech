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
#include "Wasp.hpp"
#include <fstream>

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
        float map_time;
        bool _MoveRight;
        bool _MoveLeft;
        std::vector<std::string> _map;
        int map_iterator;
        std::vector<Wasp *> _enemies;
        int cnt;
};

#endif /* !SM_RUNNER_HPP_ */
