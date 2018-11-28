
#pragma once
#include <SFML/Graphics.hpp>
#include "Powerup.h"

#include "../../States/PlayState.h"
#include <iostream>
#include <vector>

class speed : public Powerups {
public:

    speed(sf::Vector2f p);
    int type = 2;


};
