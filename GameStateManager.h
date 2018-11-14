#pragma once
#include <stack>
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "FinishState.h"
<<<<<<< HEAD:GameStateManager.h
#include "OptionState.h"
=======


>>>>>>> box2d_include:GameStateManager.h
#include "../Entities/Ships/RocketShip.h"
#include <SFML/Graphics.hpp>

#define MENUSTATE 0
#define PLAYSTATE 1
#define FINISHSTATE 2
<<<<<<< HEAD:GameStateManager.h
#define OPTIONSTATE 3
=======
#define PICKSTATE 3
>>>>>>> box2d_include:GameStateManager.h

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
