/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_architect
*/

#ifndef SM_ARCHITECT_HPP_
#define SM_ARCHITECT_HPP_

#include "Shapes.hpp"
#include <map>

class sm_architect {
    public:
        sm_architect();
        ~sm_architect();
        void run();
        void parseInput(sf::String input);
        void createShape(std::string shape);
        void quit(std::string str);
        void help(std::string str);
        void move(std::string str);
        void rotate(std::string str);
        void scale(std::string str);
        void color(std::string str);
        void show(std::string str);
    protected:
    private:
        sf::RenderWindow *window;
        std::vector<Shapes> shapes;
        std::map<std::string, void (sm_architect::*)(std::string)> commands;
        std::map<std::string, sf::Color> colors;
        bool showName;
};

#endif /* !SM_ARCHITECT_HPP_ */
