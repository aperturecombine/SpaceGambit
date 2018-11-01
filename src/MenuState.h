#pragma once
#include "GameState.h"
#include "PlayState.h"
#include "GameStateManager.h"
#include <string.h>
#include <SFML/Graphics.hpp>

class MenuState : public GameState {
public:
	MenuState(class GameStateManager *gsm);
	virtual void update(float deltams);
	virtual void draw(sf::RenderWindow *window);
	virtual void handleInput(sf::Event event);
    virtual void handleInput();

private:
	GameStateManager *gsm;
    sf::Image image;
	sf::Font font;
	sf::Text text;
    sf::Texture texture;
    sf::Sprite background;
    
	int currentChoice;
	std::string options[3] = { "Play", "Options", "Quit" };

	void moveUp() {
		currentChoice--;
		if (currentChoice < 0)
			currentChoice = 2;
	}
	void moveDown() {
		currentChoice++;
		if (currentChoice > 2)
			currentChoice = 0;
	}

	void centerText(sf::Text *text, int y);

	void select();
};
