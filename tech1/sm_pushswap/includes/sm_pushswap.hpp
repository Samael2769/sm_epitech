/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_pushswap
*/

#ifndef SM_PUSHSWAP_HPP_
#define SM_PUSHSWAP_HPP_

#include <iostream>
#include <vector>

class sm_pushswap {
    public:
        sm_pushswap(int ac, char **av);
        ~sm_pushswap();
        void sort();
        void print();
    protected:
    private:
        std::vector<int> _tab;
};

#endif /* !SM_PUSHSWAP_HPP_ */
