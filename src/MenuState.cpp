#include <iostream>
#include <stdlib.h>
#include "MenuState.h"

MenuState::MenuState(class GameStateManager *g) {
	gsm = g;
	currentChoice = 0;
	
 if (!font.loadFromFile("../resources/aerial.ttf"))
    {
       std::cout << "Could not load font." << std::endl;
   }
    
    
    if(!texture.loadFromFile("../resources/background.png"))
        return -1;
    background.setTexture(texture);
    
    background.setPosition(0, 0);
    auto size = background.getTexture()->getSize();
    background.setScale(10, 10);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
}

void MenuState::update(float deltams) {
  
}

void MenuState::draw(sf::RenderWindow *window) {
    
    gsm->window.clear(sf::Color(255,255,255));
    gsm->window.draw(background);
	text.setCharacterSize(70);
	text.setString("Space Gambit");
	centerText(&text, 150);
	gsm->window.draw(text);
    
	text.setCharacterSize(24);
    
	for (int i = 0; i < 3; i++) {
		if (i == currentChoice)
        {
			text.setString("> " + options[i] + " <");
        }
        else{
			text.setString(options[i]);
            
        }
		centerText(&text, 300 + i * 40);
		gsm->window.draw(text);
	}

}

void MenuState::handleInput(sf::Event event) {
	gsm->window.setKeyRepeatEnabled(false);
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up)
			moveUp();
		if (event.key.code == sf::Keyboard::Down)
			moveDown();
		if (event.key.code == sf::Keyboard::Space)
			select();
    
	}
}

void MenuState::handleInput() {
}


void MenuState::centerText(sf::Text *text, int y) {
	sf::FloatRect textRect = text->getLocalBounds();
	text->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text->setPosition(sf::Vector2f(800 / 2.0f, y));
}

void MenuState::select() {
	if (currentChoice == 1)
		gsm->popState();
	if (currentChoice == 0)
		gsm-> pushState(new PlayState(gsm));
//    if (currentChoice == 4)
//        gsm -> pushState (new FinishState(gsm));
}


