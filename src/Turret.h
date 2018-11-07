#pragma once

#include <SFML/Graphics.hpp>
#include "MachineGunBullet.h"
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

    /*//Default Constructor
    Turret(int x, int y)
    {
        turretImage.loadFromFile("../resources/turret.png");
        turretTexture.loadFromImage(turretImage);
        turretTexture.setSmooth(true);
        
        moveable = true;
    }
    
    void move(int angle) {
        setDirection(angle);
        if (false)
        {
            turretObject.move(direction.x,direction.y);
        }
        std::cout << "Turret Position: " << position.x << ", " << position.y << std::endl;
    }*/
    

};
