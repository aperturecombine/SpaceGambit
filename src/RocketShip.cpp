#include "RocketShip.h"

RocketShip::RocketShip(sf::Vector2f p) {
	vel = sf::Vector2f(0, 0);
	pos = p;// sf::Vector2f(100, 100);

	ACCEL = 50;
	DECEL = .92;
	maxSpeed = 500;

	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;

	radius = 10;

	if (!rocketShipImage.loadFromFile("resources/spaceship.png")) {
		printf("Could not load spaceship");
	}
	rocketShipTexture.loadFromImage(rocketShipImage);
	rocketShipTexture.setSmooth(true);
	rocketShipObject.setTexture(rocketShipTexture);
	rocketShipObject.setScale(.5, .5);
    rocketShipObject.setOrigin(rocketShipObject.getGlobalBounds().width/2, rocketShipObject.getGlobalBounds().height/2);
}

void RocketShip::update(float deltams) {
	if (moveUp || moveDown) {
		if (moveUp)
			vel.y -= ACCEL;
		if (moveDown)
			vel.y += ACCEL;
	}
	else
		vel.y *= DECEL;

	if (moveLeft || moveRight) {
		if (moveLeft)
			vel.x -= ACCEL;
		if (moveRight)
			vel.x += ACCEL;
	}
	else
		vel.x *= DECEL;

	if (vel.x <= -maxSpeed)	vel.x = -maxSpeed;
	if (vel.x >= maxSpeed)	vel.x = maxSpeed;
	if (vel.y <= -maxSpeed)	vel.y = -maxSpeed;
	if (vel.y >= maxSpeed)	vel.y = maxSpeed;

	pos += vel * deltams;

	rocketShipObject.setPosition(pos);
}
