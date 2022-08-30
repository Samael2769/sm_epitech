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
    this->isDragged = false;
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

void Shapes::drag(sf::RenderWindow *window)
{
    if (isDragged) {
        shape->setPosition(sf::Mouse::getPosition(*window).x - shape->getLocalBounds().width / 2, sf::Mouse::getPosition(*window).y - shape->getLocalBounds().height / 2);
    }
}