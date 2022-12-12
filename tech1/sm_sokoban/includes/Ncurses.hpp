/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Ncurses
*/

#pragma once

#include <ncurses.h>
#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>

class Ncurses {
    public:
        Ncurses();
        ~Ncurses();
        void print(int x, int y, std::string str);
        void Nclear();
        void Nrefresh();
        int NgetCh();
        void checkScreen(int x, int y);
        int getLINE() { return LINES; }
        int getCOLS() { return COLS; }
    protected:
    private:
        WINDOW * window;
        int last_key;
        std::string last_writen;
};
