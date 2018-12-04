#include "../../../include/Entities/Ships/RocketShip.h"
#include "../../../include/Globals.h"

RocketShip::RocketShip(sf::Vector2f p) {
	vel = sf::Vector2f(0, 0);
    pos = p;

	ACCEL = 50;
	DECEL = .92;
	maxSpeed = MAXSPEED;

	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;

	isBounced = false;
	bounceAccumulator = 5;
	bounceFactor = 1.5;

	maxHealth = 100;
	currentHealth = maxHealth;

	points = 0;

	radius = 50;
	attachShape();

	if (!rocketShipTexture.loadFromFile("resources/SHIP_SPEED.png")) {
		printf("Could not load spaceship");
	}
	//rocketShipTexture.loadFromImage(rocketShipImage);
	//rocketShipTexture.setSmooth(true);
	rocketShipObject.setTexture(rocketShipTexture);
	rocketShipObject.setScale(0.1f, 0.1f);
    rocketShipObject.setOrigin(
                               (rocketShipObject.getTexture()->getSize().x)/2,
                               (rocketShipObject.getTexture()->getSize().y)/2);
    rocketShipObject.setPosition(p);

}

void RocketShip::update(float deltams) {

    //shipShape -> m_p.Set(pos.x,pos.y);
    bounceAccumulator += deltams;

    if (bounceAccumulator < 2000 ) {
    	isBounced = false;
    }

    if(!isBounced){

    	bounceAccumulator = 0;

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
	}

	pos += vel * deltams;

	rocketShipObject.setPosition(pos);
}


void RocketShip::attachShape(){

    //shipShape= new b2CircleShape();
    //shipShape -> m_p.Set(0.0f, 0.0f);
    //shipShape -> m_radius = 50.0f;

    // create new triangle Body
    b2Vec2 vertices1[3];//PolygonA
    vertices1[0].Set(0,0);
    vertices1[1].Set(20,40);
    vertices1[2].Set(0,20);
    int count1= 3;
    shipShape= new b2PolygonShape();
    shipShape -> Set(vertices1, count1);
    shipShape -> m_radius = 10.0f;
    //shipShape->Set(vertices1,count1);
    //shipShape->m_radius = 2;
    //shipFixture.shape = shipShape;




}

void RocketShip::bounce(sf::Vector2f collision_point, float bounce_factor){

	isBounced = true;

	float x_check = pos.x - collision_point.x;
	float y_check = pos.y - collision_point.y;

	vel.x = bounce_factor * x_check;
	vel.y = bounce_factor * y_check;

}


b2PolygonShape* RocketShip::getShape(){

    return shipShape;

}
