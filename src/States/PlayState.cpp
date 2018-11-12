#include "PlayState.h"
#include "GameStateManager.h"
#include "../Entities/Turrets/MachineGunTurret.h"
#include "../Entities/Turrets/GuidedTurret.h"
#include "../Entities/Bullets/Bullet.h"

PlayState::PlayState(class GameStateManager *g) {
	gsm = g;

    if(!image.loadFromFile("resources/space_background.png")) {
		printf("playstate space_background load error\n");
	}
    texture.loadFromImage(image);
    background.setTexture(texture);
    
    background.setPosition(0, 0);
    background.setScale(2.f, 2.5);

	ship1 = RocketShip(sf::Vector2f(100,100));
    ship2 = RocketShip(sf::Vector2f(100,300));
	MachineGunTurret *t1 = new MachineGunTurret(sf::Vector2f(300, 100));
	t1->setReference(this);
	MachineGunTurret *t2 = new MachineGunTurret(sf::Vector2f(300, 400));
	t2->setReference(this);
    GuidedTurret *t3 = new GuidedTurret(sf::Vector2f(300, 700));
    t3->setReference(this);

	turrets.push_back(t1);
	turrets.push_back(t2);
    turrets.push_back(t3);
}

void PlayState::update(float deltams) {
	ship1.update(deltams);
    ship2.update(deltams);
	for (int t = 0; t < turrets.size(); t++)
		turrets[t]->update(deltams);

//    checkCollisions();
}


void PlayState::draw(sf::RenderWindow *window) {
    //window->clear(sf::Color::Black);
	window->draw(background);

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

void PlayState::handleInput() {
	ship1.moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	ship1.moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	ship1.moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	ship1.moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    
    ship2.moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    ship2.moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    ship2.moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    ship2.moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

void PlayState::checkCollisions() {
	//ship collisions
	for (int t = 0; t < turrets.size(); t++) {
		for (int b = 0; b < turrets[t]->bullets.size(); b++) {
			sf::Vector2f bPos = turrets[t]->bullets[b]->pos;

			float xDist = abs(bPos.x - ship1.pos.x);
			float yDist = abs(bPos.y - ship1.pos.y);

			if (sqrt((xDist * xDist) + (yDist * yDist)) < 15) {
				//ship1.color = sf::Color::Green;
			}
		}
	}


	//bullet bounds checking
	for (int t = 0; t < turrets.size(); t++) {
		for (int b = 0; b < turrets[t]->bullets.size(); b++) {
			sf::Vector2f bPos = turrets[t]->bullets[b]->pos;
			if (bPos.x < 0 || bPos.x > SCREENWIDTH ||
				bPos.y < 0 || bPos.y > SCREENHEIGHT) {
				delete turrets[t]->bullets[b];
				turrets[t]->bullets.erase(turrets[t]->bullets.begin() + b);
			}

		}
	}
}
