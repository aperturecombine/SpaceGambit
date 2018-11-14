#pragma once
#include "Bullet.h"

class BeamBullet : public Bullet {
public:
    BeamBullet(sf::Vector2f p, sf::Vector2f v, PlayState *ref);
    ~BeamBullet();
    
    virtual void update(float dt);
    float timePassed;
    
private:
    float speed;
};
