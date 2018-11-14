#pragma once
#include <SFML/Graphics.hpp>
#include "Turret.h"
#include "../Bullets/MachineGunBullet.h"
#include "../../States/PlayState.h"
#include <iostream>
#include <vector>
#include "Box2D/Box2D.h"
class MachineGunTurret : public Turret {
public:
	MachineGunTurret(sf::Vector2f p);
    /**
    sf::Sprite turretObject;
    sf::Image turretImage;
    sf::Texture turretTexture;
    **/
	sf::Vector2f pos;
	virtual void fire();
	virtual void update(float deltams);
  
	sf::Vector2f getInitBulletVel();

	sf::Vector2f normalize(sf::Vector2f & v);

	void setReference(PlayState *r) { ref = r; }
	PlayState *ref;

   /**
    b2CircleShape* turretShape;

    
    void attachShape(){
        turretShape= new b2CircleShape();
        turretShape -> m_p.Set(2.0f, 3.0f);
        turretShape -> m_radius = 0.5f;
      
        
    }
    
    b2CircleShape* getShape(){
        return  turretShape;
        //return (b2Shape*) turretShape;
    }
    **/
};


