/**
 * Header for circle Stage
 */

#include "Stages.h"

class squareStage : public Stages {
    
public:
    
    squareStage();
    
    //PlayState *ref;
    
    void attachRandomJunctions();
    void draw(sf::RenderWindom *window);
    b2ChainShape* getBoundaryShape();
}
