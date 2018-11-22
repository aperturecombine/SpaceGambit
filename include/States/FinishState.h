#pragma once
#include "GameState.h"
#include "PlayState.h"
#include "GameStateManager.h"

#include <SFML/Graphics.hpp>

class FinishState : public GameState {
public:
    FinishState(class GameStateManager *gsm);
    virtual void update(float deltams);
    virtual void draw(sf::RenderWindow *window);
    virtual void handleInput(sf::Event event);
    
private:
    GameStateManager *gsm;
    
    sf::Font font;
    sf::Text text;
    sf::Texture texture;
    sf::Sprite background;
    sf::Image image;
    
    int currentChoice;
    std::string options[2] = { "Replay", "Quit" };
    
    void moveUp() {
        currentChoice--;
        
        if ( currentChoice < 0)
            currentChoice = 0;
        //currentChoice = currentChoice % 2;
    }
    void moveDown() {
        currentChoice++;
        if (currentChoice > 1)
            currentChoice = 1;
        //currentChoice = currentChoice % 2;
    }

    
    void centerText(sf::Text *text, int y);
    
    void select();
};

