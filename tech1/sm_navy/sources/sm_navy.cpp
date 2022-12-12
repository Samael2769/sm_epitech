/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_navy
*/

#include "sm_navy.hpp"
#include <signal.h>
#include <fstream>
#include <exception>


static int pid2 = 0;

sm_navy::sm_navy()
{
    create_map();
}

sm_navy::~sm_navy()
{
    
}

void sm_navy::display_map()
{
    std::cout << " |A B C D E F G H" << std::endl;
    for (int i = 0; i < _map.size(); i++) {
        std::cout << i + 1 << "|";
        for (int j = 0; j < _map[i].size(); j++) {
            std::cout << _map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void sm_navy::create_map()
{
    _map.push_back("........");
    _map.push_back("........");
    _map.push_back("........");
    _map.push_back("........");
    _map.push_back("........");
    _map.push_back("........");
    _map.push_back("........");
}

void sm_navy::run()
{
    writeBoats();
    display_map();
}

//Place ship from c1 to c2 with size size
void sm_navy::placeShip(std::pair<int, int> c1, std::pair<int, int> c2, int size, char c)
{
    if (c1.first < 0 || c1.first > 6 || c1.second < 0 || c1.second > 7 || c2.first < 0 || c2.first > 6 || c2.second < 0 || c2.second > 7)
        throw std::invalid_argument("Invalid coordinates");
    if (c1.first == c2.first && c1.second == c2.second)
        throw std::invalid_argument("Invalid coordinates");
    if (c1.first != c2.first && c1.second != c2.second)
        throw std::invalid_argument("Invalid coordinates");
    if (c1.first == c2.first) {
        if (c1.second + size - 1 != c2.second)
            throw std::invalid_argument("Invalid size");
        for (int i = c1.second; i <= c2.second; i++)
            if (_map[c1.first][i] != '.')
                throw std::invalid_argument("Already shiped");
        for (int i = c1.second; i <= c2.second; i++) {
            _map[c1.first][i] = c;
        }
    } else if (c1.second == c2.second) {
        if (c1.first + size - 1 != c2.first)
            throw std::invalid_argument("Invalid size");
        for (int i = c1.first; i <= c2.first; i++)
            if (_map[i][c1.second] != '.')
                throw std::invalid_argument("Already shiped");
        for (int i = c1.first; i <= c2.first; i++) {
            _map[i][c1.second] = c;
        }
    } else
        throw std::invalid_argument("Invalid coordinates");
}

bool sm_navy::checkCoords(std::pair<int, int> coord)
{
    if (_map[coord.first][coord.second] == 'x')
        return true;
    return false;
}

void sm_navy::sendData(bool val)
{
    
}

bool sm_navy::receiveData()
{
    return false;
}

//get file datas in boat vector
void sm_navy::writeBoats()
{
    std::ifstream file(_boatFile);
    std::string line;
    std::pair<int, int> c1;
    std::pair<int, int> c2;
    int size;
    char c;

    if (!file) {
        std::cout << "Error while opening file" << std::endl;
        return;
    }
    while (getline(file, line)) {
        if (line.size() < 7) {
            std::cout << "Invalid file" << std::endl;
            return;
        }
        c1.second = line[2] - 'A';
        c1.first = line[3] - '0' - 1;
        c2.second = line[5] - 'A';
        c2.first = line[6] - '0' - 1;
        size = line[0] - '0';
        c = line[0];
        placeShip(c1, c2, size, c);
    }
}

void sm_navy::printPID()
{
    std::cout << "my_pid: " << getpid() << std::endl;
}

void sig1(int signal, siginfo_t *sig1, void *sig)
{
    std::cout << "User connected" << std::endl;
    kill(sig1->si_pid, SIGUSR2);
    pid2 = sig1->si_pid;
}

void sig2(int signal, siginfo_t *sig1, void *sig)
{
    std::cout << "Connection established" << std::endl;
}

bool sm_navy::playerOne()
{
    printPID();
    struct sigaction sa;
    sa.sa_sigaction = &sig1;
    sa.sa_flags = SA_SIGINFO;
    std::cout << "waiting for enemy connection..." << std::endl;
    sigaction(SIGUSR1, &sa, NULL);
    if (usleep(10000000) == 0)
        throw std::logic_error("Too long to connect");
    return true;
}

bool sm_navy::playerTwo()
{
    kill(_pid, SIGUSR1);
    struct sigaction sa;
    sa.sa_sigaction = &sig2;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sa, NULL);
    if (usleep(10000000) == 0)
        throw std::logic_error("Too long to connect");
    return true;
}