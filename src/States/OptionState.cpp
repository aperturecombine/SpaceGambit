#include <iostream>
#include <stdlib.h>
#include "OptionState.h"

OptionState::OptionState(class GameStateManager *g) {
    gsm = g;
    currentChoice = 0;
    counter = 5;
    if (!font.loadFromFile("resources/aerial.ttf")) {
        printf("Could not load font");
    }
    
    if(!texture.loadFromFile("resources/background.png")) {
        printf("Could not load background");
    }
    
    background.setTexture(texture);
    background.setPosition(0, 0);
    background.setScale(20.f, 20.f);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
}

void OptionState::update(float deltams) {
    std::cout <<"Counter Value: "<< counter<< std::endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        moveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        select();
}

void OptionState::draw(sf::RenderWindow *window) {
    gsm->window.clear(sf::Color(255,255,255));
    gsm->window.draw(background);
    text.setCharacterSize(70);
    text.setString("Welcome to the Options Menu");
    centerText(&text, SCREENHEIGHT*0.1);
    gsm->window.draw(text);
    text.setCharacterSize(24);
    
    
    for (int i = 0; i < 5; i++) {
        if (i == currentChoice)
            text.setString("> " + options[i] + " <");
        else
            text.setString(options[i]);
        centerText(&text, 300 + i * 40);
        gsm->window.draw(text);
    }
}

void OptionState::handleInput() {
//    if (gsm->window.waitEvent(event))
//    {
//        gsm->window.setKeyRepeatEnabled(false);
//        if (event.type == sf::Event::KeyPressed)
//        {
//            if (event.key.code == sf::Keyboard::Up)
//                moveUp();
//            if (event.key.code == sf::Keyboard::Down)
//                moveDown();
//            if (event.key.code == sf::Keyboard::Space)
//                select();
//        }
//    }
}


void OptionState::centerText(sf::Text *text, int y) {
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);
    text->setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, y));
}

void OptionState::select() {
    
    if (currentChoice == 2)
    {
        #undef PlayerOne_Up
        #undef PlayerOne_Down
        #undef PlayerOne_Left
        #undef PlayerOne_Right
        
        #define PlayerOne_Up sf::Keyboard::T
        #define PlayerOne_Down sf::Keyboard::G
        #define PlayerOne_Left sf::Keyboard::F
        #define PlayerOne_Right sf::Keyboard::H
        std::cout <<"Player 1 Controls Changed"<< std::endl;
    }
    
    if (currentChoice == 4)
    {
        std::cout <<"Return to MenuState"<< std::endl;
        gsm->pushState(MENUSTATE);
    }
}


//std::string options[5] = {
//    "Adjust Screen Resolution",
//    "Adjust Volume",
//    "Change Player 1 Controls",
//    "Change Player 2 Controls",
//    "Return to Menu"
//    };
