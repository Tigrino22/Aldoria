#include "MenuState.hpp"

#include <iostream>
#include <filesystem>

MenuState::MenuState(Game* game)
: State(game){


    this->init();
}

MenuState::~MenuState(){
    
}

void MenuState::init() {
    /**
     * Initialisation du Texte d'introduction de Aldoria
     * 
     * Return void
    */
    
    this->setFont();
    m_menuText.setFont(m_font);
    m_menuText.setFillColor(sf::Color::Blue);
    m_menuText.setPosition(350.f, 280.f);
    m_menuText.setCharacterSize(18);
    m_menuText.setString("Welcome in Aldoria\nPress Space to play!");
}

void MenuState::updateEvent()
{
}

void MenuState::update(const float &dt) {
    /**
     * Update de la position du texte à chaque frame
     * 
     * Return void
    */

    // Obtenez dimension de la fenêtre
    float windowWidth = static_cast<float>(m_game->getWindow().getSize().x);
    float windowHeight = static_cast<float>(m_game->getWindow().getSize().y);

    // Obtenez dimension du texte
    float textWidth = m_menuText.getLocalBounds().width;
    float textHeight = m_menuText.getLocalBounds().height;

    // Calculez la position X pour centrer le texte horizontalement
    float posX = (windowWidth - textWidth) / 2.0f;
    float posY = (windowHeight - textHeight) / 2.0f;
    

    // Appliquez la position X au texte
    m_menuText.setPosition(posX, posY); // Ajustez la position Y au besoin
    
}

void MenuState::render(sf::RenderTarget &target) {

    /**
     * Rendu simple du texte sur la target passée en paramètre
     * 
     * Return void
    */

    target.draw(m_menuText);
}

void MenuState::endState() {

    /**
     *  TODO
     *  Gestion de la variable isRunningState;
     *  Si False -> envoie un signal et Delete l'allocation dynamique 
     * 
     * 
     * 
    */

}

bool MenuState::getIsRunning()
{
    return true;
}

void MenuState::handleEvent(sf::Event& event){

    /**
     *  Simple fonction de redistribution selon 
     *  le type d'event passé en paramètre
     * 
     *  Return void
    */

    if(event.type == sf::Event::KeyPressed){
        onKeyPressed(event);
    }
}

void MenuState::onKeyPressed(sf::Event& event){

    /**
     * 
     *  Fonction princpale de gestion des input clavier
     * 
     *  Return void
    */
    if(event.key.code == sf::Keyboard::Space){
        this->m_game->pushState(CurrentState::Play);
    }
}

void MenuState::setFont()
{

    /**
     * 
     *  Initialisation de la police d'écriture
     * 
     *  Return void
     * 
    */
    std::string fontPath = std::filesystem::current_path().string() + "/res/font/Pixelify/static/PixelifySans-Regular.ttf";
    if(!m_font.loadFromFile(fontPath)){
        std::cout << "Error::MenuState::SetFont : Failed to load font" << std::endl;
    }
}