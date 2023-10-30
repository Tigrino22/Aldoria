#include "Player.hpp"
#include <iostream>


/**
 *  Initialisation des paramètre principaux du joueur.
 * 
 *  Retour void
*/

Player::Player() {

}

Player::~Player() {
    // Destructor (if needed)
    
}

/**
 *  Fonction gérant les entrées claviers afin de controller le personnage
 *  Cette fonction est appelée dans le updateEvent du State.
 * 
 *  return void
*/

void Player::updateEvent()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->move(0, this->getVelocity() * (-1));
        this->setDirection(Direction::Up);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->move(0, this->getVelocity() * (1));
        this->setDirection(Direction::Down);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->move(this->getVelocity() * (-1), 0);
        this->setDirection(Direction::Left);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->move(this->getVelocity() * (1), 0);
        this->setDirection(Direction::Right);
    }
    
}

/**
 *  Override
 * 
 *  Fonciton d'update de la classe du personnage
 *  chaque changement d'état doit être pris en charge par
 *  cette fonction
 * 
 *  Return void
*/

void Player::update(const sf::Int32 &dt)
{

    this->setSprite();

}

void Player::onKeyPressed(sf::Event &event)
{

}

void Player::onKeyRelease(sf::Event &event)
{
    if(event.key.code == sf::Keyboard::Up){
        this->setDirection(UpIdle);
    }else if (event.key.code == sf::Keyboard::Down)
    {
        this->setDirection(DownIdle);
    }else if (event.key.code == sf::Keyboard::Right)
    {
        this->setDirection(RightIdle);
    }else if (event.key.code == sf::Keyboard::Left)
    {
        this->setDirection(LeftIdle);
    }

}
