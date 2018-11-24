#pragma once
#include <SFML/Graphics.hpp>
#include "../../States/PlayState.h"
#include "Box2D/Box2D.h"
#include "../Ships/rocketShip.h"

class Powerups {
public:
    Powerups() {}
    ~Powerups() {}
    Powerups(sf::Vector2f p);

    virtual void update(float deltams) = 0;

	sf::Vector2f pos;


	int radius;



    PlayState *ref;
    void attachShape(){
        bulletShape= new b2CircleShape();
        bulletShape -> m_p.Set(0.0f, 0.0f);
        bulletShape -> m_radius = 1.0f;


    }

    b2CircleShape* getShape(){
        return powerupShape;
    }

    void transformShip(){


    }
};
