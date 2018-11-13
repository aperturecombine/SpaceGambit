#include "MachineGunBullet.h"

MachineGunBullet::MachineGunBullet(sf::Vector2f p, sf::Vector2f v) {
	pos = p;
	vel = v;
	speed = 300;
	isAlive = true;
	radius = 5;
}

void MachineGunBullet::update(float dt) {
	pos += vel * speed * dt;
}
