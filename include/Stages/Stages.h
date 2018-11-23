#pragma once

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

class Stages {

public:
    sf::Sprite background;
    sf::Texture backgroundTexture;
    
    void attachBoundary();
    b2ChainShape* getBoundaryShape();

    //std::vector<class Turret *> turrets;
    
    virtual void draw (sf::RenderWindow *window);
    
    void loadFont();

    
}

