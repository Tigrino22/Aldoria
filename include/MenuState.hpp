#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"


class MenuState : public State
{
public:
    MenuState(Game* game);
    virtual ~MenuState();

    void init() override;
    void update(const float &dt = 0.0) override;
    void render(sf::RenderTarget &target) override;
    void endState() override; // Peut aussi gérer les sauvegardes

    void handleEvent(sf::Event& event) override;
    void onKeyPressed(sf::Event& event) override;
    // void onKeyRelease(sf::Event& event){};
    // void onMouseButtonPressed(sf::Event& event) {};
    // void onMouseButtonRelease(sf::Event& event) {};
    // void onMouseMoved(sf::Event& evt) {};


private:

// Game

    void setFont();
    sf::Font m_font;
    sf::Text m_menuText;

};