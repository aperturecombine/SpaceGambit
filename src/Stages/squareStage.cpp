#include "./Stages/squareStage.h"

squareStage::squareStage(sf::Vector2f p){
    pos = p;
    loadFont();
    attachBoundary();
    attachRandomJunctions();

}

void squareStage::loadFont(){
    //load Textures
    backgroundTexture.loadFromFile("resources/background.png");
    background.setTexture(backgroundTexture);
    background.setScale(1.0f,1.0f);
    background.setPosition(p);
    boundaryTexture.loadFromFile("resources/boundaryTexture.png");
    boundary.setTexture(boundaryTexture);
    boundary.setScale(1.0f,1.0f);
    boundary.setPosition(p);
}

void squareStage::attachBoundary(){
    b2Vec2 vs[4];
    vs[0].Set(0,0);
    vs[1].Set(0,800);
    vs[2].Set(800,800);
    vs[3].Set(800,0);

    backgroundShape->CreateLoop(vs,4);

}


void squareStage::draw( sf::RenderWindow *window){

    //draw arena structure

    window->draw(boundary);

}

b2ChainShape* squareStage::getBoundaryShape(){
    return backgroundShape;
}

void squareStage::attachRandomJunctions(){

}
