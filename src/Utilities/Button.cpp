#include "./Utilities/Button.h"
/**
Button::Button(sf::Image* normal,sf::Image* clicked,std::string words,sf::Vector2f location) {
    this->normal.SetImage(*normal);
    this->clicked.SetImage(*clicked);
    this->currentSpr=&this->normal;
    current =false;
    this->normal.SetPosition(location);
    this->clicked.SetPosition(location);
    String.SetText(words);
    String.SetPosition(location.x+3,location.y+3);
    String.SetSize(14);
}
void Button::checkClick (sf::Vector2f mousePos) {
    if (mousePos.x>currentSpr->GetPosition().x && mousePos.x<(currentSpr->getPosition().x + currentSpr->GetSize().x)) {
        if(mousePos.y>currentSpr->GetPosition().y && mousePos.y<(currentSpr->getPosition().y + currentSpr->GetSize().y)) {
            setState(!current);
        }
    }
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
    String.SetText(words);
}
bool Button::getVar() {
    return current;
}
sf::Sprite* Button::getSprite() {
    return currentSpr;
}

sf::String * Button::getText() {
    return &String;
}

**/
