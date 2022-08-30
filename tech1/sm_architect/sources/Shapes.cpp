/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Shapes
*/

#include "Shapes.hpp"

Shapes::Shapes(sf::Shape *shape, std::string name)
{
    this->shape = shape;
    this->name = name;
}

Shapes::~Shapes()
{
}

void Shapes::show_name(sf::RenderWindow *window)
{
    sf::Text text;
    sf::Font font;
    font.loadFromFile("assets/stocky.ttf");
    text.setFont(font);
    text.setString(name);
    text.setPosition(shape->getPosition().x, shape->getPosition().y);
    window->draw(text);
}