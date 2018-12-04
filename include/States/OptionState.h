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

	int currentChoice = 0;
    int hor_CurrentChoice = 1;
    
	float volumeLevel;

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

    int resolution[3]= {720, 1440, 2160};
    
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
    
    void moveLeft() {
        hor_CurrentChoice--;
        if (hor_CurrentChoice < 0)
            hor_CurrentChoice = 2;
    }
    void moveRight() {
        hor_CurrentChoice++;
        if (hor_CurrentChoice > 2)
            hor_CurrentChoice = 0;
    }
    
    void centerText(sf::Text *text, int y);
    
    void select();
};
