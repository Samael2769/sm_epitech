/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_navy
*/

#ifndef SM_NAVY_HPP_
#define SM_NAVY_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

class sm_navy {
    public:
        sm_navy();
        ~sm_navy();
        void setType(int type) {_type = type;}
        void setBoatFile(std::string file) {_boatFile = file;}
        void setPid(int pid) {_pid = pid;}
        void writeBoats();
        void display_map();
        void display_enemy();
        void create_map();
        void run();
        void placeShip(std::pair<int, int> c1, std::pair<int, int> c2, int size, char c);
        bool checkCoords(std::pair<int, int> coord);
        void sendData(bool val);
        bool receiveData();
        void printPID();
        bool playerOne();
        bool playerTwo();
        void set_signal();
        void attack(int _x, int _y);
        std::pair<int, int> defense();
        
    protected:
    private:
        int _type;
        std::vector<std::string> _map;
        std::vector<std::string> _enemy;
        std::string _boatFile;
        int _pid;
        int _pid2;
};

#endif /* !SM_NAVY_HPP_ */
