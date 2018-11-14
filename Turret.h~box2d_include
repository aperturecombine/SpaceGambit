#pragma once

#include <SFML/Graphics.hpp>
#include "../Bullets/MachineGunBullet.h"
#include <list>
#include "Box2D/Box2D.h"

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
    b2CircleShape* turretShape;
    b2BodyDef turretBody;
    b2FixtureDef turretFixture;
  
  
    void attachShape(){
        turretShape= new b2CircleShape();
        turretShape -> m_p.Set(2.0f, 3.0f);
        turretShape -> m_radius = 0.5f;
        
    }
    
    b2CircleShape* getShape(){
        return  turretShape;
    }

    
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
