#include <iostream>
#include <stdlib.h>
#include "MenuState.h"

MenuState::MenuState(class GameStateManager *g) {
	gsm = g;
	currentChoice = 0;
	
	if (!font.loadFromFile("resources/aerial.ttf")) {
		 printf("Could not load font");
	}

    if(!texture.loadFromFile("resources/background.png")) {
		printf("Could not load background");
    }

    background.setTexture(texture);

    background.setPosition(0, 0);
    background.setScale(20.f, 20.f);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
}

void MenuState::update(float deltams) {}

void MenuState::draw(sf::RenderWindow *window) {
    gsm->window.clear(sf::Color(255,255,255));
    gsm->window.draw(background);
	text.setCharacterSize(70);
	text.setString("Space Gambit");
    centerText(&text, SCREENHEIGHT*0.1);
	gsm->window.draw(text);
    
	text.setCharacterSize(24);
    
	for (int i = 0; i < 3; i++) {
		if (i == currentChoice)
			text.setString("> " + options[i] + " <");
        else
			text.setString(options[i]);
		centerText(&text, 300 + i * 40);
		gsm->window.draw(text);
	}
}

void MenuState::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		moveUp();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		moveDown();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		select();
}

void MenuState::centerText(sf::Text *text, int y) {
	sf::FloatRect textRect = text->getLocalBounds();
	text->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text->setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, y));
}

void MenuState::select() {
	if (currentChoice == 0)
		gsm->pushState(PLAYSTATE);
    if (currentChoice == 1)
        gsm->pushState(OPTIONSTATE);
	if (currentChoice == 2)
		gsm->popState();
}
