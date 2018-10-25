#include "MenuState.h"
#include "GameStateManager.h"
#include <iostream>

MenuState::MenuState(class GameStateManager& gsm) {
    std::cout << "menustate declared" << std::endl;
}

void MenuState::update(float deltams) {
    std::cout << "menustate update" << std::endl;
}

void MenuState::handleInput() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        std::cout << "UP" << std::endl;
    }

    std::cout << "menustate handleInput" << std::endl;
}