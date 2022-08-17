/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_hunter
*/

#include "sm_hunter.hpp"
#include <fstream>

sm_hunter::sm_hunter()
{
    window = new sf::RenderWindow(sf::VideoMode(1000, 600), "SM HUNTER");
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
    sf::Clock clock;
    float dt = 0.f;
    float elapsed = 0.f;
    float gameElapsed = 0.f;
    int score = 0;
    int level = 1;
    sf::Font font;
    font.loadFromFile("assets/font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setPosition(10, 10);
    sf::Text text2;
    text2.setFont(font);
    text2.setPosition(500, 30);
    float gameTime = 90.f;

    while(window->isOpen()) {
        dt = clock.restart().asMicroseconds();
        elapsed += dt;
        gameElapsed += dt;
        if (ducks.size() < level && ducks.size() < 3) {
            ducks.push_back(new Duck(rand() % 4, level));
        }
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window->close();
            }

        }
        window->draw(background.second);
        for (int i = 0; i < ducks.size(); i++) {
            window->draw(ducks[i]->duck[ducks[i]->current]);
            if (elapsed >= 20.f) {
                ducks[i]->update();
                if (i == ducks.size() - 1)
                    elapsed = 0.f;
            }
            ducks[i]->move();
            if (ducks[i]->life <= 0) {
                window->draw(ducks[i]->duck[2]);
                ducks.erase(ducks.begin() + i);
                score++;
            }
            if (ducks[i]->pos.x >= window->getSize().x || ducks[i]->pos.x <= 0) {
                ducks.erase(ducks.begin() + i);
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            for (int i = 0; i < ducks.size(); i++) {
                if (ducks[i]->pos.x >= sf::Mouse::getPosition(*window).x - 100 && ducks[i]->pos.x <= sf::Mouse::getPosition(*window).x + 100 && ducks[i]->pos.y >= sf::Mouse::getPosition(*window).y - 100 && ducks[i]->pos.y <= sf::Mouse::getPosition(*window).y + 100) {
                    ducks[i]->life -= 1;
                }
            }
        }
        if (score >= 10 * level) {
            level++;
        }
        if (gameTime - (gameElapsed / 1000000) <= 0) {
            window->close();
        }
        text.setString(std::to_string(score));
        text2.setString(std::to_string(gameTime - (gameElapsed / 1000000)));
        window->draw(text);
        window->draw(text2);
        window->display();
        window->clear();
    }
    std::fstream file;
    file.open(".score", std::ios::out | std::ios::app);
    file << score << std::endl;
    std::cout << "Score = " << score << std::endl;
}