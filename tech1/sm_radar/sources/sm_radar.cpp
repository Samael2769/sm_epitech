/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_radar
*/

#include "sm_radar.hpp"
#include <ctime>

sm_radar::sm_radar()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 500), "Sm Radar");
    sf::Texture *texture = new sf::Texture();
    sf::Sprite *sprite = new sf::Sprite();
    texture->loadFromFile("assets/map.jpg");
    sprite->setTexture(*texture);
    sprite->setScale(1.5, 1.5);
    sprites.push_back(std::make_pair(texture, sprite));
}

sm_radar::~sm_radar()
{
    
}

void sm_radar::run()
{
    sf::Text text;
    sf::Font font;
    srand(time(NULL));
    int nb = rand() % 10 + 1;
    font.loadFromFile("assets/font.ttf");
    text.setFont(font);
    text.setCharacterSize(15);
    while (window->isOpen()) {
        sf::Event event;
        if (planes.size() < nb) {
            int x = rand() % 750;
            int y = rand() % 450;
            int x2 = rand() % 750;
            int y2 = rand() % 450;
            Plane *plane = new Plane(sf::Vector2f(x, y), sf::Vector2f(x2, y2));
            planes.push_back(plane);
        }
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
        window->clear();
        window->draw(*sprites[0].second);
        for (auto &p : planes) {
            p->update();
        }
        for (auto &p : planes)
            p->draw(window);
        for (int i = 0; i < planes.size(); i++) {
            for (int j = i + 1; j < planes.size(); j++) {
                if (planes[i]->collide(*planes[j]) == 0) {
                    text.setString("Collision between plane " + std::to_string(i) + " and plane " + std::to_string(j));
                    planes.erase(planes.begin() + j);
                    if (j < i)
                        i--;
                    planes.erase(planes.begin() + i);
                    break;
                }
                if (planes[i]->collide(*planes[j]) == 1) {
                    text.setString("Plane " + std::to_string(i) + " is in hight danger zone of plane " + std::to_string(j));
                    planes[i]->dir_change = true;
                    planes[j]->dir_change = true;
                    break;
                }
                if (planes[i]->collide(*planes[j]) == 2) {
                    text.setString("Plane " + std::to_string(i) + " is in danger zone of plane " + std::to_string(j));
                    planes[i]->dir_change = true;
                    planes[j]->dir_change = true;
                    break;
                }
                planes[i]->dir_change = false;
                planes[j]->dir_change = false;
            }
        }
        for (int i = 0; i < planes.size(); i++) {
            if (planes[i]->getSpeed() < 30) {
                text.setString("Plane " + std::to_string(i) + " has arrived");
                planes.erase(planes.begin() + i);
            }
        }
        window->draw(text);
        window->display();
    }
}