#pragma once
#include "./States/GameState.h"
#include "./Entities/Ships/RocketShip.h"
#include <iostream>
#include <vector>
#include <math.h>
#include "Box2D/Box2D.h"

class PlayState : public GameState {
public:
	PlayState() {}
    PlayState(class GameStateManager *gsm);
    
	virtual void update(float deltams);
    virtual void draw(sf::RenderWindow *window);
    virtual void handleInput();

    void pWInit();
	void checkCollisions();

    RocketShip ship1;
    RocketShip ship2;
    
    b2World* world;
    std::vector<class Turret *> turrets;
    
private:
    b2Vec2 gravity{0,0};
    
    b2Body* bShip1;
    b2Body* bShip2;

    GameStateManager *gsm;
    sf::Texture texture;
    sf::Sprite background;
    sf::Image image;
    sf::RectangleShape shipHealth1;
    sf::RectangleShape shipHealth2;

    std::vector<class b2Body *> bTurret;
};
