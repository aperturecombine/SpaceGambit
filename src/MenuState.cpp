#include "MenuState.h"
#include "GameStateManager.h"
#include <iostream>

MenuState::MenuState(class GameStateManager *g) {
	gsm = g;
	currentChoice = 0;
	
	if (!font.loadFromFile("/Users/liuwukun/Documents/GitHub_workspace/SpaceGambit/src/aerial.ttf"))
		printf("font load error");
    
    if(!image.loadFromFile("/Users/liuwukun/Documents/GitHub_workspace/SpaceGambit/src/background.png"))
        printf("image load error");
    texture.loadFromImage(image);
   
    sf::Vector2u WindowSize = gsm->window.getSize();             //Get size of window.


	text.setFont(font);
	text.setFillColor(sf::Color::White);
 
    background.setTexture(texture,true);
    
    background.setPosition(0, 0);
    sf::FloatRect Size = background.getGlobalBounds();
    float ScaleX = (float) WindowSize.x / Size.height;
    float ScaleY = (float) WindowSize.y / Size.width;     //Calculate scale.
    
    background.setScale(10,10);
}

void MenuState::update(float deltams) {

}

void MenuState::draw(sf::RenderWindow *window) {
    gsm->window.clear();
	gsm->window.draw(background);
  
	text.setCharacterSize(70);
	text.setString("Space Gambit");
	centerText(&text, 150);
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
	if (currentChoice == 2)
		gsm->popState();
	if (currentChoice == 0)
		gsm->pushState(new PlayState(gsm));
}
