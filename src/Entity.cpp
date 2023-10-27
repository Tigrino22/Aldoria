#include "Entity.hpp"

Entity::Entity(/* args */)
{
    this->loadSprite();
}

Entity::~Entity()
{
}

void Entity::loadSprite(){
    
    // Chargez la texture du joueur à partir d'une image
    if (!texture.loadFromFile("res/mystic_woods_free_2/sprites/characters/player.png", sf::IntRect(0, 0, 48, 48))) {
        std::cerr << "Erreur : Impossible de charger la texture du joueur." << std::endl;
    }

    // Configuration du sprite pour utiliser la texture chargée
    sprite.setTexture(texture);

    // Configuration de la position initiale du joueur
    sprite.setPosition(100.f, 100.f);

    // Gestion de la taille du personnage
    sprite.setScale(m_scale, m_scale);
}

void Entity::move(float x, float y) {
    sprite.move(x, y);
}

void Entity::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Vector2f Entity::getPosition() const {
    return sprite.getPosition();
}

void Entity::setSprite()
{
}

void Entity::draw(sf::RenderTarget& target) const {
    target.draw(sprite);
}

int Entity::getVelocity() const {
    return this->m_velocity;
}

Direction Entity::getDirection() const
{
    return this->m_direction;
}

void Entity::setDirection(Direction direction)
{
    this->m_direction = direction;
}
