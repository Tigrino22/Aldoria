#include "MenuState.hpp"

#include <iostream>

MenuState::MenuState(Game* game)
: State(game){
    this->init();
}

MenuState::~MenuState(){
    
}

void MenuState::init() {
    
    this->setFont();
    m_menuText.setFont(m_font);
    m_menuText.setFillColor(sf::Color::Blue);
    m_menuText.setPosition(350.f, 280.f);
    m_menuText.setCharacterSize(18);
    m_menuText.setString("Bienvenue dans Aldoria\nPress Space to play!");
}

void MenuState::update(const float &dt) {

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


    target.draw(m_menuText);
}

void MenuState::endState() {

}

void MenuState::handleEvent(sf::Event& event){
    if(event.type == sf::Event::KeyPressed){
        onKeyPressed(event);
    }
}

void MenuState::onKeyPressed(sf::Event& event){
    if(event.key.code == sf::Keyboard::Space){
        this->m_game->pushState(1);
    }
}

void MenuState::setFont()
{
    if(!m_font.loadFromFile("res/font/Pixelify/static/PixelifySans-Regular.ttf")){
        std::cout << "Error::MenuState::SetFont : Failed to load font" << std::endl;
    }
}