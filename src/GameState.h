#pragma once
#include <SFML\Graphics.hpp>

class GameState {
public:
	GameState() {}
	~GameState() {}

	virtual void update(float deltams) = 0;
	virtual void draw() = 0;
	virtual void handleInput(sf::Event event) = 0;
};
