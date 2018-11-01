#pragma once
#include <stack>
#include "MenuState.h"
#include "PlayState.h"
#include "FinishState.h"
#include "rocketShip.h"
#include <SFML/Graphics.hpp>

class GameStateManager {
public:
	GameStateManager();
	~GameStateManager() {}

	void start();
	void pushState(GameState* state);
	void popState();

	sf::RenderWindow window;

private:
	std::stack<class GameState*> states;
	int currentState;

	bool running;
};
