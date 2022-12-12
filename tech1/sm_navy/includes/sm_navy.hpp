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

class sm_navy {
    public:
        sm_navy();
        ~sm_navy();
        void setType(int type) {_type = type;}
        void setBoatFile(std::string file) {_boatFile = file;}
        void writeBoats();
        void display_map();
        void create_map();
        void run();
        void placeShip(std::pair<int, int> c1, std::pair<int, int> c2, int size, char c);
        bool checkCoords(std::pair<int, int> coord);
        void sendData(bool val);
        bool receiveData();
        
    protected:
    private:
        int _type;
        std::vector<std::string> _map;
        std::string _boatFile;
};

#endif /* !SM_NAVY_HPP_ */
