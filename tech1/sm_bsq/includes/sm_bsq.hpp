/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_bsq
*/

#ifndef SM_BSQ_HPP_
#define SM_BSQ_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>

class sm_bsq {
    public:
        sm_bsq(std::string path);
        void run();
        void load_map();
        void find_bsq();
        bool isSquare(int x, int y, int size);
        void biggestSquareAtCoords(int x, int y);
        void print_map();
        ~sm_bsq();
    protected:
    private:
        std::string _path;
        std::pair<int, int> _size;
        std::vector<std::string> _map;
        std::pair<int, int> _pos_square;
        int _size_square;
};

#endif /* !SM_BSQ_HPP_ */
