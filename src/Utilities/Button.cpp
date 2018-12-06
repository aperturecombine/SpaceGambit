#include "../../include/Utilities/Button.h"

Button::Button(sf::Texture* normal,sf::Texture* clicked,std::string words,sf::Vector2f location) {
    this->normal.setTexture(*normal);
    this->clicked.setTexture(*clicked);
    this->currentSpr=&this->normal;
    current =false;
    this->normal.setPosition(location);
    this->clicked.setPosition(location);
    sf::Font font;
    if (!font.loadFromFile("../resources/space_3.ttf")) {
         printf("Could not load font");
    }


    this->String.setFont(font);
    this->String.setString(words);
    this->String.setCharacterSize(10);
    this->String.setPosition(location);
    //String.setPosition(location.x+3,location.y+3);
    //String.setCharacterSize(14);
}
void Button::checkClick (sf::Vector2f mousePos) {
    if (mousePos.x>currentSpr->getPosition().x && mousePos.x<(currentSpr->getPosition().x + currentSpr->getScale().x)) {
        if(mousePos.y>currentSpr->getPosition().y && mousePos.y<(currentSpr->getPosition().y + currentSpr->getScale().y)) {
            setState(!current);
        }
    }
}

void Button::draw(sf::RenderWindow *window, sf::Vector2f mousePos){
  if (current)
      window->draw(this->normal);
  else
      window->draw(this->clicked);
}

void Button::setState(bool which) {
    current = which;
    if (current) {
        currentSpr=&clicked;
        return;
    }
    currentSpr=&normal;
}
void Button::setText(std::string words) {
    this->String.setString(words);
    //String.setText(words);
}
bool Button::getVar() {
    return current;
}
sf::Sprite* Button::getSprite() {
    return currentSpr;
}

sf::Text* Button::getText() {
    return &String;
}
