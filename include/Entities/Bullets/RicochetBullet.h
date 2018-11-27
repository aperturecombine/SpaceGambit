#pragma once
#include "Bullet.h"
#include "../../Globals.h"

class RicochetBullet : public Bullet {
public:
    RicochetBullet(sf::Vector2f p, sf::Vector2f v, PlayState *ref);
    ~RicochetBullet();

    virtual void update(float dt);
    virtual void loadFont();

private:
    float speed;
    float bounceCount;
    float bounceMax;

    virtual bool checkBounds(float dt);
    virtual void lifeCheck();


};
