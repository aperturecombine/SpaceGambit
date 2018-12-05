#pragma once
#include "../States/GameState.h"
#include "../Entities/Ships/RocketShip.h"
#include <iostream>
#include <vector>
#include <math.h>
#include "Box2D/Box2D.h"
#include "../Entities/Powerups/Powerup.h"
#include "../Entities/Bullets/Bludger.h"


class PlayState : public GameState {
public:
    PlayState() {}
    PlayState(class GameStateManager *gsm, int numPlayer, int ship1type, int ship2type);

    virtual void update(float deltams);
    virtual void draw(sf::RenderWindow *window);
    virtual void handleInput(sf::Event event);

    void pWInit();
    void checkCollisions();
    void createPowerUps();

    RocketShip ship1;
    RocketShip ship2;

    Bludger bludger;

    b2World* world;
    std::vector<class Turret *> turrets;

    float stageTimer;
    int level;
    bool twoPlayerMode = true;

	bool pause = false;

	std::vector<class Powerups *> powerups;
  void nextStageFunction();
  int nextStageCounter = 0;
  int nextStage = 0;
  int nextStageContinue = true;

  sf::ConvexShape triangle1;
  sf::ConvexShape triangle2;
  sf::ConvexShape triangle3;
  sf::ConvexShape triangle4;


  void setShipTypes(int s1, int s2) {
	  ship1.shipType = s1;
	  ship2.shipType = s2;
	}

private:
	//chain.CreateChain(vs,6);
	b2ChainShape backgroundShapeb;

    //polygonStage stage;
    b2Vec2 gravity{0,0};

    b2Body* bShip1;
    b2Body* bShip2;
    virtual void generateTurrets();
    virtual void resetTurrets();
    virtual void turretSelect(int i, sf::Vector2f p);
    virtual void loadPauseFonts();
    float turretCount;
    virtual int randomButNotRandomSelector();
    int turretCounter[6] = {1,2,3,4,5,6};

    GameStateManager *gsm;
    sf::Texture texture;
    sf::Texture hudTexture;
    sf::Sprite background;
    sf::Image image;
    sf::RectangleShape shipHealth1;
    sf::RectangleShape shipHealth2;

    sf::RectangleShape pauseState;
    sf::Texture pauseTexture;
    sf::Sprite pauseSprite;

    // powerups
    sf::Texture textureP1;
    sf::Sprite sP1;

    sf::Texture textureP2;
    sf::Sprite sP2;

    sf::Texture textureP3;
    sf::Sprite sP3;

    sf::Texture textureP4;
    sf::Sprite sP4;


//    sf::Vector2f(SCREENWIDTH*(2/8),SCREENHEIGHT*(6/8))
};
