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
#include "../../include/Entities/Powerups/Powerup.h"
#include "../../include/Entities/Powerups/health.h"
#include "../../include/Entities/Powerups/speed.h"

#include <math.h>
#include <cstdlib>

PlayState::PlayState(class GameStateManager *g) {

    gsm = g;
    turretCount = 6;
    stageTimer = StageTime;
    level = 1;

    loadPauseFonts();
    if(!texture.loadFromFile("resources/bg.png")) {
        printf("playstate space_background load error\n");
    }

    if (!hudTexture.loadFromFile("⁨resources/HPP1VT.png")){
      printf("Not loading hudTexture\n");

    }
    //texture.loadFromImage(image);

    background.setTexture(texture);

    background.setPosition(0, 0);


    auto size = background.getTexture()->getSize();
    background.setScale(float(SCREENWIDTH)/size.x, float(SCREENHEIGHT)/size.y);

    ship1 = RocketShip(sf::Vector2f(SCREENWIDTH/2 + 100,SCREENHEIGHT/2));
    ship2 = RocketShip(sf::Vector2f(SCREENWIDTH/2 - 100,SCREENHEIGHT/2));

    // shipHealth1.setPosition(sf::Vector2f(300,10));
    // shipHealth1.setSize(sf::Vector2f (ship1.health, 10));
    // shipHealth1.setFillColor(sf::Color::Green);
    generateTurrets();


}

void PlayState::update(float deltams) {

		if (!pause){


    if (ship1.freeze){
      ship1.pos = ship1.freezePosition;
      ship1.freeze = false;
    }

    if (ship2.freeze){
      ship2.pos = ship2.freezePosition;
      ship2.freeze = false;
    }
		checkCollisions();
    //shipHealth1.setSize(sf::Vector2f( 300 - abs(ship1.health),50));

    //if (ship1.health <= 0)
    //gsm->pushState(FINISHSTATE);

    if (stageTimer > 0)
        stageTimer -= deltams;
    //    else if (level == 5)
    //    {
    //        level = 1;
    //        resetTurrets();
    //        generateTurrets();
    //        stageTimer = StageTime;
    //
    //    }
    else
    {
        level++;
        generateTurrets();

        int pOfPup = (rand() % 10) + 1;
        powerups.clear();
        if (pOfPup  <= 2){
          createPowerUps();
        }
        stageTimer = StageTime;
    }

    ship1.update(deltams);
    ship2.update(deltams);
    for (int t = 0; t < turrets.size(); t++)
        turrets[t]->update(deltams);


        //if (ship1.health <= 0)
        //gsm->pushState(FINISHSTATE);

	  ship1.update(deltams);
    ship2.update(deltams);

    if (stageTimer > 0) stageTimer -= deltams;
    else stageTimer = 0;

	for (int t = 0; t < turrets.size(); t++)
		turrets[t]->update(deltams);
	}
}
/*
void PlayState::pause(){
	// draw a subrectangle with pause

	//gsm->pushState(PAUSESTATE);


}

*/
void PlayState::draw(sf::RenderWindow *window) {


    //window->clear(sf::Color::);
    window->draw(background);
    //window->draw(shipHealth1);
    window->draw(ship1.rocketShipObject);
    window->draw(ship2.rocketShipObject);

    for (int p = 0; p < powerups.size(); p++){
      window->draw(powerups[p]->pSprite);
    }



    //HUD; later to be refactored into render class


	for (int t = 0; t < turrets.size(); t++) {
		turrets[t]->turretObject.setPosition(turrets[t]->pos);
		window->draw(turrets[t]->turretObject);
	}

	//draw bullets
	sf::CircleShape bulletCircle;
	bulletCircle.setFillColor(sf::Color::Red);

	for (int t = 0; t < turrets.size(); t++) {
		for (int b = 0; b < turrets[t]->bullets.size(); b++) {

			float radius = turrets[t]->bullets[b]->radius;
			turrets[t]->bullets[b]->bulletObject.setScale(.01f*radius,.01f*radius);
			turrets[t]->bullets[b]->bulletObject.setPosition(
				turrets[t]->bullets[b]->pos - sf::Vector2f(.01f*radius, .01f*radius));

			gsm->window.draw(turrets[t]->bullets[b]->bulletObject);
		}
	}







    //HUD; later to be refactored into render class
		// position HUD frame




		//hudTexture.loadFromImage(hudImage);
		sf::Sprite hud;
		hud.setTexture(hudTexture);
		hud.setPosition(0,0);
		hud.setScale(0.7f, 0.5f);
		window->draw(hud);


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


    if (!font.loadFromFile("resources/spaceranger.ttf")) {
        printf("Could not load font");




    }

    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 90);
    text.setCharacterSize(40);
    text.setString("  Score: "+ std::to_string(ship1.points));

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
    text2.setString("  Score: "+ std::to_string(ship1.points));

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



    //level counter
    sf::Text levelCount;

    levelCount.setFont(font);
    levelCount.setFillColor(sf::Color::White);
    levelCount.setCharacterSize(80);
    levelCount.setString(std::to_string(level));
    levelCount.setPosition(SCREENWIDTH - levelCount.getLocalBounds().width -  50, SCREENHEIGHT - 150);



    window->draw(levelCount);

    //level counter
    sf::Text levelNumber;
    levelNumber.setFont(font);
    levelNumber.setFillColor(sf::Color::White);
    levelNumber.setCharacterSize(80);
    levelNumber.setString("Level: ");
    levelNumber.setPosition(SCREENWIDTH - levelCount.getLocalBounds().width -  60 - levelNumber.getLocalBounds().width, SCREENHEIGHT - 150);
    window->draw(levelNumber);



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
     if (pause){
       window->draw(pauseState);
       window->draw(pauseSprite);
     }
}

void PlayState::handleInput(sf::Event event) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
      pause = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
      pause = false;
    }
    {
    ship1.moveRight = sf::Keyboard::isKeyPressed(PlayerOne_Right);
    ship1.moveLeft = sf::Keyboard::isKeyPressed(PlayerOne_Left);
    ship1.moveUp = sf::Keyboard::isKeyPressed(PlayerOne_Up);
    ship1.moveDown = sf::Keyboard::isKeyPressed(PlayerOne_Down);

    ship2.moveRight = sf::Keyboard::isKeyPressed(PlayerTwo_Right);
    ship2.moveLeft = sf::Keyboard::isKeyPressed(PlayerTwo_Left);
    ship2.moveUp = sf::Keyboard::isKeyPressed(PlayerTwo_Up);
    ship2.moveDown = sf::Keyboard::isKeyPressed(PlayerTwo_Down);
  }
}


void PlayState::createPowerUps(){
	// randomly place the powerups within the screenboundary
	// and randomly choose one powerup - health , speed , ultimate

	// type of powerups
	int pOfPup = (rand() % 10) + 1;


	int pOfupX = (rand() % 1500) ;

	int pOfupY = (rand() % 1500) ;

	if (pOfPup <= 3){
    health *Health = new health(sf::Vector2f(pOfupX,pOfupY));
    powerups.push_back(Health);
	}

  else if (pOfPup <= 6){
    speed *Speed = new speed(sf::Vector2f(pOfupX,pOfupY));
    powerups.push_back(Speed);
  }
  else{

  }
  /*
  else if (pOfPup <= 6){
		sP2.setPosition(pOfupX,pOfupY);
		window->draw(sP2);
	}
	else if (pOfPup <= 9){
		sP3.setPosition(pOfupX,pOfupY);
		window->draw(sP3);
	}
	else {
		sP4.setPosition(pOfupX,pOfupY);
		window->draw(sP4);
	}
  */
}





void PlayState::checkCollisions() {
  // powerups
  for (int p = 0; p < powerups.size(); p ++) {
   if (ship1.rocketShipObject.getGlobalBounds().intersects(powerups[p]->pSprite.getGlobalBounds())){
     switch (powerups[p]->type) {
       case 1:
        ship1.currentHealth = ship1.maxHealth;
        break;
       case 2:
        ship1.vel.x += 2*ship1.vel.x;
        ship1.vel.y += 2*ship1.vel.y;
        break;


     }


    powerups.erase(powerups.begin() + p);
  }
   if (ship2.rocketShipObject.getGlobalBounds().intersects(powerups[p]->pSprite.getGlobalBounds())){
     switch (powerups[p]->type) {
       case 1:
        ship2.currentHealth = ship2.maxHealth;
        break;
       case 2:
        ship2.vel.x += 2*ship2.vel.x;
        ship2.vel.y += 2*ship2.vel.y;
        break;


     }
     powerups.erase(powerups.begin() + p);
   }
}

    //Turret collisions


    for (int t = 0; t < turrets.size(); t++) {


        float tx = turrets[t]->pos.x;
        float ty = turrets[t]->pos.y;

        float sx = ship1.pos.x;
        float sy = ship1.pos.y;

        sf::FloatRect vector1 = ship1.rocketShipObject.getGlobalBounds();

        vector1.left +=  .1*ship1.vel.x;
        vector1.top += .1*ship1.vel.y;

        sf::FloatRect vector2 = ship2.rocketShipObject.getGlobalBounds();

        vector2.left += .1*ship2.vel.x;
        vector2.top  += .1*ship2.vel.y;


				bool part1_collision = (vector1.intersects(turrets[t]->turretObject.getGlobalBounds()));
				bool part2_collision = (vector2.intersects(turrets[t]->turretObject.getGlobalBounds()));

        if (part1_collision){
            printf("ship1 collide with turret\n");
						if (ship1.currentHealth != 0) ship1.currentHealth -= 1;

            //if (ship1.vel.x > 0 | ship1.vel.y > 0)
            ship1.freeze = true;
            ship1.freezePosition.x = ship1.pos.x;
            ship1.freezePosition.y = ship1.pos.y;
            ship1.vel = sf::Vector2f(0,0);
        }
        float s2x = ship2.pos.x;
        float s2y = ship2.pos.y;

        if (part2_collision){
            printf("ship2 collide with turret\n");
            if (ship2.currentHealth != 0) ship2.currentHealth -= 1;
            ship2.freeze = true;
            ship2.freezePosition.x = ship2.pos.x;
            ship2.freezePosition.y = ship2.pos.y;
            ship2.vel = sf::Vector2f(0,0);
            //if (ship2.vel.x > 0 | ship2.vel.y > 0)

                  //ship2.vel = sf::Vector2f(NEGATIVE_INFTY*ship2.vel.x,NEGATIVE_INFTY*ship2.vel.y);

        }

    }



		//ship-ship collision
		bool shipCollide = b2TestOverlap(ship1.getShape(),0, ship2.getShape(),0,b2Transform(b2Vec2(ship1.pos.x, ship1.pos.y), b2Rot(0.0f)),b2Transform(b2Vec2(ship2.pos.x, ship2.pos.y), b2Rot(0.0f)));

		/**
		if (shipCollide){
			b2WorldManifold worldManifold;
			b2Manifold manifold;
			worldManifold.Initialize(&manifold, b2Transform(b2Vec2(ship1.pos.x, ship1.pos.y), ship1.m_radius,b2Transform(b2Vec2(ship2.pos.x, ship2.pos.y), ship2.m_radius);
				for (int32 i = 0; i < manifold.pointCount; ++i)
				{
						b2Vec2 point = worldManifold.points[i];
						resolveCollision(point, ship1,ship2);
				}
		}
		**/
    //ship collisions
    for (int t = 0; t < turrets.size(); t++) {


        for (int b = 0; b < turrets[t]->bullets.size(); b++) {

             //printf("bullet size%f\n", turrets[t]->bullets[b]->getShape()->m_radius);
             //printf("ship size%f\n", ship1.getShape()->m_radius);
						 bool part1_collision = (ship1.rocketShipObject.getGlobalBounds().intersects(turrets[t]->bullets[b]->shape.getGlobalBounds()));
		 				 bool part2_collision = (ship2.rocketShipObject.getGlobalBounds().intersects(turrets[t]->bullets[b]->shape.getGlobalBounds()));
						 //bool part1_collision = b2TestOverlap(ship1.getShape(),0, turrets[t]->bullets[b]->getShape(), 0, b2Transform(b2Vec2(ship1.pos.x, ship1.pos.y), b2Rot(0.0f)),b2Transform(b2Vec2(turrets[t]->bullets[b]->pos.x, turrets[t]->bullets[b]->pos.y), b2Rot(0.0f)));
             //bool part2_collision = b2TestOverlap(ship2.getShape(),0, turrets[t]->bullets[b]->getShape(), 0, b2Transform(b2Vec2(ship2.pos.x, ship2.pos.y), b2Rot(0.0f)),b2Transform(b2Vec2(turrets[t]->bullets[b]->pos.x, turrets[t]->bullets[b]->pos.y), b2Rot(0.0f)));


            if (part1_collision){
                //printf("Ship1 got shot\n");


                if (ship1.currentHealth != 0) ship1.currentHealth -= 1;

                turrets[t]->bullets.erase(turrets[t]->bullets.begin() + b);

            }
            else{

            }
            if (part2_collision){
                if (ship2.currentHealth != 0) ship2.currentHealth -= 1;

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

                turrets[t]->bullets.erase(turrets[t]->bullets.begin() + b);
            }

        }
    }

}

void PlayState::generateTurrets() {

    //     1 = Machine Gun Turret
    //     2 = Guided Missle Turret
    //     3 = Rail Gun Turret
    //     4 = Ricochet Turret
    //     5 = Boomerang Turret
    //     6 = Glue Gun Turret
    int turretID;
    float x = 0;
    float y = 0;
    switch(level)
    {
        case 1 : // inner most
        {
            turretID = randomButNotRandomSelector();
            for (int a = 1; a < 3; a++)
            {
                for (int b = 1; b < 3; b++)
                {
                    x = ((SCREENWIDTH/2) + ((SCREENWIDTH/7) * (pow(-1,a))));
                    y = ((SCREENHEIGHT/2) + ((SCREENHEIGHT/7) * (pow(-1,b))));
                    turretSelect(turretID, sf::Vector2f(x, y));
                }
            }
            std::cout << "Case 1 COMPLETED: "<< level << std::endl;
            break;
        }

        case 2 : // Horizontal
        {
            turretID = randomButNotRandomSelector();
            for (int a = 1; a < 3; a++)
            {
                for (int b = 1; b < 3; b++)
                {
                    x = ((SCREENWIDTH/2) + ((SCREENWIDTH/3) * (pow(-1,a))));
                    y = ((SCREENHEIGHT/2) + ((SCREENHEIGHT/15) * (pow(-1,b))));
                    turretSelect(turretID, sf::Vector2f(x, y));
                }
            }
            std::cout << "Case 2 COMPLETED: "<< level << std::endl;
            break;
        }


        case 3 : // vertical
        {
            turretID = randomButNotRandomSelector(); // Vertical
            for (int a = 1; a < 3; a++)
            {
                for (int b = 1; b < 3; b++)
                {
                    x = ((SCREENWIDTH/2) + ((SCREENWIDTH/5) * (pow(-1,a))));
                    y = ((SCREENHEIGHT/2) + ((SCREENHEIGHT/3) * (pow(-1,b))));
                    turretSelect(turretID, sf::Vector2f(x, y));
                }
            }
            std::cout << "Case 3 COMPLETED: "<< level << std::endl;
            break;
        }


        case 4 : // outer most
        {
            turretID = randomButNotRandomSelector();
            for (int a = 1; a < 3; a++)
            {
                for (int b = 1; b < 3; b++)
                {
                    x = ((SCREENWIDTH/2) + ((SCREENWIDTH/3) * (pow(-1,a))));
                    y = ((SCREENHEIGHT/2) + ((SCREENHEIGHT/3) * (pow(-1,b))));
                    turretSelect(turretID, sf::Vector2f(x, y));
                }
            }
            std::cout << "Case 4 COMPLETED: "<< level << std::endl;
            break;
        }

        default:
        {
            std::cout << "Default Case: "<< level << std::endl;
            resetTurrets();
            for (int a = 1; a < 3; a++)
            {
                for (int b = 1; b < 3; b++)
                {
                    turretID = rand() % 6 + 1;
                    turretSelect(turretID, sf::Vector2f(((SCREENWIDTH/2) + (SCREENWIDTH/7) * (pow(-1,a))), ((SCREENHEIGHT/2) + (SCREENHEIGHT/6) * (pow(-1,b)))));
                    turretID = rand() % 6 + 1;
                    turretSelect(turretID, sf::Vector2f(((SCREENWIDTH/2) + (SCREENWIDTH/4) * (pow(-1,a))), ((SCREENHEIGHT/2) + (SCREENHEIGHT/6) * (pow(-1,b)))));
                    turretID = rand() % 6 + 1;
                    turretSelect(turretID, sf::Vector2f(((SCREENWIDTH/2) + (SCREENWIDTH/7) * (pow(-1,a))), ((SCREENHEIGHT/2) + (SCREENHEIGHT/3) * (pow(-1,b)))));
                    turretID = rand() % 6 + 1;
                    turretSelect(turretID, sf::Vector2f(((SCREENWIDTH/2) + (SCREENWIDTH/2.2) * (pow(-1,a))), ((SCREENHEIGHT/2) + (SCREENHEIGHT/3) * (pow(-1,b)))));
                }
            }
            break;
        }

    }


}


void PlayState::resetTurrets() {
    //    for (int t = 0; t < sizeof(turretCounter); t++) {
    //            turretCounter[t] = (t + 1);
    //    }


    for (int t = 0; t < turrets.size(); t++) {
        for (int b = 0; b < turrets[t]->bullets.size(); b++) {
            turrets[t]->bullets.erase(turrets[t]->bullets.begin() + b);
        }
    }

    while (turrets.size()>0) {
        for (int t = 0; t < turrets.size(); t++) {
            turrets.erase(turrets.begin() + t);
        }
    }

}

int PlayState::randomButNotRandomSelector() {
    //    int max = -1;
    //    int range = sizeof(turretCounter);
    int turretID;
    //    for (int t = 0; t < sizeof(turretCounter); t++) {
    //        if(turretCounter[t] != 0)
    //        {
    //            max = t;
    //            break;
    //        }
    //    }
    //    range = sizeof(turretCounter) - max;
    //    turretID = turretCounter[max + (rand() % range)];
    //
    //    for (int t = 0; t < sizeof(turretCounter); t++) {
    //        if(turretCounter[t] == turretID)
    //        {
    //            turretCounter[t] = 0;
    //        }
    //    }

    turretID = (rand() % 6 + 1);

    return turretID;
}








void PlayState::turretSelect(int turretID, sf::Vector2f p) {

    switch(turretID)
    {
        case 1 :  // Boomerang Turret
        {
            BoomerangTurret *t1 = new BoomerangTurret(p);
            t1->setReference(this);
            turrets.push_back(t1);
            break;
        }
        case 2 :  // Glue Gun Turret
        {
            GlueGunTurret *t2 = new GlueGunTurret(p);
            t2->setReference(this);
            turrets.push_back(t2);
            break;
        }
        case 3 : // Guided Turret
        {
            GuidedTurret *t3 = new GuidedTurret(p);
            t3->setReference(this);
            turrets.push_back(t3);
            break;
        }
        case 4 : // Machine Gun Turret
        {
            MachineGunTurret *t4 = new MachineGunTurret(p);
            t4->setReference(this);
            turrets.push_back(t4);
            break;
        }
        case 5 : // Rail Gun Turret
        {
            RailGunTurret *t5 = new RailGunTurret(p);
            t5->setReference(this);
            turrets.push_back(t5);
            break;
        }
        case 6 : // Ricochet Turret
        {
            RicochetTurret *t6 = new RicochetTurret(p);
            t6->setReference(this);
            turrets.push_back(t6);
            break;
        }
        default:
        {
            std::cout << "Turret Select Error" << std::endl;
            break;
        }
    }
}


void PlayState::loadPauseFonts(){


  if(!pauseTexture.loadFromFile("resources/pause.png")){
    printf("PauseTexture  not loading\n");
  }

  pauseSprite.setTexture(pauseTexture);
  pauseSprite.setPosition(SCREENWIDTH/8,SCREENHEIGHT/8);
  pauseSprite.setScale(1.0f, 1.0f);

  sf::Color color(220,220,220);
  color.a = 90;
  pauseState.setFillColor(color);
  pauseState.setPosition(0,0);
  pauseState.setSize(sf::Vector2f(SCREENWIDTH, SCREENHEIGHT));


}
