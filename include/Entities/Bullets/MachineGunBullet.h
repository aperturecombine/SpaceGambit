#pragma once
#include "Bullet.h"
#include "Box2D/Box2D.h"
class MachineGunBullet : public Bullet {
public:
	MachineGunBullet(sf::Vector2f p, sf::Vector2f v);
	~MachineGunBullet();

	virtual void update(float dt);

	bool isAlive;
    

    
private:
	float speed;
    
};
