#include "MenuState.h"
#include "GameStateManager.h"
#include <iostream>
#include "globalVars.h"



/**
 * Menu for input of the game
 * 
 * The menu consists of three buttons 
 * Survival Mode
 * Player Verses Mode
 * Exit 
 * 
 * The first two buttons take the player into the next two states within the game
 * 
 **/




MenuState::MenuState(class GameStateManager& gsm) 
{
    this->window = sf::RenderWindow window(sf::VideoMode(800, 600));
    Init( gsm )
    
}

void MenuState::update() {

	
}

void MenuState::Init (class GameStateManager& gsm)
{
    this->_gsm->renderer.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
    this->_gsm->renderer.LoadTexture("Survival", SURVIVAL_BUTTON);
    this->_gsm->renderer.LoadTexture("Player Verses", TWO_PLAYER_BUTTON);
    this->_gsm->renderer.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

    this->_background.setTexture(this->_gsm->renderer.GetTexture("Background"));
    this->_survivalButton.setTexture(this->_gsm->renderer.GetTexture("Survival"));
    this->_playerVerses.setTexture(this->_gsm->renderer.GetTexture("Player Verses"));
    this->_title.setTexture(this->_gsm->renderer.GetTexture("Game Title"));
    this->_quitButton.setTexture(this->_gsm-> renderer.GetTexture("Quit"))

    this->_survivalButton.setPosition (SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 100);
    this->_playerVerses.setPosition (SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2));
    
    this->window->_title.setPosition (SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 50);
    this->window->_quitButton.setPosition (SCREEN_WIDTH / 2, SCREEN_HEIGHT/2 -100);
    
}   
void MenuState::draw() {

    this->window.clear(sf::Color::Red);
    
    this->window.draw(this->_background);
    this->window.draw(this->_playButton);
    this->window.draw(this->_survivalButton);
    this->window.draw(this->_title);
    
    this->window.display();
	
}

void MenuState::handleInput() 

{
    sf::Event event;

    while (this->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->window.close();
        }

        if (isCLicked(this->_quitButton, sf::Mouse::Left, this->window))
        {
            this->window.close();
        }

        if (isClicked(this->_survivalButton, sf::Mouse::Left, this->window))
        {
            std::cout << "Go To Survival Game Screen" << std::endl;
        }

        if (isClicked(this->_playerVerses, sf::Mouse::Left, this->window))
        {
            std::cout << "Go To 2 player Game Screen" << std::endl;
        }
       
    }
}

bool MenuState::isClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

        if (playButtonRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }

    return false;
}
