/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_bsq
*/

#include "sm_bsq.hpp"

sm_bsq::sm_bsq(std::string path) : _path(path)
{
    _size_square = 0;
}

sm_bsq::~sm_bsq()
{
    
}

void sm_bsq::run()
{
    load_map();
    find_bsq();
    print_map();
}

void sm_bsq::load_map()
{
    std::ifstream file(_path);
    std::string line;
    int i = 0;
    
    if (!file.is_open())
        throw std::runtime_error("File not found");
    while (std::getline(file, line)) {
        if (i != 0)
            _map.push_back(line);
        i++;
    }
    _size.first = _map[0].size() - 1;
    _size.second = i - 1;
}

//print map with x at square coords
void sm_bsq::print_map()
{
    for (int i = 0; i < _size.second; i++) {
        for (int j = 0; j < _size.first; j++) {
            if (j >= _pos_square.second && j < _pos_square.second + _size_square && i >= _pos_square.first && i < _pos_square.first + _size_square)
                std::cout << "x";
            else
                std::cout << _map[i][j];
                
        }
        std::cout << std::endl;
    }
}

bool sm_bsq::isSquare(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        if (i >= _size.second)
            return false;
        for (int j = y; j < y + size; j++) {
            if (j >= _size.first)
                return false;
            if (_map[i][j] != '.')
                return false;
        }
    }
    return true;
}

void sm_bsq::biggestSquareAtCoords(int x, int y) {
    int size = _size_square;
    while(isSquare(x, y, size + 1)) {
        size++;
    }
    if (size > _size_square) {
        _size_square = size;
        _pos_square.first = x;
        _pos_square.second = y;
    }
}

void sm_bsq::find_bsq() {
    for (int i = 0; i < _size.second; i++) {
        for (int j = 0; j < _size.first; j++) {
            biggestSquareAtCoords(i, j);
        }
    }
    std::cout << "The biggest square has a size of " << _size_square << " and is located at " << _pos_square.first << "," << _pos_square.second << std::endl;
}