#include "../../include/States/PlayState.h"
#include "../../include/States/GameStateManager.h"
#include "../../include/Globals.h"
#include "../../include/Entities/Turrets/MachineGunTurret.h"
#include "../../include/Entities/Turrets/GuidedTurret.h"
#include "../../include/Entities/Turrets/BoomerangTurret.h"
#include "../../include/Entities/Turrets/RailGunTurret.h"
#include "../../include/Entities/Turrets/RicochetTurret.h"
#include "../../include/Entities/Turrets/GlueGunTurret.h"
#include "../../include/Entities/Bullets/Bullet.h"
#include <math.h>

PlayState::PlayState(class GameStateManager *g) {
	gsm = g;

    if(!image.loadFromFile("resources/space_background.jpg")) {
		printf("playstate space_background load error\n");
	}
	texture.loadFromImage(image);
    background.setTexture(texture);
    
    background.setPosition(0, 0);
    background.setScale(0.7f, 0.5f);

	ship1 = RocketShip(sf::Vector2f(250,500));
    ship2 = RocketShip(sf::Vector2f(250,900));
	MachineGunTurret *t1 = new MachineGunTurret(sf::Vector2f(250, 100));
	t1->setReference(this);
    turrets.push_back(t1);
    
     GuidedTurret *t2 = new GuidedTurret(sf::Vector2f(500, 100));
     t2->setReference(this);
     turrets.push_back(t2);
    
     BoomerangTurret *t3 = new BoomerangTurret(sf::Vector2f(800, 100));
     t3->setReference(this);
     turrets.push_back(t3);
    
     RailGunTurret *t4 = new RailGunTurret(sf::Vector2f(1100, 100));
     t4->setReference(this);
     turrets.push_back(t4);
    
     RicochetTurret *t5 = new RicochetTurret(sf::Vector2f(1350, 100));
     t5->setReference(this);
     turrets.push_back(t5);
    
     GlueGunTurret *t6 = new GlueGunTurret(sf::Vector2f(1500, 100));
     t6->setReference(this);
     turrets.push_back(t6);
	

     stageTimer = 20;
    // shipHealth1.setPosition(sf::Vector2f(300,10));
    // shipHealth1.setSize(sf::Vector2f (ship1.health, 10));
    // shipHealth1.setFillColor(sf::Color::Green);
    
}

void PlayState::update(float deltams) {
    checkCollisions();
    //shipHealth1.setSize(sf::Vector2f( 300 - abs(ship1.health),50));
        //if (ship1.health <= 0)
        //gsm->pushState(FINISHSTATE);

	ship1.update(deltams);
    ship2.update(deltams);

    if (stageTimer > 0) stageTimer -= deltams;
    else stageTimer = 0;

	for (int t = 0; t < turrets.size(); t++)
		turrets[t]->update(deltams);

}


void PlayState::draw(sf::RenderWindow *window) {
    //window->clear(sf::Color::Black);
	window->draw(background);
    //window->draw(shipHealth1);
    window->draw(ship1.rocketShipObject);
    window->draw(ship2.rocketShipObject);

	for (int t = 0; t < turrets.size(); t++) {
		turrets[t]->turretObject.setPosition(turrets[t]->pos);
		window->draw(turrets[t]->turretObject);
	}

	//draw bullets
	sf::CircleShape bulletCircle;
	bulletCircle.setFillColor(sf::Color::Red);

	for (int t = 0; t < turrets.size(); t++) {
		for (int b = 0; b < turrets[t]->bullets.size(); b++) {
			float bRadius = turrets[t]->bullets[b]->radius;
			bulletCircle.setRadius(bRadius);
			bulletCircle.setPosition(
				turrets[t]->bullets[b]->pos - sf::Vector2f(bRadius, bRadius));
			gsm->window.draw(bulletCircle);
		}
	}







    //HUD; later to be refactored into render class

    //Player 1 HUD
    sf::RectangleShape bar;
    bar.setFillColor(sf::Color::White);
    bar.setSize(sf::Vector2f(100, 50));
    bar.setPosition(10, 20);

    sf::RectangleShape health;
    bar.setFillColor(sf::Color::Red);
    health.setSize(sf::Vector2f(100*(ship1.currentHealth / ship1.maxHealth), 50));
    health.setPosition(10, 20);



    sf::Font font;
    sf::Text text;

    if (!font.loadFromFile("resources/space_3.ttf")) {
         printf("Could not load font");
    }

    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 90);
    text.setCharacterSize(40);
    text.setString("Score: "+ std::to_string(ship1.points));

    window->draw(bar);
    window->draw(health);
    window->draw(text);





    //player 2 HUD
    sf::RectangleShape bar2;
    bar2.setFillColor(sf::Color::White);
    bar2.setSize(sf::Vector2f(100, 50));
    bar2.setPosition(SCREENWIDTH - 250, 20);

    sf::RectangleShape health2;
    bar2.setFillColor(sf::Color::Red);
    health2.setSize(sf::Vector2f(100*(ship2.currentHealth / ship2.maxHealth), 50));
    health2.setPosition(SCREENWIDTH - 250, 20);


    sf::Text text2;

    text2.setFont(font);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(SCREENWIDTH - 250, 90);
    text2.setCharacterSize(40);
    text2.setString("Score: "+ std::to_string(ship1.points));

    window->draw(bar2);
    window->draw(health2);
    window->draw(text2);




    //stage counter
    sf::Text stage;

    stage.setFont(font);
    stage.setFillColor(sf::Color::White);
    stage.setPosition(10, SCREENHEIGHT - 150);
    stage.setCharacterSize(80);
    stage.setString("Stage: ");

    window->draw(stage);






    sf::Text timer;

    timer.setFont(font);
    timer.setFillColor(sf::Color::White);
    timer.setPosition(SCREENWIDTH - 200, SCREENHEIGHT - 150);
    timer.setCharacterSize(80);
    timer.setString(std::to_string(static_cast<int>(stageTimer)));

    window->draw(timer);







	/*
	//draw ship
	sf::CircleShape shipCircle;
	shipCircle.setFillColor(ship1.color);
	shipCircle.setRadius(ship1.radius);
	shipCircle.setPosition(ship1.getPosition() -
		sf::Vector2f(ship1.radius, ship1.radius));
	gsm->window.draw(shipCircle);

	//draw turret
	sf::RectangleShape turretRect;
	turretRect.setSize(sf::Vector2f(100, 100));
	turretRect.setFillColor(sf::Color::Yellow);
	for (int t = 0; t < turrets.size(); t++) {
		turretRect.setPosition(turrets[t]->pos - sf::Vector2f(50, 50));
		gsm->window.draw(turretRect);
	}*/
}

void PlayState::handleInput(sf::Event event) {
	ship1.moveRight = sf::Keyboard::isKeyPressed(PlayerOne_Right);
	ship1.moveLeft = sf::Keyboard::isKeyPressed(PlayerOne_Left);
	ship1.moveUp = sf::Keyboard::isKeyPressed(PlayerOne_Up);
	ship1.moveDown = sf::Keyboard::isKeyPressed(PlayerOne_Down);
    
    ship2.moveRight = sf::Keyboard::isKeyPressed(PlayerTwo_Right);
    ship2.moveLeft = sf::Keyboard::isKeyPressed(PlayerTwo_Left);
    ship2.moveUp = sf::Keyboard::isKeyPressed(PlayerTwo_Up);
    ship2.moveDown = sf::Keyboard::isKeyPressed(PlayerTwo_Down);
}

void PlayState::checkCollisions() {
    //Turret collisions
    
    /**
    for (int t = 0; t < turrets.size(); t++) {

 
        float tx = turrets[t]->pos.x;
        float ty = turrets[t]->pos.y;
        
        
        float sx = ship1.pos.x;
        float sy = ship1.pos.y;

        b2CircleShape* shape1 = ship1.getShape();
        b2CircleShape* shape2 = ship2.getShape();
        b2CircleShape* shape = turrets[t]->getShape();
        
        
        bool part1_collision = b2TestOverlap(shape1,0, shape, 0, b2Transform(b2Vec2(sx,sy), b2Rot(0.0f)),b2Transform(b2Vec2(tx,ty), b2Rot(0.0f)));
        
        
        if (part1_collision){
            printf("ship1 collide with turret\n");
            ship1.health -= 10;
            //ship1.vel = sf::Vector2f(0,0);
        }
        float s2x = ship2.pos.x;
        float s2y = ship2.pos.y;

        
        bool part2_collision = b2TestOverlap(shape2,0, shape, 0, b2Transform(b2Vec2(s2x,s2y), b2Rot(0.0f)),b2Transform(b2Vec2(tx,ty), b2Rot(0.0f)));
        if (part2_collision){
            printf("ship2 collide with turret\n");
            ship2.health -= 10;
            //ship2.vel = sf::Vector2f(0,0);
        }

    }
    
    **/
    
    
    //ship collisions
    for (int t = 0; t < turrets.size(); t++) {
  

        for (int b = 0; b < turrets[t]->bullets.size(); b++) {
             
             printf("bullet size%f\n", turrets[t]->bullets[b]->getShape()->m_radius);
             printf("ship size%f\n", ship1.getShape()->m_radius);
             bool part1_collision = b2TestOverlap(ship1.getShape(),0, turrets[t]->bullets[b]->getShape(), 0, b2Transform(b2Vec2(ship1.pos.x, ship1.pos.y), b2Rot(0.0f)),b2Transform(b2Vec2(turrets[t]->bullets[b]->pos.x, turrets[t]->bullets[b]->pos.y), b2Rot(0.0f)));
             bool part2_collision = b2TestOverlap(ship2.getShape(),0, turrets[t]->bullets[b]->getShape(), 0, b2Transform(b2Vec2(ship2.pos.x, ship2.pos.y), b2Rot(0.0f)),b2Transform(b2Vec2(turrets[t]->bullets[b]->pos.x, turrets[t]->bullets[b]->pos.y), b2Rot(0.0f)));
    
             
            if (part1_collision){
                printf("Ship1 got shot\n");

                if (ship1.currentHealth != 0) ship1.currentHealth -= 1;
                // printf("%f\n",ship1.health);
//            delete turrets[t]->bullets[b];
            turrets[t]->bullets.erase(turrets[t]->bullets.begin() + b);
            
            }
            else{
                
                printf("Miss : %5f \n",(ship1.pos.x - turrets[t]->bullets[b]->pos.x) + (ship1.pos.y - turrets[t]->bullets[b]->pos.y));
        
                //printf("%5f bx",turrets[t]->bullets[b]->pos.x);
                //printf("%5f by\n",turrets[t]->bullets[b]->pos.y);
            }
            if (part2_collision){
                if (ship2.currentHealth != 0) ship2.currentHealth -= 1;
                printf("Ship2 got shot\n");
                //world->DestroyBody(turrets[t]->bullets[b]->body);
//                delete turrets[t]->bullets[b];
                turrets[t]->bullets.erase(turrets[t]->bullets.begin() + b);
                
            }
            
			}
		}
    
    
	//bullet bounds checking
	for (int t = 0; t < turrets.size(); t++) {
		for (int b = 0; b < turrets[t]->bullets.size(); b++) {
			sf::Vector2f bPos = turrets[t]->bullets[b]->pos;
			if (bPos.x < 0 || bPos.x > SCREENWIDTH ||
				bPos.y < 0 || bPos.y > SCREENHEIGHT) {
//                delete turrets[t]->bullets[b];
                turrets[t]->bullets.erase(turrets[t]->bullets.begin() + b);
			}

		}
	}
	
}