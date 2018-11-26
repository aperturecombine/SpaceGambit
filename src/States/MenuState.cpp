#include <iostream>
#include <stdlib.h>
#include "../../include/States/MenuState.h"

MenuState::MenuState(class GameStateManager *g) {
	gsm = g;
	currentChoice = 0;
	
	if (!font.loadFromFile("resources/spaceranger.ttf")) {
		 printf("Could not load font");
	}

    if(!texture.loadFromFile("resources/space_real.jpg")) {
		printf("Could not load background");
    }

    background.setTexture(texture);

    background.setPosition(0, 0);
    background.setScale(1.5f, 1.5f);
    text.setFont(font);
    text.setFillColor(sf::Color::White);

	gsm->window.setKeyRepeatEnabled(false);
}

void MenuState::update(float deltams) {}

void MenuState::draw(sf::RenderWindow *window) {
    gsm->window.clear(sf::Color(255,255,255));
    gsm->window.draw(background);
	text.setCharacterSize(175);
	text.setString("Space Gambit");
    centerText(&text, SCREENHEIGHT*0.1);
	gsm->window.draw(text);
    
	text.setCharacterSize(70);
    
	for (int i = 0; i < 3; i++) {
		if (i == currentChoice)
			text.setString("> " + options[i] + " <");
        else
			text.setString(options[i]);
		centerText(&text, SCREENHEIGHT*0.2 + i * 100);
		gsm->window.draw(text);
	}
}

void MenuState::handleInput(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up)
            moveUp();
        else if (event.key.code == sf::Keyboard::Down)
            moveDown();
        else if (event.key.code == sf::Keyboard::Space)
            select();
//        switch (event.key.code) {
//            case sf::Keyboard::Up:
//                    moveUp();
//                    break;
//            case sf::Keyboard::Down:
//                    moveDown();
//                    break;
//            case sf::Keyboard::Space:
//                    select();
//                    break;
//        }
	}
}

void MenuState::centerText(sf::Text *text, int y) {
	sf::FloatRect textRect = text->getLocalBounds();
	text->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text->setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, y));
}

void MenuState::select() {
	if (currentChoice == 0)
		gsm->pushState(PICKSTATE);
    if (currentChoice == 1)
        gsm->pushState(OPTIONSTATE);
	if (currentChoice == 2)
		gsm->popState();
}
