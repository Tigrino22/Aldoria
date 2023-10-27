#pragma once 

#include <SFML/Graphics.hpp>

class Player{

public:
    Player(float startX, float startY);
    virtual ~Player();

    void move(float x, float y);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    void draw(sf::RenderTarget& target) const;

    int getVelocity() const;

private:

    void setSprite(); // boucle pour sélectionner le sprite et créer une animation
    void getDirection() const; // Méthode qui devriat rétourner une enumération de la direction du joueur.


    // sf::RectangleShape m_shape;
    int m_velocity = 2;
    float m_scale = 2.5;

    sf::Sprite sprite; // Le sprite de joueur
    sf::Texture texture; // La texture associée au sprite

};