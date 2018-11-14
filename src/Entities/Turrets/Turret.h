#pragma once

#include <SFML/Graphics.hpp>
#include "../Bullets/MachineGunBullet.h"
#include <list>


class Turret {
public:
    // create an empty shape
    sf::Sprite turretObject;
    sf::Image turretImage;
    sf::Texture turretTexture;

    bool moveable;

	virtual void fire() = 0;
	virtual void update(float deltams) = 0;

	std::vector<class Bullet *> bullets;
    
	sf::Vector2f pos;
    
private:
	float damage;

protected:
	float fireRate;
	float counter;
    float firingRange;
    bool withinfiringRange;

};
