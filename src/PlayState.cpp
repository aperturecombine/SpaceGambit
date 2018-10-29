#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "rocketShip.h"
#include "Turret.h"
#include "PlayState.h"
#include "GameState.h"
#include "GameStateManager.h"


PlayState::PlayState(class GameStateManager *g) {
    std::cout << "PlayState declared" << std::endl;
	gsm = g;
//    GameStateManager gsm = g;
    
//    int width = gsm.window.GetWidth ();
//    int height = gsm.window -> Get
}

void PlayState::update(float deltams) {
//    std::cout << "PlayState update" << std::endl
//    sf::sleep(sf::milliseconds(600));
    
    t1.fire(ship1.getRocketPosition(), ship2.getRocketPosition());
    t2.fire(ship1.getRocketPosition(), ship2.getRocketPosition());
}

void PlayState::draw(sf::RenderWindow *window) {
    window->clear(sf::Color::Black);
    window->draw(ship1.rocketShipObject);
    window->draw(ship2.rocketShipObject);
    window->draw(t1.turretObject);
    window->draw(t2.turretObject);
    
    
    for (t1.bulletIt = t1.listOfBullets.begin(); t1.bulletIt != t1.listOfBullets.end(); ++t1.bulletIt){
        window -> draw(t1.bulletIt->shell);
    }
    
    for (t2.bulletIt = t2.listOfBullets.begin(); t2.bulletIt != t2.listOfBullets.end(); ++t2.bulletIt){
        window -> draw(t2.bulletIt->shell);
    }
    
    
    
    
    
//    std::cout << "PlayState update" << std::endl;
}

void PlayState::handleInput(sf::Event event) {
//    gsm->window.setKeyRepeatEnabled(false);

//    if (event.type == sf::Event::KeyPressed) {
//        if(event.key.code == sf::Keyboard::Up) {ship1.move(90);}
//        else if(event.key.code == sf::Keyboard::Left) {ship1.move(180);}
//        else if(event.key.code == sf::Keyboard::Down) {ship1.move(270);}
//        else if(event.key.code == sf::Keyboard::Right) {ship1.move(360);}
//
//        if(event.key.code == sf::Keyboard::W) {ship2.move(90);}
//        else if(event.key.code == sf::Keyboard::A) {ship2.move(180);}
//        else if(event.key.code == sf::Keyboard::S) {ship2.move(270);}
//        else if(event.key.code == sf::Keyboard::D) {ship2.move(360);}

        std::cout << "Key Pressed:" << event.type << std::endl;
//    }

}

void PlayState::handleInput() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        ship1.move(135);
    }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
	{
		gsm->pushState(MENUSTATE);
	}
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        ship1.move(225);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        ship1.move(315);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        ship1.move(45);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        ship1.move(90);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        ship1.move(180);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        ship1.move(270);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        ship1.move(360);
    }
    else
    {
        ship1.move(0);
    }



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        ship2.move(135);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        ship2.move(225);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        ship2.move(315);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        ship2.move(45);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        ship2.move(90);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        ship2.move(180);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        ship2.move(270);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        ship2.move(360);
    }

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
	{
		gsm->pushState(FINISHSTATE);
	}

    else
    {
        ship2.move(0);
    }

//    std::cout << "PlayState handleInput" << std::endl;
}
