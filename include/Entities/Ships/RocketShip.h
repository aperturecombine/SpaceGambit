#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class RocketShip {
public:
    
    sf::Texture rocketShipTexture;
    sf::Image rocketShipImage;
    sf::Sprite rocketShipObject;
    
    
	RocketShip() {}
	RocketShip(sf::Vector2f p);
	~RocketShip() {}

	bool moveUp;
	bool moveDown;
	bool moveRight;
	bool moveLeft;

	void update(float deltams);
	int radius = 20;
    float maxSpeed;
    
	sf::Vector2f pos;
	sf::Vector2f vel;

    b2CircleShape* shipShape;
    b2BodyDef rocketBody;
    b2FixtureDef shipFixture;
    void attachShape();
 
    b2CircleShape* getShape();
 
    float health;

    bool isBounced;
    float bounceAccumulator;
    float bounceFactor;
    void bounce(sf::Vector2f collision_point, float bounce_factor);


private:
	float ACCEL;
	float DECEL;


	

	int damageStat;
	int defenseStat;
	float speedStat;
};
