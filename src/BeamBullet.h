
#pragma once
#include "Bullet.h"

class BeamBullet : public Bullet {
public:
    BeamBullet(sf::Vector2f p, sf::Vector2f v);
    ~BeamBullet();
    
    virtual void update(float dt);
    
    bool isAlive;
    
private:
    float speed;
};
