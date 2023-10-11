#include "GameState.hpp"

GameState::GameState()
{
}

GameState::~GameState()
{
    this->m_window = nullptr;
}

void GameState::init(sf::RenderWindow *window)
{

    this->m_window = window;

    carre.setSize(sf::Vector2f(100.f, 100.f));
    carre.setPosition(sf::Vector2f(100.f, 100.f));
    carre.setFillColor(sf::Color::Black);


}

void GameState::update(const float &dt)
{
    carre.setPosition(sf::Vector2f(carre.getPosition().x + m_VELOCITY_X, carre.getPosition().y + m_VELOCITY_Y));

    if(carre.getPosition().x >= m_window->getSize().x - carre.getSize().x){
        carre.setPosition(sf::Vector2f(m_window->getSize().x - carre.getSize().x, carre.getPosition().y));
        m_VELOCITY_X *= -1;
    }
    if(carre.getPosition().x <= 0){
        carre.setPosition(0, carre.getPosition().y);
        m_VELOCITY_X *= -1;
    }

    if(carre.getPosition().y >= m_window->getSize().y - carre.getSize().y){
        carre.setPosition(sf::Vector2f(carre.getPosition().x, m_window->getSize().y - carre.getSize().y));
        m_VELOCITY_Y *= -1;
    }
    if(carre.getPosition().y <= 0){
        carre.setPosition(carre.getPosition().x, 0);
        m_VELOCITY_Y *= -1;
    }
}

void GameState::render(sf::RenderTarget &target)
{
    target.draw(carre);
}

void GameState::cleanUp()
{
}
