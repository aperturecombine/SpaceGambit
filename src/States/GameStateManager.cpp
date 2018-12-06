#include "../../include/States/GameStateManager.h"
#include "../../include/Globals.h"
#include "../../include/Renderer.h"
#include <chrono>
#include <thread>

GameStateManager::GameStateManager() {
    window.create(sf::VideoMode(RESOLUTION, RESOLUTION), "Space Gambit", sf::Style::Titlebar | sf::Style::Close);
    gameView.reset(sf::FloatRect(0.f, 0.f, SCREENWIDTH, SCREENHEIGHT));
	window.setPosition(sf::Vector2i(10,10));
    window.setView(gameView);
    gameView.zoom(RESOLUTION/SCREENWIDTH);
	renderer = new Renderer(this);
	
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    
    pushState(MENUSTATE);
    running = true;
    winners = 0;
}

void GameStateManager::start() {
    sf::Clock clock;
    
    while (running) {
        float deltams = clock.restart().asSeconds();
        
        states.top()->update(deltams);
        
        window.clear();
		renderer->draw(&window);
		window.display();
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
            states.top()->handleInput(event);
            if(running == false)
                break;
        }
    }
}

void GameStateManager::pushState(int newState) {
    switch (newState) {
        case MENUSTATE:
            states.push(new MenuState(this));
            break;
        case PICKSTATE:
            states.push(new PickState(this));
            break;
        case PLAYSTATE:
		{
			// TODO: this is probably the wrong way to pass variables.
			int ship1Type = ((PickState *)getTop())->currentChoicePlayer[0];
			int ship2Type = ((PickState *)getTop())->currentChoicePlayer[1];
			PlayState * newPlay = new PlayState(this, numPlayer, ship1Type, ship2Type);
			renderer->setShipTypes(ship1Type, ship2Type);
			states.push(newPlay);
		}
		break;
        case FINISHSTATE:
            states.push(new FinishState(this, winners));
            break;
        case OPTIONSTATE:
            states.push(new OptionState(this));
            break;
    }
	renderer->setState(newState);
}

void GameStateManager::popState() {
    this->states.pop();
    if (this->states.empty()) {
        printf("SHUTDOWN\n");
        running = false;
    }
	else
		renderer->setState(this->states.top()->stateID);

	//TODO: fix this please (add prevState?)
	//renderer->setState(MENUSTATE);
}

void GameStateManager::returnToMenu() {
	while (states.size() > 1) {
		popState();
	}
}
