#pragma once
#include "../States/GameState.h"
#include "../Entities/Ships/RocketShip.h"
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
    virtual void handleInput(sf::Event event);

    void pWInit();
	void checkCollisions();

    RocketShip ship1;
    RocketShip ship2;
    
    b2World* world;
    std::vector<class Turret *> turrets;

    float stageTimer;
    int level;

    
private:
    b2Vec2 gravity{0,0};
    
    b2Body* bShip1;
    b2Body* bShip2;
    virtual void generateTurrets();
    virtual void resetTurrets();
    virtual void turretSelect(int i, sf::Vector2f p);
    float turretCount;
    virtual int randomButNotRandomSelector();
    int turretCounter[6] = {1,2,3,4,5,6};

    GameStateManager *gsm;
    sf::Texture texture;
    sf::Sprite background;
    sf::Image image;
    sf::RectangleShape shipHealth1;
    sf::RectangleShape shipHealth2;

    std::vector<class b2Body *> bTurret;
    
//    sf::Vector2f(SCREENWIDTH*(2/8),SCREENHEIGHT*(6/8))
    
    sf::Vector2f turretLayout[3][4];
    
    
    
    
};
