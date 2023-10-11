#pragma once

#include <iostream>
#include <stack>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "State.hpp"
#include "GameState.hpp"


class Game
{
public:
    Game();
    virtual ~Game();

// Updating functions
    void updateDt();
    void updateEvent();
    void update();

// Rendering funcitons
    void render();

// Running function
    void run();

private:
// Function init
    void initWindow();
    void initStates();
// Environnement variables
    sf::RenderWindow m_window;
    sf::Event m_event;
    
    GameState m_gameState;

// Time variables
    sf::Clock m_dtClock;
    float m_dt;

    
};