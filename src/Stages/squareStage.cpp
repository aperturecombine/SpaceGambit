#include "../../include/Stages/squareStage.h"

squareStage::squareStage(sf::Vector2f p){
    pos = p;
    attachBoundary();
    attachRandomJunctions();

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
