#pragma once
#include <stack>
#include "MenuState.h"
#include <SFML/Graphics.hpp>

class GameStateManager {
public:
	GameStateManager();
	~GameStateManager() {}

	void start();
	void pushState(GameState* state);
	void popState();

private:
	std::stack<class GameState*> states;
	int currentState;

	bool running;
};
