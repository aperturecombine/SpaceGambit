#include "GameStateManager.h"
#include "../Globals.h"

GameStateManager::GameStateManager() {
	window.create(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Space Gambit");
    window.setVerticalSyncEnabled(true);
	
	pushState(MENUSTATE);
	running = true;
}

void GameStateManager::start() {

	sf::Clock clock;

	while (running) {
		float deltams = clock.restart().asSeconds();

		states.top()->update(deltams);

		window.clear();
		states.top()->draw(&window);
		window.display();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				running = false;
		}
        states.top()->handleInput();
	}
}

void GameStateManager::pushState(int newState) {
	currentState = newState;
	switch (newState) {
	case MENUSTATE:
		states.push(new MenuState(this));
		break;
	case PLAYSTATE:
		states.push(new PlayState(this));
		break;
	case FINISHSTATE:
            states.push(new FinishState(this));
		break;
    case OPTIONSTATE:
            states.push(new OptionState(this));
        break;
	}
}

void GameStateManager::popState() {
	this->states.pop();
	if (this->states.empty()) {
		printf("SHUTDOWN");
		running = false;
	}
}
