#include "Box2D/Box2D.h"
#include "Stages.h"

class squareStage : public Stages {

public:
    squareStage();
    squareStage(sf::Vector2f p);
    //PlayState *ref;
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
