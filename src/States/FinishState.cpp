//
//  FinishState.cpp
//  SpaceGambit
//
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "../../include/States/FinishState.h"

FinishState::FinishState(class GameStateManager *g) {
    gsm = g;
    currentChoice = 0;
	stateID = FINISHSTATE;

    if (!font.loadFromFile("resources/spaceranger.ttf"))
    {
        std::cout << "Could not load font." << std::endl;

    }

    if(!texture.loadFromFile("resources/good_game.jpg"))
    {
    }
    //texture.loadFromImage(image);
    background.setTexture(texture);

    background.setPosition(0, 0);
    //    auto size = background.getTexture()->getSize();
    background.setScale(0.5f, 0.5f);
    std::cout << "Could not load font." << std::endl;

    text.setFont(font);
    text.setFillColor(sf::Color::Red);
}

void FinishState::update(float deltams) {

}

void FinishState::draw(sf::RenderWindow *window) {
//
//    gsm->window.clear(sf::Color(255,255,255));
//    gsm->window.draw(background);
//    text.setCharacterSize(150);
//    text.setFillColor(sf::Color::White);
//    text.setString("No!  You Died!");
//    centerText(&text, 150);
//    gsm->window.draw(text);
//
//    text.setCharacterSize(24);
//    for (int i = 0; i < 2; i++) {
//
//        if (i == currentChoice){
//            text.setString("> " + options[i] + " <");
//        }
//        else{
//            text.setString(options[i]);
//        }
//        centerText(&text, 300 + i * 40);
//        gsm->window.draw(text);
//    }

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

void FinishState::centerText(sf::Text *text, int y) {
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);
    text->setPosition(sf::Vector2f(800, y));
}

void FinishState::select() {

	if (currentChoice == 0) {
		gsm->returnToMenu();
	}
	if (currentChoice == 1)
	{
		gsm->running = false;
	}
}
