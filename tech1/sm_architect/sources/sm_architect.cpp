/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_architect
*/

#include "sm_architect.hpp"
#include <sstream>

sm_architect::sm_architect()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "SM ARCHITECT");
    commands["create"] = &sm_architect::createShape;
    commands["move"] = &sm_architect::move;
    commands["quit"] = &sm_architect::quit;
    commands["help"] = &sm_architect::help;
    commands["rotate"] = &sm_architect::rotate;
    commands["scale"] = &sm_architect::scale;
    commands["color"] = &sm_architect::color;
    commands["show"] = &sm_architect::show;

    colors["red"] = sf::Color::Red;
    colors["green"] = sf::Color::Green;
    colors["blue"] = sf::Color::Blue;
    colors["yellow"] = sf::Color::Yellow;
    colors["white"] = sf::Color::White;
    colors["black"] = sf::Color::Black;
    colors["magenta"] = sf::Color::Magenta;
    colors["cyan"] = sf::Color::Cyan;

    showName = false;
}

sm_architect::~sm_architect()
{
    
}

void sm_architect::move(std::string str)
{
    std::stringstream ss(str);
    std::string command;
    std::string name;
    std::string x;
    std::string y;
    ss >> command;
    ss >> name;
    ss >> x;
    ss >> y;
    for (auto &shape : shapes) {
        if (shape.getName() == name) {
            shape.move(x, y);
        }
    }
}

void sm_architect::quit(std::string str)
{
    window->close();
}

void sm_architect::help(std::string str)
{
    std::cout << "create <shape> <name> <x> <y> <size> <size_y/nb_points> <color>" << std::endl;
    std::cout << "move <name> <x> <y>" << std::endl;
    std::cout << "color <name> <color>" << std::endl;
    std::cout << "rotate <name> <angle>" << std::endl;
    std::cout << "scale <name> <x> <y>" << std::endl;
    std::cout << "quit" << std::endl;
    std::cout << "help" << std::endl;
}

void sm_architect::color(std::string str)
{
    std::stringstream ss(str);
    std::string command;
    std::string name;
    std::string color;
    ss >> command;
    ss >> name;
    ss >> color;
    for (auto &shape : shapes) {
        if (shape.getName() == name) {
            shape.shape->setFillColor(colors[color]);
        }
    }
}

void sm_architect::show(std::string str)
{
    std::stringstream ss(str);
    std::string command;
    std::string name;
    ss >> command;
    showName = !showName;
}

void sm_architect::rotate(std::string str)
{
    std::stringstream ss(str);
    std::string command;
    std::string name;
    std::string angle;
    ss >> command;
    ss >> name;
    ss >> angle;
    for (auto &shape : shapes) {
        if (shape.getName() == name) {
            shape.shape->rotate(std::stoi(angle));
        }
    }
}

void sm_architect::scale(std::string str)
{
    std::stringstream ss(str);
    std::string command;
    std::string name;
    std::string x;
    std::string y;
    ss >> command;
    ss >> name;
    ss >> x;
    ss >> y;
    for (auto &shape : shapes) {
        if (shape.getName() == name) {
            shape.shape->setScale(sf::Vector2f(std::stoi(x), std::stoi(y)));
        }
    }
}

void sm_architect::createShape(std::string str)
{
    std::cout << "create" << std::endl;
    std::stringstream ss(str);
    std::string command;
    std::string shape;
    std::string name;
    std::string x;
    std::string y;
    std::string size;
    std::string color;
    ss >> command;
    ss >> shape;
    ss >> name;
    ss >> x;
    ss >> y;
    if (shape == "rectangle") {
        std::string size_y;
        ss >> size;
        ss >> size_y;
        ss >> color;
        Shapes *rectangle = new Shapes(new sf::RectangleShape(sf::Vector2f(std::stoi(size), std::stoi(size_y))), name);
        rectangle->move(x, y);
        rectangle->shape->setFillColor(colors[color]);
        shapes.push_back(*rectangle);
    }
    if (shape == "circle") {
        ss >> size;
        ss >> color;
        Shapes *circle = new Shapes(new sf::CircleShape(std::stoi(size)), name);
        circle->move(x, y);
        circle->shape->setFillColor(colors[color]);
        shapes.push_back(*circle);
    }
    if (shape == "triangle") {
        ss >> size;
        ss >> color;
        Shapes *circle = new Shapes(new sf::CircleShape(std::stoi(size), 3), name);
        circle->move(x, y);
        circle->shape->setFillColor(colors[color]);
        shapes.push_back(*circle);
    }
    if (shape == "losange") {
        ss >> size;
        ss >> color;
        Shapes *circle = new Shapes(new sf::CircleShape(std::stoi(size), 4), name);
        circle->move(x, y);
        circle->shape->setFillColor(colors[color]);
        shapes.push_back(*circle);
    }
    if (shape == "special") {
        int nb_point;
        ss >> size;
        ss >> nb_point;
        ss >> color;
        Shapes *circle = new Shapes(new sf::CircleShape(std::stoi(size), nb_point), name);
        circle->move(x, y);
        circle->shape->setFillColor(colors[color]);
        shapes.push_back(*circle);
    }
}

void sm_architect::parseInput(sf::String input)
{
    std::string str = input.toAnsiString();

    std::stringstream ss(str);
    std::string command;
    ss >> command;
    try {
        for (auto &it : commands) {
            if (it.first == command) {
                (this->*it.second)(str);
                return;
            }
        }
        throw std::runtime_error("Unknown command");
    } catch (std::exception &e) {
        std::cout << "Command not found" << std::endl;
        help(str);
    }
}

void sm_architect::run()
{
    bool isWriting = false;
    sf::String input = "";
    sf::Text text;
    sf::Font font;
    font.loadFromFile("assets/stocky.ttf");
    text.setFont(font);
    text.setScale(0.5, 0.5);
    sf::Event event;
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
                isWriting = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && isWriting) {
                isWriting = false;
                parseInput(input.substring(1, input.getSize() - 1));
                input = "";
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && isWriting) {
                input.erase(input.getSize() - 1, 1);
            }
            if (isWriting && event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
                input += event.text.unicode;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
        if (input != "")
            text.setString(input.substring(1, input.getSize()));
        for (auto &shape : shapes)
            window->draw(*shape.shape);
        if (showName)
            for (auto &shape : shapes)
                shape.show_name(window);
        window->draw(text);
        window->display();
        window->clear();
    }
}