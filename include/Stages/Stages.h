#pragma once

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

class Stages {

public:
    sf::Sprite boundary;
    sf::Texture boundaryTexture;
    sf::Vector2f pos;
    void attachBoundary();
    b2ChainShape* getBoundaryShape();
    b2ChainShape* backgroundShape;
    //std::vector<class Turret *> turrets;

    virtual void draw (sf::RenderWindow *window);

    void loadFont();


};
