/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** mySokoban
*/

#ifndef MYSOKOBAN_HPP_
#define MYSOKOBAN_HPP_

#include <Ncurses.hpp>
#include <fstream>
#include <vector>
#include <utility>

class mySokoban {
    public:
        mySokoban();
        ~mySokoban();
        void run();
        void setMap(std::string filepath);
        void printMap();
        std::pair<int, int> getPlayer();
        void setPlayer();
        void movePlayer(int key);
        bool moveBox(int type);
        bool checkWin();
        void getBoxes();
        void setBoxes();
    protected:
    private:
        std::vector<std::string> _map;
        std::pair<int, int> _player;
        Ncurses _ncurses;
        std::vector<std::pair<int, int>> _boxes;
};

#endif /* !MYSOKOBAN_HPP_ */
