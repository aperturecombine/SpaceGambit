
#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Button {
public:

    Button (sf::Texture* normal,sf::Texture* clicked,std::string,sf::Vector2f location);
    
    void checkClick (sf::Vector2f);
    void setState(bool);
    void setText(std::string);
    bool getVar();
    sf::Sprite* getSprite();
    sf::Text * getText();
    void draw(sf::RenderWindow *window, sf::Vector2f mousePos);
private:
    sf::Sprite normal;
    sf::Sprite clicked;
    sf::Sprite* currentSpr;
    sf::Text String;
    bool current;
};
