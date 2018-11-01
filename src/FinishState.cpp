//
//  FinishState.cpp
//  SpaceGambit
//
//

#include <stdio.h>
#include "FinishState.h"
#include "GameStateManager.h"
#include <iostream>
#include <stdlib.h>

FinishState::FinishState(class GameStateManager *g) {
    gsm = g;
    currentChoice = 0;
    
    if (!font.loadFromFile("/Users/liuwukun/Documents/GitHub_workspace/SpaceGambit/src/aerial.ttf"))
    {
        std::cout << "Could not load font." << std::endl;
        
        
        
    }
    
    if(!texture.loadFromFile("/Users/liuwukun/Documents/GitHub_workspace/SpaceGambit/src/space_finish.jpg"))
        return -1;
    //texture.loadFromImage(image);
    background.setTexture(texture);
    
    background.setPosition(0, 0);
    auto size = background.getTexture()->getSize();
    background.setScale(10, 10);
    std::cout << "Could not load font." << std::endl;
    
    text.setFont(font);
    text.setFillColor(sf::Color::White);
}

void FinishState::update(float deltams) {
    
}

void FinishState::draw(sf::RenderWindow *window) {
    
    gsm->window.clear(sf::Color(255,255,255));
    gsm->window.draw(background);
    text.setCharacterSize(70);
    text.setString("You are Finished!");
    centerText(&text, 150);
    gsm->window.draw(text);
    
    text.setCharacterSize(24);
    for (int i = 0; i < 2; i++) {
        
        if (i == currentChoice){
            text.setString("> " + options[i] + " <");
        }
        else{
            text.setString(options[i]);
        }
        centerText(&text, 300 + i * 40);
        gsm->window.draw(text);
    }
    
}

void FinishState::handleInput(sf::Event event) {
    gsm->window.setKeyRepeatEnabled(false);
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up)
            moveUp();
        if (event.key.code == sf::Keyboard::Down)
            moveDown();
        if (event.key.code == sf::Keyboard::Space)
            select();
        
    }
}

void FinishState::handleInput() {
    
}


void FinishState::centerText(sf::Text *text, int y) {
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);
    text->setPosition(sf::Vector2f(800 / 2.0f, y));
}

void FinishState::select() {
    if (currentChoice == 1)
        gsm->popState();
    exit(0);
    if (currentChoice == 0)
        gsm->pushState(new PlayState(gsm));
    
}
