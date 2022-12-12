/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** mySokoban
*/

#include "mySokoban.hpp"

mySokoban::mySokoban()
{
    _ncurses = Ncurses();
}

mySokoban::~mySokoban()
{
}

void mySokoban::printMap()
{
    for (int i = 0; i < _map.size(); i++) {
        _ncurses.print(0, i, _map[i]);
    }
}

void mySokoban::run()
{
    _ncurses.checkScreen(20, 10);
    setPlayer();
    getBoxes();
    while (checkWin() != true) {
        printMap();
        int key = _ncurses.NgetCh();
        movePlayer(key);
        setBoxes();
        _ncurses.Nrefresh();
        _ncurses.Nclear();
        usleep(100000);
    }
    _ncurses.print(LINES/2, COLS/2, "You win!");
    _ncurses.Nrefresh();
    usleep(1000000);
}

void mySokoban::setMap(std::string filepath)
{
    std::ifstream file;
    std::string str;

    file.open(filepath);
    if (file.is_open()) {
        while (getline(file, str)) {
            _map.push_back(str);
        }
    }
    file.close();
}

std::pair<int, int> mySokoban::getPlayer()
{
    return _player;
}

void mySokoban::setPlayer()
{
    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] == 'P') {
                _player.first = i;
                _player.second = j;
            }
        }
    }
}

void mySokoban::movePlayer(int key)
{
    switch (key) {
        case KEY_UP:
            if (_map[_player.first - 1][_player.second] != '#') {
                if (moveBox(0) != true)
                    break;
                _map[_player.first][_player.second] = ' ';
                _map[_player.first - 1][_player.second] = 'P';
                _player.first -= 1;
            }
            break;
        case KEY_DOWN:
            if (_map[_player.first + 1][_player.second] != '#') {
                if (moveBox(1) != true)
                    break;
                _map[_player.first][_player.second] = ' ';
                _map[_player.first + 1][_player.second] = 'P';
                _player.first += 1;
            }
            break;
        case KEY_LEFT:
            if (_map[_player.first][_player.second - 1] != '#') {
                if (moveBox(2) != true)
                    break;
                _map[_player.first][_player.second] = ' ';
                _map[_player.first][_player.second - 1] = 'P';
                _player.second -= 1;
            }
            break;
        case KEY_RIGHT:
            if (_map[_player.first][_player.second + 1] != '#') {
                if (moveBox(3) != true)
                    break;
                _map[_player.first][_player.second] = ' ';
                _map[_player.first][_player.second + 1] = 'P';
                _player.second += 1;
            }
            break;
        default: 
            return;
    }
}

bool mySokoban::moveBox(int type)
{
    switch (type) {
        case 0:
            if (_map[_player.first - 1][_player.second] == 'X') {
                if (_map[_player.first - 2][_player.second] != '#' && _map[_player.first - 2][_player.second] != 'X') {
                    _map[_player.first - 1][_player.second] = ' ';
                    _map[_player.first - 2][_player.second] = 'X';
                    return true;
                }
                return false;
            }
            break;
        case 1:
            if (_map[_player.first + 1][_player.second] == 'X') {
                if (_map[_player.first + 2][_player.second] != '#' && _map[_player.first + 2][_player.second] != 'X') {
                    _map[_player.first + 1][_player.second] = ' ';
                    _map[_player.first + 2][_player.second] = 'X';
                    return true;
                }
                return false;
            }
            break;
        case 2:
            if (_map[_player.first][_player.second - 1] == 'X') {
                if (_map[_player.first][_player.second - 2] != '#' && _map[_player.first][_player.second - 2] != 'X') {
                    _map[_player.first][_player.second - 1] = ' ';
                    _map[_player.first][_player.second - 2] = 'X';
                    return true;
                }
                return false;
            }
            break;
        case 3:
            if (_map[_player.first][_player.second + 1] == 'X') {
                if (_map[_player.first][_player.second + 2] != '#' && _map[_player.first][_player.second + 2] != 'X') {
                    _map[_player.first][_player.second + 1] = ' ';
                    _map[_player.first][_player.second + 2] = 'X';
                    return true;
                }
                return false;
            }
            break;
        default:
            return true;
    }
    return true;
}

void mySokoban::getBoxes()
{
    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] == 'O') {
                _boxes.push_back(std::make_pair(i, j));
            }
        }
    }
}

void mySokoban::setBoxes()
{
    for (int i = 0; i < _boxes.size(); i++) {
        if (_map[_boxes[i].first][_boxes[i].second] != 'X' && _map[_boxes[i].first][_boxes[i].second] != 'P')
            _map[_boxes[i].first][_boxes[i].second] = 'O';
    }
}

bool mySokoban::checkWin()
{
    for (int i = 0; i < _boxes.size(); i++) {
        if (_map[_boxes[i].first][_boxes[i].second] != 'X')
            return false;
    }
    return true;
}