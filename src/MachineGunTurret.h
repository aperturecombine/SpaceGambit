#pragma once
#include <SFML/Graphics.hpp>
#include "Turret.h"
#include "MachineGunBullet.h"
#include "PlayState.h"
#include <iostream>
#include <vector>

class MachineGunTurret : public Turret {
public:
	MachineGunTurret(sf::Vector2f p);

	virtual void fire();
	virtual void update(float deltams);

	sf::Vector2f getInitBulletVel();

	sf::Vector2f normalize(sf::Vector2f & v);

	void setReference(PlayState *r) { ref = r; }
	PlayState *ref;
};
