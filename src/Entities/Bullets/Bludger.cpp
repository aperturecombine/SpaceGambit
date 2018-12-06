#include "../../../include/Entities/Bullets/Bludger.h"
#include "../../../include/Entities/Bullets/Bullet.h"
#include <stdio.h>
Bludger::Bludger(sf::Vector2f p, sf::Vector2f v) {
// Bludger::Bludger(sf::Vector2f p, sf::Vector2f v) {
    pos = p;
    // bulletObject.setOrigin(p);
    damage = 20;
    vel = v;
    speed = 200;
    isAlive = true;
    radius = 20;
    trans_time = 0;
    full_time = 2;
    // ref = refe;
    attachShape();
    loadFont();
}

void Bludger::update(float dt, sf::Vector2f ship1, sf::Vector2f ship2, bool twoPlayerMode) {
    

	// trans_time += dt;

	// if(trans_time > full_time){
	// 	trans_time = 0;

	    sf::Vector2f ship1_init = (ship1 - pos);
	    float ship1_dist = pow((ship1_init.x*ship1_init.x + ship1_init.y*ship1_init.y),0.5);


	    printf("bludgx: %f\n", pos.x);
	    printf("bludgy: %f\n\n", pos.y);

	    printf("shipx: %f\n", ship1.x);
	    printf("shipy: %f\n\n", ship1.y);

	    if(twoPlayerMode){

	    printf("!");
	        sf::Vector2f ship2_init = (ship2 - pos);
	        float ship2_dist = pow((ship2_init.x*ship2_init.x + ship2_init.y*ship2_init.y),0.5);

	        if (ship1_dist < ship2_dist)
	        {

	            if (ship1_dist != 0) 
	            	vel = sf::Vector2f(ship1_init.x / ship1_dist, ship1_init.y / ship1_dist);
	            else vel = ship1_init;
	        }
	        else 
	        {
	         	if (ship2_dist != 0) 
	         		vel = sf::Vector2f(ship2_init.x / ship2_dist, ship2_init.y / ship2_dist);
	            else vel = ship2_init;
	        }
	    }
	    else
	    {
	            if (ship1_dist > 0) 
	            	vel = sf::Vector2f(ship1_init.x / ship1_dist, ship1_init.y / ship1_dist);
	            // else vel = ship1_init;
	    }

	   

	// }

	 bulletObject.setRotation(360.f + atan(vel.y/vel.x)*180/M_PI);
	    if (vel.x > 0) {
	    	bulletObject.rotate(180.f);}



    pos += vel * speed * dt;

}

void Bludger::loadFont(){

    if (!bulletImage.loadFromFile("resources/missle_frame2.png")) {
        printf("Could not load guided\n");
    }

    bulletTexture.loadFromImage(bulletImage);
    bulletTexture.setSmooth(true);
    bulletObject.setTexture(bulletTexture);
}