#pragma once
#include "rocketShip.h"
#include "Turret.h"
#include "GameState.h"
#include "GameStateManager.h"


class PlayState : public GameState {
public:
    PlayState(class GameStateManager *gsm);
    virtual void update(float deltams);
    virtual void draw(sf::RenderWindow *window);
    virtual void handleInput(sf::Event event);
    virtual void handleInput();
    rocketShip ship1;
    rocketShip ship2;
    turret t1 = turret(600, 20, ship1.getRocketPosition(), ship2.getRocketPosition());
//    turret t2 = turret(600,500, ship1.getRocketPosition(), ship2.getRocketPosition());
    
private:
    GameStateManager *gsm;
    
};

