#pragma once
#include <stack>
#include "MenuState.h"
#include "PlayState.h"
#include "FinishState.h"


#include "../Entities/Ships/RocketShip.h"
#include <SFML/Graphics.hpp>

#define MENUSTATE 0
#define PLAYSTATE 1
#define FINISHSTATE 2
#define PICKSTATE 3

class GameStateManager {
public:
	GameStateManager();
	~GameStateManager() {}

	void start();
	void pushState(int newState);
	void popState();

	sf::RenderWindow window;

private:
	std::stack<class GameState*> states;
	int currentState;

	bool running;
};
