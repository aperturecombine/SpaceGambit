#pragma once
#include "GameStateManager.h"
#include <string.h>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

class OptionState : public GameState {
public:
    OptionState(class GameStateManager *gsm);
    virtual void update(float deltams);
    virtual void draw(sf::RenderWindow *window);
    virtual void handleInput(sf::Event event);
    sf::Event event;

	int currentChoice;
    
	int volumeLevel;

private:
    GameStateManager *gsm;
    sf::Image image;
    sf::Font font;
    sf::Text text;
    sf::Texture texture;
    sf::Sprite background;
    float counter;
    
    std::string options[5]= {  "Adjust Screen Resolution",
                                "Adjust Volume          ",
                                "Change Player 1 Controls",
                                "Change Player 2 Controls",
                                "Return to Menu"
                            };
    
    void moveUp() {
        currentChoice--;
        if (currentChoice < 0)
            currentChoice = 4;
    }
    void moveDown() {
        currentChoice++;
        if (currentChoice > 4)
            currentChoice = 0;
    }
    
    void centerText(sf::Text *text, int y);
    
    void select();
};
