

#pragma once
#include <SFML/Graphics.hpp>
#include "Turret.h"
#include "GuidedBullet.h"
#include "PlayState.h"
#include <iostream>
#include <vector>

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
};