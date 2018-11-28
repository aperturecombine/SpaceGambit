#pragma once
#include "GameState.h"
#include "PlayState.h"
#include "GameStateManager.h"
#include <string.h>
#include <SFML/Graphics.hpp>

class PickState : public GameState {
public:
    PickState(class GameStateManager *gsm);
    virtual void update(float deltams);
    virtual void draw(sf::RenderWindow *window);
    virtual void handleInput(sf::Event event);
    

    GameStateManager *gsm;
    
    sf::Font font;
    sf::Text text;
    
   
    sf::Sprite sp[2];
    
    //draw background
    sf::Image image;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    
    // draw power bars
    sf::Sprite rocket[2];
    sf::Texture imagePower[3];
    
    sf::RectangleShape strength[2];
    sf::RectangleShape speed[2];
    sf::RectangleShape defense[2];
    
    int currentChoicePlayer[2];
    int playerConfirmation[2];
    int players = 1;
    bool beginGame = false;
    //std::string options[3] = { "Strength", "Speed", "Defense" };
    
    void loadFonts();
    void centerText(sf::Text *text, int x, int y);
    void moveUpPick(int player);
    void moveDownPick(int player);
    void select(int player);  
};

