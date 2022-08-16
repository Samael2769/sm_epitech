/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_hunter
*/

#include "sm_hunter.hpp"

sm_hunter::sm_hunter()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "SM HUNTER");
    sf::Texture texture;
    sf::Sprite sprite;
    background = std::make_pair(texture, sprite);
    background.first.loadFromFile("assets/background.png");
    background.second.setTexture(background.first);
}

sm_hunter::~sm_hunter()
{
    
}

void sm_hunter::run()
{
    sf::Event event;
    ducks.push_back(new Duck(0, 1));
    while(window->isOpen()) {
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->draw(background.second);
        for (int i = 0; i < ducks.size(); i++) {
            window->draw(ducks[i]->duck[ducks[i]->current]);
            ducks[i]->update();
        }
        window->display();
        window->clear();
    }
}