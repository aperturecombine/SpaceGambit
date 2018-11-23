#include "./Stages/polygonStage.h"

polygonStage::polygonStage(sf::Vector2f p){
    pos = p;
    loadFont();
    attachBoundary();
    attachRandomJunctions();

}

void polgonStage::loadFont(){
    //load Textures
    backgroundTexture.loadFromFile("resources/background.png");
    background.setTexture(backgroundTexture);
    background.setScale(1.0f,1.0f);
    background.setPosition(p);
    boundaryTexture.loadFromFile("resources/boundaryTexture.png")
    boundary.setTexture(boundaryTexture);
    boundary.setScale(1.0f,1.0f);
    boundary.setPosition(p);
}

void polygonStage::attachBoundary(){
    b2Vec2 vs[4];
    vs[0].Set(0,300);
    vs[1].Set(0,1500);
    vs[2].Set(400,1800);
    vs[3].Set(800,1500);
    vs[4].Set(800,300);
    vs[5].Set(800,300);

    //chain.CreateChain(vs,6);
    chain.CreateLoop(vs, 6);

}

void polygonStage::draw( window){

    //draw arena structure
    window->draw(backgroundTexture);
    window->draw(boundary);

}

b2PolygonShape* polygonStage::getBoundaryShape(){
    return backgroundShape;
}

void polygonStage::attachRandomJunctions(){

}
