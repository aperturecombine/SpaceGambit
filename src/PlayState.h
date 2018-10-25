#pragma once
#include "rocketShip.h"
#include "GameState.h"
#include "GameStateManager.h"


class PlayState : public GameState {
public:
    PlayState(class GameStateManager& gsm);
    void update(float deltams);
    void draw(sf::RenderWindow *window);
    void handleInput();
    rocketShip ship1;
    rocketShip ship2;
};
