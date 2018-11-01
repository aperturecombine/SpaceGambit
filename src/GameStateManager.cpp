#include "GameStateManager.h"


GameStateManager::GameStateManager() {
	pushState(new MenuState(this));
    
	running = true;
	window.create(sf::VideoMode(800, 600), "Space Gambit");
    window.setVerticalSyncEnabled(true);
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                this->states.push(new FinishState(this));
			if (event.type == sf::Event::Closed)
				running = false;
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
            this->states.top()->handleInput(event);
            
            
		}
        this->states.top()->handleInput();
		clock.restart();
	}
}

void GameStateManager::pushState(GameState * state) {
	this->states.push(state);
}

void GameStateManager::popState() {
	this->states.pop();
	if (this->states.empty()) {
		printf("SHUTDOWN");
		running = false;
        exit(0);
	}
}
