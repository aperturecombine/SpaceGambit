#pragma once
#include <SFML/Graphics.hpp>

class RocketShip {
public:
    sf::Sprite rocketShipObject;
    sf::Texture rocketShipTexture;
    sf::Image rocketShipImage;

	RocketShip() {}
	RocketShip(sf::Vector2f p);
	~RocketShip() {}

	bool moveUp;
	bool moveDown;
	bool moveRight;
	bool moveLeft;

	void update(float deltams);
	int radius = 20;

	sf::Vector2f pos;
	sf::Vector2f vel;

private:
	float ACCEL;
	float DECEL;
	float maxSpeed;

	float health;

	int damageStat;
	int defenseStat;
	float speedStat;
};