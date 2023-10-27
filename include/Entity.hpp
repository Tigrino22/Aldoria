#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{

public:
    Entity(/* args */);
    virtual ~Entity();
    virtual void loadSprite();
    void setSprite(); // boucle pour sélectionner le sprite et créer une animation

    void move(float x, float y);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    void draw(sf::RenderTarget& target) const;

    int getVelocity() const;
    Direction getDirection() const; // Méthode qui devriat rétourner une enumération de la direction du joueur.
    void setDirection(Direction direction);
    void getDirection() const; // Méthode qui devriat rétourner une enumération de la direction du joueur.

protected:

    int m_velocity = 2;
    float m_scale = 2.5;
    Direction m_direction = Down;

    sf::Sprite sprite; // Le sprite de joueur
    sf::Texture texture; // La texture associée au sprite
};


