#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
// class Game;



class GameState : public State
{
public:
    GameState(Game* m_game);
    virtual ~GameState();

    void init() override;
    void update(const float &dt = 0.0) override;
    void render(sf::RenderTarget &target) override;

    void endState() override; // Peut aussi gérer les sauvegardes
    bool getIsRunning() override;

    void handleEvent(sf::Event& event) override;
    void onKeyPressed(sf::Event& event) override;
    // void onKeyRelease(sf::Event& event){};
    // void onMouseButtonPressed(sf::Event& event) {};
    // void onMouseButtonRelease(sf::Event& event) {};
    // void onMouseMoved(sf::Event& evt) {};


private:

    sf::RectangleShape carre;
    int m_VELOCITY = 3;
    int m_VELOCITY_X = m_VELOCITY;
    int m_VELOCITY_Y = m_VELOCITY;

    bool m_move = false;

    // Variable de communication avec m_game
    bool isRunningState;

};
