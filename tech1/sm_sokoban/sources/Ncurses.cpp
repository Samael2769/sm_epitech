/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
    window = initscr();
    keypad(window, true);
    noecho();
    keypad(window, TRUE);
    curs_set(0);
}

Ncurses::~Ncurses()
{
    echo();
    endwin();
}

void Ncurses::print(int x, int y, std::string str)
{
    mvprintw(y, x, str.c_str());
}

void Ncurses::Nclear()
{
    clear();
}

void Ncurses::Nrefresh()
{
    refresh();
}

int Ncurses::NgetCh()
{
    return wgetch(window);
}

void Ncurses::checkScreen(int x, int y)
{
    while (x > COLS || y > LINES) {
        clear();
        mvprintw(LINES/2, COLS/2, "Enlarge your terminal please.");
        usleep(10000);
        refresh();
    }
}