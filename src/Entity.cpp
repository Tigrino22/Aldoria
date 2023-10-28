#include "Entity.hpp"

Entity::Entity(/* args */)
{

    
}

Entity::~Entity()
{
}

void Entity::update(const sf::Int32 &dt)
{
    this->setSprite();
}

/**
 *  Fonction principale du chargement de tous les sprites du joueur 
 *  (sera peut être déplacée dans Entity si portable pour d'autres entités)
 *  Il ne reste plus qu'à utiliser le tableau de Vector
 * 
 *  Return void
*/
void Entity::loadSprite(std::string filepath)
{   
    sprite.setPosition(100.f, 100.f);
    // Chargement de la Texture du joueur
    if(!texture.loadFromFile(filepath)){
        std::cerr << "Erreur : Impossible de charger la texture du joueur." << std::endl;
    }

    //  Définition de la taille des sprites
    int spriteSize = 64;

    // Découpage de la texture (vector Y) en fonciton de la taille du Sprite
    for (unsigned int i = 0; i < texture.getSize().y; i += spriteSize)
    {
        // Création des sous vectors
        std::vector<sf::Texture> animation;

        // Boucle d'ajout de chaque sprite sur l'axe X
        for (unsigned int j = 0; j < texture.getSize().x; j += spriteSize)
        {
            // Création du sous Rect pour appliquer la texture
            sf::IntRect rect(j, i, spriteSize, spriteSize);
            sf::Texture frameTexture;
            frameTexture.loadFromImage(texture.copyToImage(), rect);

            animation.push_back(frameTexture);
        
        }

        animations.push_back(animation);
        
    }

    currentFrame = 0;
    sprite.setTexture(animations[static_cast<int>(currentDirection)][currentFrame]);
    

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

void Entity::draw(sf::RenderTarget& target) const {
    target.draw(sprite);
}

int Entity::getVelocity() const {
    return this->m_velocity;
}

Direction Entity::getDirection() const
{
    return this->currentDirection;
}

void Entity::setDirection(Direction direction)
{
    if(currentDirection != direction){
        currentDirection = direction;
        currentFrame = 0;
        sprite.setTexture(animations[static_cast<int>(currentDirection)][currentFrame]);
    }
}

void Entity::setSprite()
{

    elapsedTime = spriteClock.getElapsedTime().asMilliseconds();

    if (elapsedTime >= spriteChangeInterval){

        if(currentFrame < animations[static_cast<int>(currentDirection)].size() -1){
            currentFrame++;
        } else {
            currentFrame = 0;
        }

        sprite.setTexture(animations[static_cast<int>(currentDirection)][currentFrame]);

        spriteClock.restart();

    }
}
