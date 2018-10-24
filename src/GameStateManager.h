#pragma once
#include <stack>
#include "MenuState.h"

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
};};
