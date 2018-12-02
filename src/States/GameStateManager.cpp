#include "../../include/States/GameStateManager.h"
#include "../../include/Globals.h"
#include "../Renderer.h"

GameStateManager::GameStateManager() {
    window.create(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Space Gambit");
    window.setVerticalSyncEnabled(true);
    
	renderer = new Renderer(this);

    pushState(MENUSTATE);
    running = true;
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
			PlayState * newPlay = new PlayState(this, ((PickState *)getTop())->players);
			int ship1Type = ((PickState *)getTop())->currentChoicePlayer[0];
			int ship2Type = ((PickState *)getTop())->currentChoicePlayer[1];
			//newPlay->ship1.shipType = ship1Type;
			//newPlay->ship2.shipType = ship2Type;
			renderer->setShipTypes(ship1Type, ship2Type);
			states.push(newPlay);
		}
		break;
        case FINISHSTATE:
			printf("finish state\n");
            states.push(new FinishState(this));
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
	//TODO: fix this please (add prevState?)
	renderer->setState(MENUSTATE);
}