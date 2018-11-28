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
    //
    //    std::cout << "Could not load font." << std::endl;
    //    std::cout << "Could not load font." << std::endl;
    //    std::cout << "Could not load font." << std::endl;
    //    std::cout << "Could not load font." << std::endl;
    //
    
    
    
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
    
    //set individual health bars
    //TODO: combine setting the bars and drawing
    //TODO: make the bar positions constants and more elegant
    if(!beginGame)
    {
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
        centerText(&text, SCREENWIDTH/2, 100);
        gsm->window.draw(text);
        
        text.setCharacterSize(80);
        
        text.setString("Strength: ");
        text.setPosition(20, 600);
        gsm->window.draw(text);
        
        text.setString("Speed: ");
        text.setPosition(20, 700);
        gsm->window.draw(text);
        
        text.setString("Defense: ");
        text.setPosition(20, 800);
        gsm->window.draw(text);
        
        //draw status bars and ship sprite
        for (int i = 0; i < players; i++) {
            sp[i].setPosition(  (   (SCREENWIDTH*3/2)/(players + 1)*(i+1)   ) - ( (SCREENWIDTH*3/2)/2 - SCREENWIDTH/2 ), 300);
            gsm->window.draw(sp[i]);
            
            strength[i].setPosition( (sp[i].getPosition().x), 600);
            gsm->window.draw(strength[i]);
            
            speed[i].setPosition(sp[i].getPosition().x, 700);
            gsm->window.draw(speed[i]);
            
            defense[i].setPosition(sp[i].getPosition().x, 800);
            gsm->window.draw(defense[i]);
            
            //        std::cout << "x Position" << (SCREENWIDTH/(2 + players)*(i+1) << std::endl;
        }
        
        for (int i = 0; i < players; i++) {
            if (playerConfirmation[i] == 1)
                text.setString("Selected");
            else
                text.setString("Unselected");
            centerText(&text, (sp[i].getPosition().x), 1000);
            gsm->window.draw(text);
        }
        
        text.setCharacterSize(60);
        text.setString("Use the Left/Right Keys to Select Rocket");
        centerText(&text,SCREENWIDTH/2, SCREENHEIGHT - (text.getGlobalBounds().height*3) - 10);
        gsm->window.draw(text);
        text.setString("Use the Down Key to Confirm Selction");
        centerText(&text,SCREENWIDTH/2, SCREENHEIGHT - (text.getGlobalBounds().height*2) - 10);
        gsm->window.draw(text);
        text.setString("Press P Key to Add or Remove Player 2");
        centerText(&text,SCREENWIDTH/2, SCREENHEIGHT - text.getGlobalBounds().height - 10);
        gsm->window.draw(text);
    }
    else
    {
        
        
        
        
        
    }
    
    
    
    
}

void PickState::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == PlayerOne_Left)
            moveUpPick(0);
        if (event.key.code == PlayerOne_Right)
            moveDownPick(0);
        if (event.key.code == PlayerOne_Down)
            select(0);
        
        if (event.key.code == sf::Keyboard::P)
        {
            if (players == 2)
                players = 1;
            else
                players = 2;
        }
        if(players == 2)
        {
            if (event.key.code == PlayerTwo_Left)
                moveUpPick(1);
            if (event.key.code == PlayerTwo_Right)
                moveDownPick(1);
            if (event.key.code == PlayerTwo_Down)
                select(1);
        }
    }
}


void PickState::centerText(sf::Text *text, int x, int y) {
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + (textRect.width / 2.0f),
                    textRect.top + (textRect.height / 2.0f));
    text->setPosition(sf::Vector2f(x, y));
}



void PickState::select(int player) {
    if (playerConfirmation[player] == 0)
    {
        playerConfirmation[player] = 1;
        if(players == 1)
        {
            gsm -> numPlayer = 1;
            gsm -> pushState(PLAYSTATE);
        }
    }
    else
        playerConfirmation[player] = 0;
    
    if (playerConfirmation[0] == playerConfirmation[1] && playerConfirmation[1] == 1)
    {
        gsm -> numPlayer = 2;
        gsm -> pushState(PLAYSTATE);
    }
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

void PickState::loadFonts(){
    
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
