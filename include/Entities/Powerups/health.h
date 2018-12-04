
#pragma once
#include <SFML/Graphics.hpp>
#include "Powerup.h"

#include "../../States/PlayState.h"
#include <iostream>
#include <vector>

class health : public Powerups {
public:

    health(sf::Vector2f p);
    int type;



};
