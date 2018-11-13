#include "BeamBullet.h"

BeamBullet::BeamBullet(sf::Vector2f p, sf::Vector2f v, PlayState *refe) {
    pos = p;
    vel = v;
    speed = 800;
    isAlive = true;
    radius = 20;
    ref = refe;
}

void BeamBullet::update(float dt) {
  
    pos += vel * speed * dt;
}
