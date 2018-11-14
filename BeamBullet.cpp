
#include "./Entities/Bullets/BeamBullet.h"

BeamBullet::BeamBullet(sf::Vector2f p, sf::Vector2f v) {

    pos = p;
    vel = v;
    speed = 300;
    isAlive = true;
    radius = 5;
    attachShape();
    
}

void BeamBullet::update(float dt) {
    pos += vel * speed * dt;
   
}
