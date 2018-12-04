//
//  FinishState.cpp
//  SpaceGambit
//
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "../../include/States/FinishState.h"

FinishState::FinishState(class GameStateManager *g, int winners) {
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


    winner = winners;
}

void FinishState::update(float deltams) {

}

void FinishState::draw(sf::RenderWindow *window) {

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
