#include "Game.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"

// Constructors

Game::Game()
{  
    this->initWindow();
    this->initStates();
}

Game::~Game()
{

}

// Initialisation

void Game::initWindow()
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    m_window.create(sf::VideoMode(800, 600), "My window", sf::Style::Default, settings);
    m_window.setVerticalSyncEnabled(true);


}

void Game::initStates()
{
    m_states.push(new MenuState(this));
}

// Functions

// // Updating
void Game::updateDt()
{
    // Update the time variable 1 per frame
    m_dt = m_dtClock.restart().asSeconds();
    
}

void Game::updateEvent()
{
    while(m_window.pollEvent(m_event)){
        if(m_event.type == sf::Event::Closed){
            m_window.close();
        }else{
            // Transfert les events au state prioritaire, CàD celui au top de la pile
            if(!m_states.empty()){
                m_states.top()->handleEvent(m_event);
            }
        }

    }
}

void Game::update()
{
    this->updateDt();
    this->updateEvent();
    if(!m_states.empty()){
        m_states.top()->update(m_dt);
    }
}

// // Rendering
void Game::render()
{

   m_window.clear(sf::Color::White);
    
    // Render items
    // ...
    // Rendu de l'état supérieur de la pile
    if(!m_states.empty()){
        m_states.top()->render(m_window);
    }
    

    m_window.display();
}

// // Running
void Game::run()
{
    while (m_window.isOpen())
    { 
        this->updateDt();
        this->update();
        this->render();
    }
}

void Game::pushState(int choise)
{
    switch (choise)
    {
    case 1:
        m_states.push(new GameState(this));
        break;
    
    default:
        break;
    }

}

sf::RenderWindow& Game::getWindow()
{
    return m_window;
}
