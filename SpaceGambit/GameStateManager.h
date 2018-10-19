#pragma once
#include <stack>
#include "MenuState.h"

class GameStateManager {
public:
	static const int MENUSTATE = 0;
	static const int FIRSTLEVELSTATE = 1;

	GameStateManager();
	~GameStateManager() {}

	void start();

private:
	std::stack<class GameState*> states;
	int currentState;

	bool running;
};