#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "rocketShip.h"
#include "Turret.h"
#include "PlayState.h"
#include "GameState.h"
#include "GameStateManager.h"


PlayState::PlayState(class GameStateManager *g) {
    std::cout << "PlayState declared" << std::endl;
//    GameStateManager gsm = g;
    
//    int width = gsm.window.GetWidth ();
//    int height = gsm.window -> Get
}

void PlayState::update(float deltams) {
//    std::cout << "PlayState update" << std::endl
//    sf::sleep(sf::milliseconds(600));
    t1.fire();
}

void PlayState::draw(sf::RenderWindow *window) {
    window->clear(sf::Color::Black);
    window->draw(ship1.rocketShipObject);
    window->draw(ship2.rocketShipObject);
    window->draw(t1.turretObject);
    window->draw(t1.b1.shell);
    window->draw(t2.turretObject);
    window->draw(t2.b1.shell);
//    std::cout << "PlayState update" << std::endl;
}

void PlayState::handleInput(sf::Event event) {
//    gsm->window.setKeyRepeatEnabled(false);
    if (event.type == sf::Event::KeyPressed) {
        std::cout << "Key Pressed:" << event.type << std::endl;
    }
}


//
//void PlayState::handleInput(sf::Event event) {
//
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//    {
//        ship1.move(135);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//    {
//        ship1.move(225);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//    {
//        ship1.move(315);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//    {
//        ship1.move(45);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//    {
//        ship1.move(90);
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//    {
//        ship1.move(180);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//    {
//        ship1.move(270);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//    {
//        ship1.move(360);
//    }
//    else
//    {
//        ship1.move(0);
//    }
//
//
//
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//    {
//        ship2.move(135);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//    {
//        ship2.move(225);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//    {
//        ship2.move(315);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//    {
//        ship2.move(45);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//    {
//        ship2.move(90);
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//    {
//        ship2.move(180);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//    {
//        ship2.move(270);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//    {
//        ship2.move(360);
//    }
//    else
//    {
//        ship2.move(0);
//    }
//
//    std::cout << "PlayState handleInput" << std::endl;
//}
