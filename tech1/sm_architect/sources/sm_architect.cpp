/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_architect
*/

#include "sm_architect.hpp"

sm_architect::sm_architect()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "SM ARCHITECT");
}

sm_architect::~sm_architect()
{
    
}

void sm_architect::run()
{
    bool isWriting = false;
    
    sf::Event event;
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Space)
                        isWriting = !isWriting;
                    break;
                default:
                    break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
        std::cout << isWriting << std::endl;
        for (auto &shape : shapes)
            window->draw(*shape.shape);
        window->display();
        window->clear();
    }
}