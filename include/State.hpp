#pragma once

#include <SFML/Graphics.hpp>


/// @brief Classe des Etat
class State
{
public:
    State();
    virtual ~State();

    virtual void init() = 0;
    virtual void update(const float &dt) = 0;
    virtual void render(sf::RenderTarget &target) = 0;
    virtual void cleanUp() = 0; // Peut aussi gérer les sauvegardes

    virtual void handleEvent(sf::Event& event) {};
    virtual void onKeyPressed(sf::Event& event){};
    virtual void onKeyRelease(sf::Event& event){};
    virtual void onMouseButtonPressed(sf::Event& event) {};
    virtual void onMouseButtonRelease(sf::Event& event) {};
    virtual void onMouseMoved(sf::Event& evt) {};


protected:

    

};







