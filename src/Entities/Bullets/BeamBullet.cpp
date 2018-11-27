#include "../../../include/Entities/Bullets/BeamBullet.h"

BeamBullet::BeamBullet(sf::Vector2f p, sf::Vector2f v, PlayState *refe) {
    pos = p;
    vel = v;
    speed = 1000;
    isAlive = true;
    radius = 20;
    ref = refe;
    timePassed = 0;
    attachShape();
}

void BeamBullet::update(float dt) {
    timePassed +=dt;
    if (timePassed>0.25)
        pos += vel * speed * dt;
    
}
