
#pragma once
#include "Bullet.h"

class GuidedBullet : public Bullet {
public:
    GuidedBullet(sf::Vector2f p, sf::Vector2f v, PlayState *ref);
    ~GuidedBullet();
    
    virtual void update(float dt);
    
private:
    float speed;
};
