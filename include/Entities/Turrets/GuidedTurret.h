

#pragma once
#include <SFML/Graphics.hpp>
#include "Turret.h"
#include "../Bullets/GuidedBullet.h"
#include "../../States/PlayState.h"
#include <iostream>
#include <vector>
#include "Box2D/Box2D.h"
class GuidedTurret : public Turret {
public:
    GuidedTurret(sf::Vector2f p);
    
    virtual void fire();
    virtual void update(float deltams);

    sf::Vector2f getInitBulletVel();
    
    sf::Vector2f normalize(sf::Vector2f & v);
    
    virtual void explode();
    
    void setReference(PlayState *r) { ref = r; }
    PlayState *ref;
    b2CircleShape* turretShape;
    b2BodyDef turretBody;
    b2FixtureDef turretFixture;
    
    

  
    void attachShape(){
        turretShape= new b2CircleShape();
        turretShape -> m_p.Set(2.0f, 3.0f);
        turretShape -> m_radius = 0.5f;
        
    }
    
    b2CircleShape* getShape(){
        return turretShape;
    }
};

   

