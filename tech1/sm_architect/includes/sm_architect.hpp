/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_architect
*/

#ifndef SM_ARCHITECT_HPP_
#define SM_ARCHITECT_HPP_

#include "Shapes.hpp"

class sm_architect {
    public:
        sm_architect();
        ~sm_architect();
        void run();
    protected:
    private:
        sf::RenderWindow *window;
        std::vector<Shapes> shapes;
};

#endif /* !SM_ARCHITECT_HPP_ */
