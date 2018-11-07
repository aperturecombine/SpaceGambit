#pragma once
#include "GameState.h"
#include "RocketShip.h"
#include <iostream>
#include <vector>
#include <math.h>

class PlayState : public GameState {
public:
	PlayState() {}
    PlayState(class GameStateManager *gsm);
    
	virtual void update(float deltams);
    virtual void draw(sf::RenderWindow *window);
    virtual void handleInput();

	void checkCollisions();

    RocketShip ship1;
    RocketShip ship2;
    
private:
    GameStateManager *gsm;
    sf::Texture texture;
    sf::Sprite background;
    sf::Image image;

	std::vector<class Turret *> turrets;
};
