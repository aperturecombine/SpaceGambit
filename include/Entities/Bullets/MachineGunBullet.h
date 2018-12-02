#pragma once
#include "Bullet.h"
#include "../../Globals.h"


class MachineGunBullet : public Bullet {
public:
	MachineGunBullet(sf::Vector2f p, sf::Vector2f v);
	~MachineGunBullet();

	virtual void update(float dt);
        virtual void loadFont();
private:
	float speed;
    virtual void checkBounds(float dt);

};
