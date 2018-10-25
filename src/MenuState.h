#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
class MenuState : public GameState {
public:
	MenuState(class GameStateManager& gsm);
	virtual void update();
	virtual void draw();
    virtual void handleInput();
    

private:
    void Init(class GameStateManager& gsm);
    bool MenuState::isClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
};
