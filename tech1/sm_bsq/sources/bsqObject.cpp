/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** bsqObject
*/

#include "bsq.hpp"
#include <iostream>

void bsq::printMap()
{
    for (int i = 0; i < this->rows; i++)
        std::cout << this->map[i] << std::endl;
}

//find the biggest square of "." in the map with obstacles "o"
void bsq::findMax()
{
    int max = 0;
    int pos[2];
    pos[0] = 0;
    pos[1] = 0;

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            if (this->map[i][j] == '.') {
                int tmp = checkSquare(i, j);
                if (tmp > max) {
                    max = tmp;
                    pos[0] = i;
                    pos[1] = j;
                }
            }
        }
    }
    this->sizeMax = max;
    this->maxPos.push_back(pos[0]);
    this->maxPos.push_back(pos[1]);
}

bool bsq::isSquare(int i, int j, int size)
{
    for (int k = i; k < i + size; k++) {
        if (k >= this->rows)
            return false;
        for (int l = j; l < j + size; l++) {
            if (l >= this->cols)
                return false;
            if (this->map[k][l] != '.')
                return false;
        }
    }
    return true;
}

int bsq::checkSquare(int i, int j)
{
    int size = 0;
    while (this->isSquare(i, j, size)) {
        size++;
    }
    return size - 1;
}

void bsq::fillMap()
{
    for (int i = this->maxPos[0]; i < this->maxPos[0] + this->sizeMax; i++) {
        for (int j = this->maxPos[1]; j < this->maxPos[1] + this->sizeMax; j++) {
            this->map[i][j] = 'x';
        }
    }
}