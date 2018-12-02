#include "../../include/States/PickState.h"


PickState::PickState(class GameStateManager *g) {
    gsm = g;
    
    currentChoicePlayer[0] = 0;
    currentChoicePlayer[1] = 0;
    
    background.setPosition(0, 0);
    //auto size = background.getTexture()->getSize();
    background.setScale(1.5f, 1.5f);
    
    loadFonts();
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    sp[0].setScale(0.2f,0.2f);
    sp[1].setScale(0.2f,0.2f);
    
    
    sp[1].setOrigin(sp[1].getGlobalBounds().width/2,
                    sp[1].getGlobalBounds().height/2);
    
    for (int i = 0; i < 2; i++) {
        strength[i].setSize(sf::Vector2f(100.0f,100.0f));
        speed[i].setSize(sf::Vector2f(100.0f,100.0f));
        defense[i].setSize(sf::Vector2f(100.0f,100.0f));
    }
    
    gsm->window.setKeyRepeatEnabled(false);
}

void PickState::update(float deltams) {}

void PickState::draw(sf::RenderWindow *window) {
    gsm->window.draw(background);
    
    // TODO: set individual health bars
    // combine setting the bars and drawing and 
	// make the bar positions constants and more elegant
    for (int i = 0; i < 2; i++) {
        switch (currentChoicePlayer[i]) {
            case 0:
                sp[i].setTexture(imagePower[0]);
                sp[i].setOrigin(sp[i].getGlobalBounds().width/2, sp[i].getGlobalBounds().height/2);
                strength[i].setSize(sf::Vector2f(100, 10));
                speed[i].setSize(sf::Vector2f(80, 10));
                defense[i].setSize(sf::Vector2f(30, 10));
                break;
            case 1:
                sp[i].setTexture(imagePower[1]);
                sp[i].setOrigin(sp[i].getGlobalBounds().width/2, sp[i].getGlobalBounds().height/2);
                strength[i].setSize(sf::Vector2f(30, 10));
                speed[i].setSize(sf::Vector2f(100, 10));
                defense[i].setSize(sf::Vector2f(80, 10));
                break;
            case 2:
                sp[i].setTexture(imagePower[2]);
                sp[i].setOrigin(sp[i].getGlobalBounds().width/2, sp[i].getGlobalBounds().height/2);
                strength[i].setSize(sf::Vector2f(30, 10));
                speed[i].setSize(sf::Vector2f(80, 10));
                defense[i].setSize(sf::Vector2f(100, 10));
                break;
                
        }
    }
    text.setCharacterSize(150);
    text.setString("Pick your Ship");
    centerText(&text,100);
    gsm->window.draw(text);
    
    text.setCharacterSize(80);
    
    text.setString("Strength");
    centerText(&text,600);
    gsm->window.draw(text);
    
    text.setString("Speed");
    centerText(&text,700);
    gsm->window.draw(text);
    
    text.setString("Defense");
    centerText(&text,800);
    gsm->window.draw(text);
    
    //draw status bars and ship sprite
    for (int i = 0; i < 2; i++) {
        sp[i].setPosition((SCREENWIDTH/2 + SCREENWIDTH/4*pow(-1,1+i)), 300);
        gsm->window.draw(sp[i]);
        
        strength[i].setPosition((SCREENWIDTH/2 + SCREENWIDTH/4*pow(-1,1+i)), 600);
        gsm->window.draw(strength[i]);
        
        speed[i].setPosition((SCREENWIDTH/2 + SCREENWIDTH/4*pow(-1,1+i)), 700);
        gsm->window.draw(speed[i]);
        
        defense[i].setPosition((SCREENWIDTH/2 + SCREENWIDTH/4*pow(-1,1+i)), 800);
        gsm->window.draw(defense[i]);
    }
}

void PickState::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == PlayerOne_Left)
            moveUpPick(1);
        if (event.key.code == PlayerOne_Right)
            moveDownPick(1);
        if (event.key.code == sf::Keyboard::Space)
            select(1);
        
        if (event.key.code == PlayerTwo_Left)
            moveUpPick(0);
        if (event.key.code == PlayerTwo_Right)
            moveDownPick(0);
        if (event.key.code == sf::Keyboard::X)
            select(0);
    }
}


void PickState::centerText(sf::Text *text, int y) {
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + (textRect.width / 2.0f),
                    textRect.top + (textRect.height / 2.0f));
    text->setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, y));
}



void PickState::select(int player) {
	//TODO: why are these ints? Can't they be bools?
    if (selected[player] == 0)
        selected[player] = 1;
    else
        selected[player] = 0;
    
    if (selected[0] == selected[1] && selected[1] == 1)
        gsm -> pushState(PLAYSTATE);
}


void PickState::moveUpPick(int player) {
    currentChoicePlayer[player]--;
    if (currentChoicePlayer[player] == -1)
        currentChoicePlayer[player] = 2;
}

void PickState::moveDownPick(int player) {
    currentChoicePlayer[player]++;
    if (currentChoicePlayer[player] == 3)
        currentChoicePlayer[player] = 0;
}

void PickState::loadFonts() {
    if (!font.loadFromFile("resources/spaceranger.ttf"))
        std::cout << "Could not load font." << std::endl;
    
    if(!backgroundTexture.loadFromFile("resources/space_real.jpg"))
        std::cout << "Could not load font." << std::endl;
    background.setTexture(backgroundTexture);
    
    if(!imagePower[0].loadFromFile("resources/SHIP_ATTACK.png"))
        std::cout << "Could not load font." << std::endl;
    
    if(!imagePower[1].loadFromFile("resources/SHIP_DEFENSE.png"))
        std::cout << "Could not load font." << std::endl;
    
    if(!imagePower[2].loadFromFile("resources/SHIP_SPEED.png"))
        std::cout << "Could not load font." << std::endl;
    
    for (int i = 0; i < 2; i++) {
        strength[i].setFillColor(sf::Color::Red);
        speed[i].setFillColor(sf::Color::Green);
        defense[i].setFillColor(sf::Color::Blue);
    }
}
