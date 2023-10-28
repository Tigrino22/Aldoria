#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Player.hpp"


// class Game;

class GameState : public State
{
public:
    GameState(Game* m_game);
    virtual ~GameState();

    void init() override;
    void updateEvent() override;
    void update(const sf::Int32 &dt = 0) override;
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

    void loadPlayerTexture(){};

    sf::RectangleShape carre;
    

    // Variable de communication avec m_game
    bool isRunningState;

    // Texture du joueur
    Player m_player;
    sf::Texture m_playerTexture;

};
