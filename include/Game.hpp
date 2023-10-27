#pragma once

#include <iostream>
#include <stack>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "State.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"




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

// Manage States
    void pushState(int choise);
    sf::RenderWindow& getWindow();

private:
// Function init
    void initWindow();
    void initStates();
// Environnement variables
    sf::RenderWindow m_window;
    sf::Event m_event;
    

// Time variables
    sf::Clock m_dtClock;
    float m_dt;

// States
    std::stack<State*> m_states;

    
};