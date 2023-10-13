#include "GameState.hpp"


GameState::GameState(Game* game)
: State(game)
{
    this->init();
}

GameState::~GameState()
{

}

void GameState::init()
{
    carre.setSize(sf::Vector2f(100.f, 100.f));
    carre.setPosition(sf::Vector2f(100.f, 100.f));
    carre.setFillColor(sf::Color::Black);
}

void GameState::update(const float &dt)
{
    if(m_move){
        carre.setPosition(sf::Vector2f(carre.getPosition().x + m_VELOCITY_X, carre.getPosition().y + m_VELOCITY_Y));

        if(carre.getPosition().x >= m_game->getWindow().getSize().x - carre.getSize().x){
            carre.setPosition(sf::Vector2f(m_game->getWindow().getSize().x - carre.getSize().x, carre.getPosition().y));
            m_VELOCITY_X *= -1;
        }
        if(carre.getPosition().x <= 0){
            carre.setPosition(0, carre.getPosition().y);
            m_VELOCITY_X *= -1;
        }

        if(carre.getPosition().y >= m_game->getWindow().getSize().y - carre.getSize().y){
            carre.setPosition(sf::Vector2f(carre.getPosition().x, m_game->getWindow().getSize().y - carre.getSize().y));
            m_VELOCITY_Y *= -1;
        }
        if(carre.getPosition().y <= 0){
            carre.setPosition(carre.getPosition().x, 0);
            m_VELOCITY_Y *= -1;
        }
    }
    
}

void GameState::render(sf::RenderTarget &target)
{
    target.draw(carre);
}

void GameState::endState()
{
}

// Event
void GameState::handleEvent(sf::Event& event) {
    if(event.type == sf::Event::KeyPressed){
        onKeyPressed(event);
    }
}

void GameState::onKeyPressed(sf::Event& event){
    if(event.key.code == sf::Keyboard::Space){
        if(m_move == false){
            m_move = true;
        }else{
            m_move = false;
        }
    }
    if(event.key.code == sf::Keyboard::Up){
        if (m_VELOCITY_X >= 0){
            m_VELOCITY_X++;
        }else
        {
            m_VELOCITY_X--;
        }
        if (m_VELOCITY_Y >= 0){
            m_VELOCITY_Y++;
        }else
        {
            m_VELOCITY_Y--;
        }
        
        
    }
    if(event.key.code == sf::Keyboard::Down){
        if (m_VELOCITY_X >= 0){
            m_VELOCITY_X--;
        }else
        {
            m_VELOCITY_X++;
        }
        if (m_VELOCITY_Y >= 0){
            m_VELOCITY_Y--;
        }else
        {
            m_VELOCITY_Y++;
        }
    }
}
