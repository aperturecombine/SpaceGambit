#include "../../../include/Entities/Ships/RocketShip.h"
#include "../../../include/Globals.h"
#include <iostream>

RocketShip::RocketShip(sf::Vector2f p, int type) {
	shipType = type;
	vel = sf::Vector2f(0, 0);
    pos = p;

	ACCEL = 50;
	DECEL = .92;
    currentdirection = 3; 
    rotation = 0.0f;
	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;

	isBounced = false;
	bounceAccumulator = 5;
	bounceFactor = 1.5;

	points = 0;

	radius = 50;
	attachShape();

	switch (shipType) {
	case 0:
		maxSpeed = 500; //HEavy or fast
		maxHealth = 100;
		break;
	case 1:
		maxSpeed = 400; //HEavy or fast
		maxHealth = 125;
		break;
	case 2:
		maxSpeed = 600; //
		maxHealth = 75;
		break;
	}
	currentHealth = maxHealth;

	if (!rocketShipTexture.loadFromFile("../resources/SHIP_SPEED.png")) {
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
			if (moveUp){
				vel.y -= vel_powerup*ACCEL;
                
      
            }
			if (moveDown){
                
				vel.y += vel_powerup*ACCEL;
                
            }
		}
		else
			// vel.y *= vel_powerup*DECEL;
			vel.y *= DECEL;

		if (moveLeft || moveRight) {
			if (moveLeft){
                
				vel.x -= vel_powerup*ACCEL;

            }
			if (moveRight){
                
				vel.x += vel_powerup*ACCEL;
                
            }
		}
		else
			// vel.x *= vel_powerup*DECEL;
			vel.x *= DECEL;

		if (vel.x <= -maxSpeed)	vel.x = -maxSpeed;
		if (vel.x >= maxSpeed)	vel.x = maxSpeed;
		if (vel.y <= -maxSpeed)	vel.y = -maxSpeed;
		if (vel.y >= maxSpeed)	vel.y = maxSpeed;
	}



	rocketShipObject.setPosition(pos);
    pos += vel * deltams;
    
}


void RocketShip::attachShape(){

    //shipShape= new b2CircleShape();
    //shipShape -> m_p.Set(0.0f, 0.0f);
    //shipShape -> m_radius = 50.0f;

    // create new triangle Body
    b2Vec2 vertices1[5];//PolygonA
    vertices1[0].Set(0,0);
    vertices1[1].Set(0,8);
    vertices1[2].Set(15,20);
    vertices1[3].Set(30,8);
    vertices1[4].Set(30,0);
    int count1= 5;
    shipShape= new b2PolygonShape();
    shipShape -> Set(vertices1, count1);
    shipShape -> m_radius = 30.0f;
    //shipShape->Set(vertices1,count1);
    //shipShape->m_radius = 2;
    //shipFixture.shape = shipShape;

}

void RocketShip::bounce(sf::Vector2f collision_point, float bounce_factor){

	isBounced = true;

	// std::cout << collision_point.x << std::endl;
	// std::cout << collision_point.y << std::endl;


	float x_check = pos.x - collision_point.x;
	float y_check = pos.y - collision_point.y;

	// std::cout << x_check << std::endl;
	// std::cout << y_check << std::endl << std::endl;

	vel.x = bounce_factor * x_check*5;
	vel.y = bounce_factor * y_check*5;

}


    b2PolygonShape* RocketShip::getShape(){
    return shipShape;
}
