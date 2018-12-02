#pragma once
#include <stack>
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "FinishState.h"
#include "PickState.h"
#include "OptionState.h"
#include "../Entities/Ships/RocketShip.h"
#include <SFML/Graphics.hpp>

#define MENUSTATE 0
#define PLAYSTATE 1
#define FINISHSTATE 2
#define OPTIONSTATE 3
#define PICKSTATE 4
#define SINGLEPLAYERFINISHSTATE 5
#define TWOPLAYERFINISHSTATE 6

class GameStateManager {
public:
	GameStateManager();
	~GameStateManager() {}

	void start();
	void pushState(int newState);
	void popState();
    int numPlayer = 2;

	GameState * getTop() {
		return states.top();
	}

	sf::RenderWindow window;

private:
	class Renderer * renderer;
	std::stack<class GameState*> states;

	bool running;
};