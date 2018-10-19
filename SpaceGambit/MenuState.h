#pragma once
#include "GameState.h"

class MenuState : public GameState {
public:
	MenuState(class GameStateManager& gsm);
	virtual void update();
	virtual void draw();
	virtual void handleInput();
};