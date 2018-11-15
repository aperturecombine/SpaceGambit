#include "MachineGunBullet.h"

MachineGunBullet::MachineGunBullet(sf::Vector2f p, sf::Vector2f v) {
	pos = p;
	vel = v;
	speed = 300;
	isAlive = true;
	radius = 5;
    attachShape();
}

void MachineGunBullet::update(float dt) {
	pos += vel * speed * dt;
}

void MachineGunBullet::checkBounds(float dt){
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
