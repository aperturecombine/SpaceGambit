#pragma once

// #include "../../States/PlayState.h"
// #include "Bullet.h"
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"


class Bludger {
public:
    Bludger() {};
    Bludger(sf::Vector2f p, sf::Vector2f v);
    // Bludger(sf::Vector2f p, sf::Vector2f v);
    // ~Bludger();

     void update(float dt, sf::Vector2f ship1, sf::Vector2f ship2, bool twoPlayerMode);

  sf::Texture bulletTexture;
  sf::Sprite bulletObject;
  sf::Image bulletImage;
	sf::Vector2f pos;
	sf::Vector2f vel;
  sf::Sprite shape;
	int radius;
    bool isAlive;
    b2CircleShape* bulletShape;
    float damage;

    // PlayState *ref;


    void loadFont();
    // void setReference(PlayState *r) { ref = r; }
    // PlayState *ref;
    void attachShape(){
        bulletShape= new b2CircleShape();
        bulletShape -> m_p.Set(0.0f, 0.0f);
        bulletShape -> m_radius = 5.0f;


    }

    b2CircleShape* getShape(){
        return bulletShape;
    }



    float full_time;
    float trans_time;

    // virtual void update(float dt);
    // virtual void loadFont();

private:
    float speed;

};