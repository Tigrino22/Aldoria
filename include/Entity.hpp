#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Enumerations.hpp"

class Entity
{

    /**
     *  En utilisant cette classe , merci d'appeler loadSprite() 
     *  à l'initialisation afin de spécifier le chemin d'accès 
     *  au fichier sprite.
    */

public:
    Entity(/* args */);
    virtual ~Entity();
    void update(const sf::Int32 &dt = 0);
    virtual void loadSprite(std::string filepath);

    void move(float x, float y);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    void draw(sf::RenderTarget& target) const;

    int getVelocity() const;
    Direction getDirection() const; // Méthode qui devriat rétourner une enumération de la direction du joueur.
    void setDirection(Direction direction);
    void setSprite(); // boucle pour sélectionner le sprite et créer une animation

protected:

    int m_velocity = 1;
    float m_scale = 1;
    sf::Vector2f position; 

    sf::Sprite sprite; // Le sprite de joueur
    sf::Texture texture; // La texture associée au sprite

    std::vector<std::vector<sf::Texture>> animations;
    int currentFrame;
    Direction currentDirection = Down;
    const sf::Int32 spriteChangeInterval = 250;
    sf::Clock spriteClock;
    sf::Int32 elapsedTime; 

};


