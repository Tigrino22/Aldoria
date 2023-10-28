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
    m_player.loadSprite("res/characterSprite.jpg");

}

/**
 * 
 *  Fonciton prise en compte des direction du joueur et bouge le joueur avec 
 *  l'appel de la méthode move().
 * 
 *  Return void
*/
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
        m_player.setDirection(Direction::Right);
    }
}

void GameState::update(const sf::Int32 &dt)
{

    // Mise à jour des informations prise par le clavier.
    this->updateEvent();
    this->m_player.update(dt);
    
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
