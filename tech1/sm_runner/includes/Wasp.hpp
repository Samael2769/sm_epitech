/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** wasp
*/

#ifndef WASP_HPP_
#define WASP_HPP_

#include "sfml.hpp"

class Wasp {
    public:
        Wasp(bool type, float x, float y);
        ~Wasp();
        void update();
        std::pair<sf::Texture * , sf::Sprite *> _wasp;
        bool _type;
    protected:
    private:
};


#endif /* !WASP_HPP_ */
