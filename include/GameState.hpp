#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"



class GameState : public State
{
public:
    GameState();
    virtual ~GameState();

    void init() override;
    void update(const float &dt) override;
    void render(sf::RenderTarget &target) override;
    void cleanUp() override; // Peut aussi gérer les sauvegardes

    void handleEvent(sf::Event& event) {};
    void onKeyPressed(sf::Event& event){};
    void onKeyRelease(sf::Event& event){};
    void onMouseButtonPressed(sf::Event& event) {};
    void onMouseButtonRelease(sf::Event& event) {};
    void onMouseMoved(sf::Event& evt) {};


private:

    sf::RectangleShape carre;

};
