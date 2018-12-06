#pragma once
#include <stack>
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "FinishState.h"
#include "PickState.h"
#include "OptionState.h"
#include "../Entities/Ships/RocketShip.h"
#include "../Renderer.h"
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
	void returnToMenu();
    int numPlayer = 2;
    sf::View gameView;

	GameState * getTop() {
		return states.top();
	}

	sf::RenderWindow window;
	int winners;
	int stages;

	bool running;

	class Renderer * renderer;
private:
	std::stack<class GameState*> states;

};
