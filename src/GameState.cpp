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
    m_player.loadSprite("res/characterSprites.png");

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
    // Appel des evenements des entity qui en ont besoin
    m_player.updateEvent();
}

void GameState::update(const sf::Int32 &dt)
{
    
    // Mise à jour des entités du jeu
    this->m_player.update(dt);
    this->updateEvent();
    
}

void GameState::render(sf::RenderTarget &target)
{

    // Rendu des entités du jeu
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
    if(event.type == sf::Event::KeyReleased){
        onKeyRelease(event);
    }
}

void GameState::onKeyPressed(sf::Event& event){
    if(event.key.code == sf::Keyboard::Space){}
    
    if(event.key.code == sf::Keyboard::Escape){
        this->endState();  
    }

    m_player.onKeyPressed(event);
}

// Prise en compte des informations claviers et 
//  Retransmises au besoin
void GameState::onKeyRelease(sf::Event &event)
{
    m_player.onKeyRelease(event);
}
