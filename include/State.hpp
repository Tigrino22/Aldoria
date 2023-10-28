#pragma once

#include <SFML/Graphics.hpp>

class Game;


class State
{
public:
    State(Game* m_game);
    virtual ~State();

    virtual void init() = 0;
    virtual void updateEvent() = 0;
    virtual void update(const sf::Int32 &dt) = 0;
    virtual void render(sf::RenderTarget &target) = 0;

    virtual void endState() = 0; // Peut aussi gérer les sauvegardes
    virtual bool getIsRunning() = 0;

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void onKeyPressed(sf::Event& event) = 0;
    // virtual void onKeyRelease(sf::Event& event){};
    // virtual void onMouseButtonPressed(sf::Event& event) {};
    // virtual void onMouseButtonRelease(sf::Event& event) {};
    // virtual void onMouseMoved(sf::Event& evt) {};


protected:

    Game* m_game;
    
};
