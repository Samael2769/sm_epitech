/**
 * @ Author: Samael
 * @ Create Time: 2023-02-14 07:54:37
 * @ Modified by: Samael
 * @ Modified time: 2023-02-14 09:03:00
 * @ Description: Project made by Samael
 */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

static int id = 0;

class toolBox {
    public:
        toolBox(sf::Color color, sf::Vector2f position, sf::Vector2f size, sf::RenderWindow *window);
        ~toolBox();
        void draw();
        void addButton(std::string text, sf::Color color, sf::Vector2f position, sf::Vector2f size);
        void addText(sf::Font font, sf::Color color, sf::Vector2f position, int id, std::string text);
        void addImage(sf::Texture texture, sf::Vector2f position, int id);
        struct button_t {
            sf::RectangleShape shape;
            sf::Color color;
            sf::Vector2f position;
            sf::Text text;
            sf::Font font;
            sf::Texture texture;
            sf::Sprite sprite;
            int id;
            bool isClicked(sf::RenderWindow *window, sf::Event event);
        };
        bool isClicked(sf::RenderWindow *window, sf::Event event, int id);
    private:
        sf::RectangleShape _toolBox;
        sf::RenderWindow *_window;
        std::vector<button_t> _buttons;
};