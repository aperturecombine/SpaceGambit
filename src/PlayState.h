#pragma once
#include "rocketShip.h"
#include "Turret.h"
#include "MenuState.h"
#include "FinishState.h"
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
    turret t1 = turret(600, 200);
    turret t2 = turret(600,600);
    
private:
    GameStateManager *gsm;
    sf::Texture texture;
    sf::Sprite background;
    sf::Image image;
};

