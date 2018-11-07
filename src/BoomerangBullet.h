
#pragma once
#include "Bullet.h"

class BoomerangBullet : public Bullet {
public:
    BoomerangBullet(sf::Vector2f p, sf::Vector2f v);
    ~BoomerangBullet();
    
    virtual void update(float dt);
    
    bool isAlive;
    
private:
    float speed;
};
