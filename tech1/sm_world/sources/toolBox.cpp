/**
 * @ Author: Samael
 * @ Create Time: 2023-02-14 08:11:43
 * @ Modified by: Samael
 * @ Modified time: 2023-02-20 10:54:33
 * @ Description: Project made by Samael
 */

#include "toolBox.hpp"

toolBox::toolBox(sf::Color color, sf::Vector2f position, sf::Vector2f size, sf::RenderWindow *window)
{
    _toolBox.setFillColor(color);
    _toolBox.setPosition(position);
    _toolBox.setSize(size);
    _window = window;
}

toolBox::~toolBox()
{
}

void toolBox::draw()
{
    _window->draw(_toolBox);
    for (int i = 0; i < _buttons.size(); i++) {
        _window->draw(_buttons[i].shape);
        _window->draw(_buttons[i].text);
        _window->draw(_buttons[i].sprite);
    }
}

void toolBox::addButton(std::string text, sf::Color color, sf::Vector2f position, sf::Vector2f size)
{
    button_t button;

    button.shape.setFillColor(color);
    button.shape.setPosition(position);
    button.shape.setSize(size);
    button.text.setString(text);
    button.id = id;
    id++;
    _buttons.push_back(button);
}
void toolBox::addText(sf::Font font, sf::Color color, sf::Vector2f position, int id, std::string text)
{
    for (int i = 0; i < _buttons.size(); i++) {
        if (_buttons[i].id == id) {
            _buttons[i].text.setFont(font);
            _buttons[i].text.setFillColor(color);
            _buttons[i].text.setPosition(position);
            _buttons[i].text.setString(text);
        }
    }
}

void toolBox::addImage(sf::Texture texture, sf::Vector2f position, int id)
{
    for (int i = 0; i < _buttons.size(); i++) {
        if (_buttons[i].id == id) {
            _buttons[i].texture = texture;
            _buttons[i].sprite.setTexture(_buttons[i].texture);
            _buttons[i].sprite.setPosition(position);
        }
    }
}

bool toolBox::button_t::isClicked(sf::RenderWindow *window, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            if (mousePos.x >= shape.getPosition().x && mousePos.x <= shape.getPosition().x + shape.getSize().x) {
                if (mousePos.y >= shape.getPosition().y && mousePos.y <= shape.getPosition().y + shape.getSize().y) {
                    return true;
                }
            }
        }
    }
    return false;
}
#include <iostream>
bool toolBox::isClicked(sf::RenderWindow *window, sf::Event event, int id)
{
    for (int i = 0; i < _buttons.size(); i++) {
        if (_buttons[i].id == id) {
            return _buttons[i].isClicked(window, event);
        }
    }
    return false;
}