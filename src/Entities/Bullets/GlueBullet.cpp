#include "../../../include/Entities/Bullets/GlueBullet.h"

GlueBullet::GlueBullet(sf::Vector2f p, sf::Vector2f v) {
    pos = p;
    vel = v;
    speed = 1000;
    isAlive = true;
    radius = 5;
    attachShape();
}

void GlueBullet::update(float dt) {
    pos += vel * speed * dt;
}

void GlueBullet::checkBounds(float dt){
    sf::Vector2f temp =  pos + (vel * speed * dt);
    if (temp.x > SCREENWIDTH || temp.x < 0)
    {
        isAlive = false;
    }
    if (temp.y > SCREENHEIGHT || temp.y < 0)
    {
        isAlive = false;
    }
}
