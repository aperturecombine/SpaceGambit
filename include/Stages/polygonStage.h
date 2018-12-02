#include "Box2D/Box2D.h"
#include "Stages.h"
class polygonStage : public Stages {

public:


    polygonStage(sf::Vector2f p);
    //PlayState *ref;
    polygonStage();
    sf::Sprite boundary;
    sf::Texture boundaryTexture;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    sf::Vector2f p;
    void attachBoundary();

    b2ChainShape* backgroundShape;

    void attachRandomJunctions();
    void draw(sf::RenderWindow *window);
    b2ChainShape* getBoundaryShape();
};
