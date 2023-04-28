/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_tetris
*/

#include "sm_tetris.hpp"

sm_tetris::sm_tetris()
{
    initscr();
    noecho();
    curs_set(0);
    _windows["main"] = stdscr;
    _windows["gameHandle"] = subwin(stdscr, LINES - 2, COLS - COLS / 3, 1, 1);
    _windows["game"] = subwin(stdscr, LINES - 4, COLS - COLS / 3 - 4, 2, 3);
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_WHITE, COLOR_WHITE);
}

sm_tetris::~sm_tetris()
{
    for (auto &it : _windows) {
        delwin(it.second);
    }
    endwin();
}

void sm_tetris::run()
{
    box(_windows["gameHandle"], ACS_VLINE, ACS_HLINE);
    nodelay(stdscr, TRUE);
    float deltaTime = 0;
    _speed = 0.5;
    _start = clock();
    int posX = 0;
    blocks block(blocks::T, 30, 0, 1);
    int score = 0;
    winNb = 200;
    blocks nextBlock = blocks((blocks::blockType)(std::rand() % 5), 55, LINES / 2 - 6, 1);
    while(1) {
        int c = getch();
        if (c == 'r')
            break;
        if (c == 'q')
            block.move(false);
        if (c == 'd')
            block.move(true);
        if (c == ' ')
            block.rotate();
        if (deltaTime > _speed) {
            wclear(_windows["game"]);
            if (winCheck()) {
                mvwprintw(_windows["game"], LINES / 2, COLS / 2 - 5, "You Win!");
                wrefresh(_windows["game"]);
                continue;
            }
            if (loseCheck(_windows["game"])) {
                mvwprintw(_windows["game"], LINES / 2, COLS / 2 - 5, "You Lose!");
                wrefresh(_windows["game"]);
                continue;
            }
            //mvwprintw(_windows["game"], posX, 20, "Hello World!");
            drawWalls();
            block.draw(_windows["game"]);
            nextBlock.draw(_windows["game"]);
            mvwprintw(_windows["game"], 0, 0, "Score: %d", score);
            for (auto &it : _staticBlocks) {
                it.draw(_windows["game"]);
            }
            wrefresh(_windows["game"]);
            block.update();
            if (block.checkCollision(_windows["game"])) {
                _staticBlocks.push_back(block);
                int rand = std::rand() % 5;
                block = blocks(nextBlock._type, 30, 0, 1);
                nextBlock = blocks((blocks::blockType)rand, 55, LINES / 2 - 6, 1);
                score++;
            }
            deltaTime = 0;
            _start = clock();
            posX++;
        }
        deltaTime = (float)(clock() - _start) / CLOCKS_PER_SEC;
    }
}


void sm_tetris::drawWalls()
{
    wattron(_windows["game"], COLOR_PAIR(6));
    for (int i = 0; i < LINES; i++) {
        mvwprintw(_windows["game"], i, 21, "|");
        mvwprintw(_windows["game"], i, 41, "|");
    }
    wattroff(_windows["game"], COLOR_PAIR(6));
}

bool sm_tetris::winCheck()
{
    if (winNb == 0)
        return true;
    return false;
}

bool sm_tetris::loseCheck(WINDOW *win)
{
    for (auto &it : _staticBlocks) {
        if (it._y <= 1)
            return true;
    }
    return false;
}

blocks::blocks(blockType type, int x, int y, int speed)
{
    _type = type;
    this->speed = speed;
    isRotated = false;
    _x = x;
    _y = y;
    if (type == T) {
        _blocks.push_back(std::make_pair(std::make_pair(0, 0), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(0, 1), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(0, 2), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(1, 1), 'X'));
        size = 3;
    } else if (type == L) {
        _blocks.push_back(std::make_pair(std::make_pair(0, 0), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(0, 1), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(0, 2), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(1, 2), 'X'));
        size = 3;
    } else if (type == ZIGZAG) {
        _blocks.push_back(std::make_pair(std::make_pair(0, 0), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(0, 1), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(1, 1), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(1, 2), 'X'));
        size = 3;
    } else if (type == SQUARE) {
        _blocks.push_back(std::make_pair(std::make_pair(0, 0), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(0, 1), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(1, 0), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(1, 1), 'X'));
        size = 2;
    } else if (type == LINE) {
        _blocks.push_back(std::make_pair(std::make_pair(0, 0), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(0, 1), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(0, 2), 'X'));
        _blocks.push_back(std::make_pair(std::make_pair(0, 3), 'X'));
        size = 4;
    }
}

blocks::~blocks()
{
}

void blocks::update()
{
    _y += speed;
}

void blocks::draw(WINDOW *win)
{
    wattron(win, COLOR_PAIR((int)_type + 1));
    for (auto &it : _blocks) {
        mvwprintw(win, _y + it.first.first, _x + it.first.second, "%c", it.second);
    }
    wattroff(win, COLOR_PAIR((int)_type + 1));
}

void blocks::move(bool isright)
{
    if (isright && _x + size <= 40 && mvinch(_y, _x + size) != 'x')
        _x++;
    else if (!isright && _x - size >= 20 && mvinch(_y, _x - size) != 'x')
        _x--;
}

bool blocks::checkCollision(WINDOW *win)
{
    for (auto &it : _blocks) {
        if ((mvwinch(win, _y + it.first.first + speed, _x + it.first.second)&A_CHARTEXT) == 'x' || _y + it.first.first + speed >= LINES - 4) {
            for (auto &it : _blocks)
                it.second = 'x';
            return true;
        }
    }
    return false;
}

bool blocks::isInPos(int x, int y)
{
    for (auto &it : _blocks) {
        if (it.first.first == y && it.first.second == x)
            return true;
    }
    return false;
}

void blocks::rotate()
{
    std::vector<std::pair<std::pair<int, int>, char>> tmp;
    for (auto &it : _blocks) {
        tmp.push_back(std::make_pair(std::make_pair(it.first.second, size - it.first.first - 1), it.second));
    }
    _blocks = tmp;
    isRotated = true;
}