

#pragma once
#include <SFML/Graphics.hpp>
#include "Turret.h"
#include "../Bullets/BeamBullet.h"
#include "../../States/PlayState.h"
#include <iostream>
#include <vector>

class RicochetTurret : public Turret {
public:
    RicochetTurret(sf::Vector2f p);
    
    virtual void fire();
    virtual void update(float deltams);
    
    sf::Vector2f getInitBulletVel();
    
    sf::Vector2f normalize(sf::Vector2f & v);
    
    void setReference(PlayState *r) { ref = r; }
    PlayState *ref;
};
