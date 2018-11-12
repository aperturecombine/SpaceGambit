
#include <iostream>
#include <stdlib.h>
#include "PickState.h"

PickState::PickState(class GameStateManager *g) {
    gsm = g;

    currentChoicePlayer[0] = 0;
    currentChoicePlayer[1] = 0;
    
    background.setPosition(0, 0);
    auto size = background.getTexture()->getSize();
    background.setScale(10, 10);
    loadFonts();
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
}

void PickState::update(float deltams) {
    
}

void PickState::draw(sf::RenderWindow *window) {
    
    gsm->window.clear(sf::Color(255,255,255));
    
    gsm->window.draw(background);
    
    text.setCharacterSize(20);
    text.setString("Strength:");
    text.setPosition(50, 550);
    gsm->window.draw(text);
    
    text.setString("Speed:");
    text.setPosition(50, 650);
    gsm->window.draw(text);
    
    text.setString("Defense:");
    text.setPosition(50, 750);
    gsm->window.draw(text);
//
//    text.setCharacterSize(24);
    
    for (int i = 0; i < 2; i++) {
        
        if (currentChoicePlayer[i] == 0)
        {
            
            texture[i].loadFromImage(imagePower[0]);
            strength[i].setSize(sf::Vector2f(80,20));
            speed[i].setSize(sf::Vector2f(30,20));
            defense[i].setSize(sf::Vector2f(40,20));
            
        }
        else if (currentChoicePlayer[i] == 1)
        {
            texture[i].loadFromImage(imagePower[1]);
            strength[i].setSize(sf::Vector2f(30,20));
            speed[i].setSize(sf::Vector2f(80,20));
            defense[i].setSize(sf::Vector2f(40,20));
            
        }
        else
        {
            texture[i].loadFromImage(imagePower[2]);
            strength[i].setSize(sf::Vector2f(30,20));
            speed[i].setSize(sf::Vector2f(40,20));
            defense[i].setSize(sf::Vector2f(80,20));
            
        }

        rocket[i].setTexture(texture[i]);
        rocket[i].setPosition(i*400 +50, 300);
        gsm->window.draw(rocket[i]);
        strength[i].setPosition(i*400 + 50, 550);
        gsm->window.draw(strength[i]);
        strength[i].setPosition(i*400 +50, 650);
        gsm->window.draw(speed[i]);
        strength[i].setPosition(i*400 + 50, 750 );
        gsm->window.draw(defense[i]);

    }

    
}

void PickState::handleInput(sf::Event event) {
    gsm->window.setKeyRepeatEnabled(false);
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left)
            moveUpPick(2);
        if (event.key.code == sf::Keyboard::Right)
            moveDownPick(2);
        if (event.key.code == sf::Keyboard::Space)
            select(2);
        
        if (event.key.code == sf::Keyboard::A)
            moveUpPick(1);
        if (event.key.code == sf::Keyboard::D)
            moveDownPick(1);
        if (event.key.code == sf::Keyboard::X)
            select(1);
        
    }
}

void PickState::handleInput() {
}


void PickState::centerText(sf::Text *text, int y) {
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);
    text->setPosition(sf::Vector2f(800 / 2.0f, y));
}

void PickState::select(int player) {
    selected[player]  = (selected[player] + 1 ) % 2;
    if (selected[0] && selected[1])
        gsm -> pushState(PLAYSTATE);
}


void PickState::moveUpPick(int player) {
    currentChoicePlayer[player]--;
    currentChoicePlayer[player] = currentChoicePlayer[player] % 2;
}
void PickState::moveDownPick(int player) {
    currentChoicePlayer[player] ++;
    currentChoicePlayer[player] = currentChoicePlayer[player] % 2;
}

void PickState::loadFonts(){
    
    if (!font.loadFromFile("/resources/aerial.ttf"))
        std::cout << "Could not load font." << std::endl;
    
    if(!backgroundTexture.loadFromFile("/resources/background.png"))
        return -1;
    background.setTexture(backgroundTexture);
    
    if(!imagePower[0].loadFromFile("/resources/rocketship_1.png"))
        return -1;
    
    if(!imagePower[1].loadFromFile("/resources/rocketship_2.png"))
        return -1;
    if(!imagePower[2].loadFromFile("/resources/rocketship_3.png"))
        return -1;
    
    
     for (int i = 0; i < 2; i++) {
         strength[i].setFillColor(sf::Color::Red);
         speed[i].setFillColor(sf::Color::Green);
         defense[i].setFillColor(sf::Color::Blue);
     }
}



