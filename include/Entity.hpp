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
    
    virtual void update(const sf::Int32 &dt = 0);
    void draw(sf::RenderTarget& target) const;

    void move(float x, float y);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    int getVelocity() const;

    Direction getDirection() const; // Méthode qui devriat rétourner une enumération de la direction du joueur.
    void setDirection(Direction direction);
    virtual void loadSprite(std::string filepath);
    void setSprite(); // boucle pour sélectionner le sprite et créer une animation

protected:

    int m_velocity = 1;
    float m_scale = 1;
    sf::Vector2f position; 

    sf::Sprite sprite; // Le sprite de joueur
    sf::Texture texture; // La texture associée au sprite

    std::vector<std::vector<sf::Texture>> animations;
    int currentFrame;
    Direction currentDirection = DownIdle;
    const sf::Int32 spriteChangeInterval = 250;
    sf::Clock spriteClock;
    sf::Int32 elapsedTime; 

};


