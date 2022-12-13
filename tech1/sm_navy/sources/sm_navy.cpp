/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_navy
*/

#include "sm_navy.hpp"
#include <fstream>
#include <exception>


static int pid2 = 0;
static int x = 0;
static int y = 0;

sm_navy::sm_navy()
{
    create_map();
    _enemy = _map;
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

void sm_navy::display_enemy()
{
    std::cout << " |A B C D E F G H" << std::endl;
    for (int i = 0; i < _enemy.size(); i++) {
        std::cout << i + 1 << "|";
        for (int j = 0; j < _enemy[i].size(); j++) {
            std::cout << _enemy[i][j] << " ";
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
    set_signal();
    usleep(1);

    int t = 0;
    if (_type == 2)
        t = 1;

    while (1) { 
        if (t == 0) {
            display_map();
            display_enemy();
            std::cout << "attack: ";
            std::string input;
            std::cin >> input;
            if (input.size() != 2)
                throw std::invalid_argument("Invalid coordinates");
            if (input[0] < 'A' || input[0] > 'H')
                throw std::invalid_argument("Invalid coordinates");
            if (input[1] < '1' || input[1] > '8')
                throw std::invalid_argument("Invalid coordinates");
            attack(input[0] - 'A', input[1] - '0');
            t = 1;
            usleep(1);
        } else {
            usleep(100000);
            std::pair<int, int> coord = defense();
            std::cout << "enemy's attack: " << (char)(coord.first + 'A') << coord.second + 1 << std::endl;
            t = 0;
        }
    }
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

void sig_SIGUSR1(int signal)
{
    x += 1;
}

void sig_SIGUSR2(int signal)
{
    y = 1;
}

void sm_navy::sendData(bool val)
{
    if (val == true)
        kill(pid2, SIGUSR1);
    else
        kill(pid2, SIGUSR2);
}

void sm_navy::set_signal()
{
    signal(SIGUSR1, sig_SIGUSR1);
    signal(SIGUSR2, sig_SIGUSR2);
}

bool sm_navy::receiveData()
{
    if (usleep(1000000000) == 0) {
        std::cout << "retry" << std::endl;
    }
    if (y == 0) {
        return true;
    } else {
        y = 0;
        return false;
    }
}

void handler(int signal, siginfo_t *sig1, void *sig)
{
    pid2 = sig1->si_pid;
    std::cout << "enemy connected" << std::endl;
    kill(pid2, SIGUSR2);
}

void handler_rec(int signal, siginfo_t *sig1, void *sig)
{
    std::cout << "successfully connected to " << pid2 << std::endl;
}

bool sm_navy::playerOne()
{
    printPID();
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handler;
    std::cout << "waiting for enemy connection..." << std::endl;
    sigaction(SIGUSR1, &sa, NULL);
    if (usleep(10000000) == 0)
        throw std::logic_error("Too long to connect");
    usleep(1);
    return true;
}

bool sm_navy::playerTwo()
{
    pid2 = _pid;
    _pid = getpid();
    kill(pid2, SIGUSR1);
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handler_rec;
    sigaction(SIGUSR2, &sa, NULL);
    if (usleep(10000000) == 0)
        throw std::logic_error("Too long to connect");
    usleep(1);
    return true;
}

void sm_navy::attack(int _x, int _y)
{
    for (int i = 0; i < _x; ++i) {
        sendData(true);
        usleep(1);
    }
    sendData(false);
    usleep(1);
    for (int i = 0; i < _y; ++i) {
        sendData(true);
        usleep(1);
    }
    sendData(false);
    usleep(1);
}

std::pair<int, int> sm_navy::defense()
{
    std::pair<int, int> coord;
    coord.first = 0;
    coord.second = 0;
    while (1) {
        if (receiveData() == false)
            break;
        usleep(1);
    }
    usleep(1);
    coord.first = x;
    x = 0;
    while (1) {
        if (receiveData() == false)
            break;
        usleep(1);
    }
    coord.second = x;
    x = 0;
    usleep(1);
    return coord;
}