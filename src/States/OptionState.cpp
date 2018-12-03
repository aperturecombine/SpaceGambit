#include <iostream>
#include <stdlib.h>
#include "../../include/States/OptionState.h"

OptionState::OptionState(class GameStateManager *g) {
    gsm = g;
	stateID = OPTIONSTATE;
    currentChoice = 0;
    counter = 5;
    if (!font.loadFromFile("resources/spaceranger.ttf")) {
        printf("Could not load font");
    }
    
    if(!texture.loadFromFile("resources/space_real.jpg")) {
        printf("Could not load background");
    }
    
    background.setTexture(texture);
    background.setPosition(0, 0);
    
    auto size = background.getTexture()->getSize();
    background.setScale(float(SCREENWIDTH)/size.x, float(SCREENHEIGHT) / size.y);
    text.setFont(font);
    text.setFillColor(sf::Color::White);
}

void OptionState::update(float deltams) {}

void OptionState::draw(sf::RenderWindow *window) {
    gsm->window.clear(sf::Color(255,255,255));
    gsm->window.draw(background);
    text.setCharacterSize(150);
    text.setString("Welcome to the");
    centerText(&text, SCREENHEIGHT*0.1);
    gsm->window.draw(text);
    text.setString("Options Menu");
    centerText(&text, SCREENHEIGHT*0.2);
    gsm->window.draw(text);
    
    text.setCharacterSize(70);
    
    for (int i = 0; i < 5; i++) {
        if (i == currentChoice)
            text.setString("> " + options[i] + " <");
        else
            text.setString(options[i]);
        centerText(&text, SCREENHEIGHT*0.3 + i * 100);
        gsm->window.draw(text);
    }
    
    
}

void OptionState::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up)
            moveUp();
        else if (event.key.code == sf::Keyboard::Down)
            moveDown();
        else if (event.key.code == sf::Keyboard::Space)
            select();
        //        switch (event.key.code) {
        //        case sf::Keyboard::Up:
        //            moveUp();
        //            break;
        //        case sf::Keyboard::Down:
        //            moveDown();
        //            break;
        //        case sf::Keyboard::Space:
        //            select();
        //            break;
        //        }
    }
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
        PlayerOne_Up = sf::Keyboard::T;
        PlayerOne_Down = sf::Keyboard::G;
        PlayerOne_Left = sf::Keyboard::F;
        PlayerOne_Right = sf::Keyboard::H;
        std::cout <<"Player 1 Controls Changed"<< std::endl;
    }
    
    if (currentChoice == 4)
    {
        std::cout <<"Return to MenuState"<< std::endl;
        gsm->popState();
    }
}


//std::string options[5] = {
//    "Adjust Screen Resolution",
//    "Adjust Volume",
//    "Change Player 1 Controls",
//    "Change Player 2 Controls",
//    "Return to Menu"
//    };
