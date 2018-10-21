#pragma once

class GameState {
public:
	GameState() {}
	~GameState() {}

	virtual void update(float deltams) = 0;
	virtual void draw() = 0;
	virtual void handleInput() = 0;
};