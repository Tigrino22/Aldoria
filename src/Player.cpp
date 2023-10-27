#include "Player.hpp"
#include <iostream>


/**
 *  Initialisation des paramètre principaux du joueur.
 * 
 *  Retour void
*/

Player::Player(float startX, float startY) {
//     m_shape.setSize(sf::Vector2f(50.f, 50.f));
//     m_shape.setPosition(startX, startY);
//     m_shape.setFillColor(sf::Color::Green); // You can change the color to suit your needs

    // Chargez la texture du joueur à partir d'une image
    if (!texture.loadFromFile("res/mystic_woods_free_2/sprites/characters/player.png", sf::IntRect(0, 0, 48, 48))) {
        std::cerr << "Erreur : Impossible de charger la texture du joueur." << std::endl;
    }

    // Configuration du sprite pour utiliser la texture chargée
    sprite.setTexture(texture);

    // Configuration de la position initiale du joueur
    sprite.setPosition(startX, startY);

    // Gestion de la taille du personnage
    sprite.setScale(m_scale, m_scale);

}

Player::~Player() {
    // Destructor (if needed)
}

void Player::move(float x, float y) {
    sprite.move(x, y);
}

void Player::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

void Player::draw(sf::RenderTarget& target) const {
    target.draw(sprite);
}

int Player::getVelocity() const {
    return this->m_velocity;
}