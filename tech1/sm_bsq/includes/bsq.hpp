/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** bsq
*/

#ifndef BSQ_HPP_
#define BSQ_HPP_

#include <vector>
#include <string>

class bsq {
    public:
        std::vector<std::string> map;
        std::vector<int> maxPos;
        int sizeMax;
        int cols;
        int rows;

        void printMap();
        void findMax();
        int checkSquare(int i, int j);
        bool isSquare(int i, int j, int size);
        void fillMap();
    protected:
    private:
};

#endif /* !BSQ_HPP_ */
