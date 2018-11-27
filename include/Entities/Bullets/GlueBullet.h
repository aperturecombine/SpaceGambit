#pragma once
#include "Bullet.h"
#include "../../Globals.h"


class GlueBullet : public Bullet {
public:
    GlueBullet(sf::Vector2f p, sf::Vector2f v);
    ~GlueBullet();

    virtual void update(float dt);
  
    virtual void loadFont();
private:
    float speed;
    virtual void checkBounds(float dt);

};
