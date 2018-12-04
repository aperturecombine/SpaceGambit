#pragma once

#include <SFML/Graphics.hpp>
#include "../Bullets/MachineGunBullet.h"
#include "../../Globals.h"
#include <list>
#include <Box2D/Box2D.h>

class Turret {
public:
    // create an empty shape
    sf::Sprite turretObject;
    sf::Image turretImage;
    sf::Texture turretTexture;
    sf::Sprite turretObjectbase;
    sf::Image turretbase;
    sf::Texture turretTexturebase;

    bool moveable;

	virtual void fire() = 0;
	virtual void update(float deltams) = 0;

	std::vector<class Bullet *> bullets;

	sf::Vector2f pos;
    b2CircleShape* turretShape;
    b2BodyDef turretBody;
    b2FixtureDef turretFixture;

	float damage = 5;

    void attachShape(){
        turretShape= new b2CircleShape();
        turretShape -> m_p.Set(0.0f, 0.0f);
        turretShape -> m_radius = 60.0f;

    }

    b2CircleShape* getShape(){
        return  turretShape;
    }

protected:
	float fireRate;
	float counter;
    float firingRange;
    bool withinfiringRange;


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

    void loadbase(sf::Vector2f pos){
      if (!turretbase.loadFromFile("resources/base_allgun.png")) {
          printf("Could not load turret\n");
      }


      turretTexturebase.loadFromImage(turretbase);
      turretTexturebase.setSmooth(true);

      turretObjectbase.setTexture(turretTexture);


      turretObjectbase.setOrigin((turretObjectbase.getTexture()->getSize().x) / 2,
                             (turretObjectbase.getTexture()->getSize().y) / 2);

  
      turretObjectbase.setPosition(pos);

    }


};
