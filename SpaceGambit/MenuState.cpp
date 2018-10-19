#include "MenuState.h"
#include "GameStateManager.h"
#include <iostream>

MenuState::MenuState(class GameStateManager& gsm) {
	std::cout << "menustate declared" << std::endl;
}

void MenuState::update() {
	std::cout << "menustate update" << std::endl;
}

void MenuState::draw() {
	std::cout << "menustate draw" << std::endl;
}

void MenuState::handleInput() {
	std::cout << "menustate handleInput" << std::endl;
}