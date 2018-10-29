#include "GameStateManager.h"


GameStateManager::GameStateManager() {
	running = true;
	window.create(sf::VideoMode(800, 600), "Space Gambit");
    window.setVerticalSyncEnabled(true);

	pushState(MENUSTATE);
}

void GameStateManager::start() {

	sf::Clock clock;

	while (running) {
		float deltams = clock.getElapsedTime().asMicroseconds();

		this->states.top()->update(deltams);
		this->states.top()->draw(&window);

		window.display();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				running = false;
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
            this->states.top()->handleInput(event);
		}
        this->states.top()->handleInput();
		clock.restart();
	}
}

void GameStateManager::pushState(int newState) {
	switch (newState) {
		case MENUSTATE:
			printf("new menu\n");
			states.push(new MenuState(this));
			break;
		case PLAYSTATE:
			printf("new play\n");
			states.push(new PlayState(this));
			break;
		case FINISHSTATE:
			printf("new finish\n");
			states.push(new MenuState(this));
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
