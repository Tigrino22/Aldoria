#include "GameState.hpp"

GameState::GameState()
{
}

GameState::~GameState()
{
    this->init();
}

void GameState::init()
{
    carre.setSize(sf::Vector2f(100.f, 100.f));
    carre.setPosition(sf::Vector2f(100.f, 100.f));
    carre.setFillColor(sf::Color::Black);
}

void GameState::update(const float &dt)
{

}

void GameState::render(sf::RenderTarget &target)
{
    target.draw(carre);
}

void GameState::cleanUp()
{
}
