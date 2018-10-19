#include "GameStateManager.h"


GameStateManager::GameStateManager() {
	this->currentState = MENUSTATE;
	this->states.push(new MenuState(*this));

	running = true;
}

void GameStateManager::start() {
	while (running) {
		this->states.top()->update();
		this->states.top()->draw();
	}
}