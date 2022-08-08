/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_bistromatic
*/

#ifndef SM_BISTROMATIC_HPP_
#define SM_BISTROMATIC_HPP_

#include "Calculator.hpp"

class sm_bistromatic {
    public:
        sm_bistromatic(std::string op, std::string base_nb, std::string base_op);
        ~sm_bistromatic();
        void run();
    protected:
    private:
        Calculator calc;
        std::string base_nb;
        std::string base_op;
};

#endif /* !SM_BISTROMATIC_HPP_ */
