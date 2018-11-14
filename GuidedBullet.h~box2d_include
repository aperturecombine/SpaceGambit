
#pragma once
#include "Bullet.h"
#include "Box2D/Box2D.h"
class GuidedBullet : public Bullet {
public:
    GuidedBullet(sf::Vector2f p, sf::Vector2f v, PlayState *ref);
    ~GuidedBullet();

    virtual void update(float dt);

    bool isAlive;

private:
    float speed;
    
};
