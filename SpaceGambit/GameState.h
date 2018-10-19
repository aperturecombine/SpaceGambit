#pragma once

class GameState {
public:
	GameState() {}
	~GameState() {}

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void handleInput() = 0;
};