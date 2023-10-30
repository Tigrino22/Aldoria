#pragma once 

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Player : public Entity {

public:
    Player();
    virtual ~Player();
    void updateEvent();
    void update(const sf::Int32 &dt = 0) override;

    // Methode d'action
    
    void onKeyPressed(sf::Event& event);
    void onKeyRelease(sf::Event& event);

private:
    

};