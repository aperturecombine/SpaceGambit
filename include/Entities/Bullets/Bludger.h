#pragma once
#include "Bullet.h"

class Bludger : public Bullet {
public:
    Bludger(sf::Vector2f p, sf::Vector2f v, PlayState *ref);
    ~Bludger();

    virtual void update(float dt);
    virtual void loadFont();

private:
    float speed;

};