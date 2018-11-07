
#pragma once
#include "Bullet.h"

class GuidedBullet : public Bullet {
public:
    GuidedBullet(sf::Vector2f p, sf::Vector2f v);
    ~GuidedBullet();
    
    virtual void update(float dt);
    
    bool isAlive;
    
private:
    float speed;
};
