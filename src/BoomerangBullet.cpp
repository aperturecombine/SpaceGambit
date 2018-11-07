

#include "BoomerangBullet.h"

BoomerangBullet::BoomerangBullet(sf::Vector2f p, sf::Vector2f v) {
    pos = p;
    vel = v;
    speed = 300;
    isAlive = true;
    radius = 5;
}

void BoomerangBullet::update(float dt) {
    pos += vel * speed * dt;
}
