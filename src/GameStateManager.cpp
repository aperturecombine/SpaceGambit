#include "GameStateManager.h"

GameStateManager::GameStateManager() {
    pushState(new MenuState(*this));
    pushState(new PlayState(*this));
	running = true;
    
}

void GameStateManager::start() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Space Gambit");

	sf::Clock clock;

	while (running) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				running = false;
		}

		this->states.top()->handleInput();

		float deltams = clock.getElapsedTime().asMicroseconds();

        window.setVerticalSyncEnabled(true);
        
		this->states.top()->update(deltams);
		this->states.top()->draw(&window);
		
		window.display();

		clock.restart();
	}
}

void GameStateManager::pushState(GameState * state) {
	this->states.push(state);
}

void GameStateManager::popState() {
	this->states.pop();
}
