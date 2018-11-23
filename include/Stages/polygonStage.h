#include "Stages.h"

class polygonStage : public Stages {

public:

    polygonStage();

    //PlayState *ref;

    void attachRandomJunctions();
    void draw(sf::RenderWindom *window);
    b2ChainShape* getBoundaryShape();
}
