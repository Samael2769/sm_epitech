/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_tetris
*/

#ifndef SM_TETRIS_HPP_
#define SM_TETRIS_HPP_

#include <ncurses.h>
#include <ctime>
#include <vector>
#include <map>
#include <utility>
#include <cmath>

class blocks {
    public:
        enum blockType {
            T,
            L,
            ZIGZAG,
            SQUARE,
            LINE,
        };
        blocks(blockType type, int x, int y, int speed);
        ~blocks();
        int get_type() { return _type;}
        int get_x() { return _x;}
        int get_y() { return _y;}
        void update();
        void draw(WINDOW * win);
        void move(bool isright);
        bool checkCollision(WINDOW *win);
        bool isInPos(int x, int y);
        void rotate();
        int size;
        bool isRotated;
        blockType _type;
        int _x;
        int _y;
    protected:
    private:
        std::vector<std::pair<std::pair<int, int>, char>> _blocks;
        int speed;

};

class sm_tetris {
    public:
        sm_tetris();
        ~sm_tetris();
        void run();
        void drawWalls();
        bool winCheck();
        bool loseCheck(WINDOW *win);
    protected:
    private:
        float _speed;
        std::map<std::string, WINDOW *> _windows;
        std::vector<blocks> _staticBlocks;
        //blocks _actualBlock;
        clock_t _start;
        int winNb;
};

#endif /* !SM_TETRIS_HPP_ */
