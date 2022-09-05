/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Plane
*/

#include "Plane.hpp"

Plane::Plane(sf::Vector2f pos, sf::Vector2f dest)
{
    sf::Texture *texture = new sf::Texture();
    sf::Sprite *sprite = new sf::Sprite();
    texture->loadFromFile("assets/plane.png");
    sprite->setTexture(*texture);
    sprite->setPosition(pos);
    sprite->setScale(0.1, 0.1);
    sprite->setOrigin(50, 50);
    this->sprite = std::make_pair(texture, sprite);
    this->dest = dest;
    this->zone = new sf::CircleShape(25);
    this->zone->setFillColor(sf::Color(0, 0, 0, 0));
    this->zone->setOutlineColor(sf::Color::Green);
    this->zone->setOutlineThickness(2);
    this->zone->setPosition(sf::Vector2f(dest.x - 25, dest.y - 25));
    this->zone->setOrigin(25, 25);
    this->danger = new sf::CircleShape(50);
    this->danger->setFillColor(sf::Color(0, 0, 0, 0));
    this->danger->setOutlineColor(sf::Color::Red);
    this->danger->setOutlineThickness(2);
    this->danger->setPosition(sf::Vector2f(dest.x - 50, dest.y - 50));
    this->danger->setOrigin(50, 50);
    this->dir_change = false;
}

Plane::~Plane()
{
}

void Plane::update()
{
    sf::Vector2f pos = this->sprite.second->getPosition();
    sf::Vector2f dir = this->dest - pos;
    float angle = atan2(dir.x, dir.y);
    this->sprite.second->setRotation(angle * 180 / M_PI + 90);
    if (dir_change == false)
        this->sprite.second->move(dir.x / 1000, dir.y / 1000);
    else
        this->sprite.second->move( - (dir.x / 1000), - (dir.y / 1000));
    if (this->sprite.second->getPosition().x < 50)
        this->sprite.second->setPosition(450, this->sprite.second->getPosition().y);
    if (this->sprite.second->getPosition().x > 850)
        this->sprite.second->setPosition(50, this->sprite.second->getPosition().y);
    if (this->sprite.second->getPosition().y < 50)
        this->sprite.second->setPosition(this->sprite.second->getPosition().x, 450);
    if (this->sprite.second->getPosition().y > 450)
        this->sprite.second->setPosition(this->sprite.second->getPosition().x, 50);
    this->zone->setPosition(this->sprite.second->getPosition());
    this->danger->setPosition(this->sprite.second->getPosition());
}

void Plane::draw(sf::RenderWindow *window)
{
    window->draw(*this->sprite.second);
    window->draw(*this->zone);
    window->draw(*this->danger);
}

int Plane::collide(Plane &other)
{
    if (this->sprite.second->getGlobalBounds().intersects(other.sprite.second->getGlobalBounds()))
        return 0;
    if (this->danger->getGlobalBounds().intersects(other.sprite.second->getGlobalBounds()))
        return 1;
    if (this->zone->getGlobalBounds().intersects(other.sprite.second->getGlobalBounds()))
        return 2;
    return -1;
}

float Plane::getSpeed()
{
    return sqrt(pow(this->sprite.second->getPosition().x - this->dest.x, 2) + pow(this->sprite.second->getPosition().y - this->dest.y, 2));
}