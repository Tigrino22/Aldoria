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
    /**
     * 
     *  Initialisation des variables
     *  L'état est en cours
     * 
     *  Génération du joueur
     * 
     *  Return void
     * 
    */

    isRunningState = true;

    
}

void GameState::updateEvent()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        m_player.move(0, m_player.getVelocity() * (-1));
        m_player.setDirection(Direction::Up);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        m_player.move(0, m_player.getVelocity() * (1));
        m_player.setDirection(Direction::Down);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        m_player.move(m_player.getVelocity() * (-1), 0);
        m_player.setDirection(Direction::Left);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        m_player.move(m_player.getVelocity() * (1), 0);
        m_player.setDirection(Direction::Left);
    }
}

void GameState::update(const float &dt)
{

    // Mise à jour des informations prise par le clavier.
    this->updateEvent();
    
}

void GameState::render(sf::RenderTarget &target)
{
    m_player.draw(target);
}

// Gestion de l'état en cours

void GameState::endState()
{
    isRunningState = false;
}

bool GameState::getIsRunning()
{
    return isRunningState;
}

// Event
void GameState::handleEvent(sf::Event& event) {

    if(event.type == sf::Event::KeyPressed){
        onKeyPressed(event);
    }
}

void GameState::onKeyPressed(sf::Event& event){
    if(event.key.code == sf::Keyboard::Space){}
    
    if(event.key.code == sf::Keyboard::Escape){
        this->endState();  
    }

}
