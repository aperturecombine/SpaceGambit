#include "../../include/States/PickState.h"


PickState::PickState(class GameStateManager *g) {
    gsm = g;
	stateID = PICKSTATE;
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
//            playerConfirmation[0] = 0;
            gsm -> pushState(PLAYSTATE);
        }
    }
    else
        playerConfirmation[player] = 0;

    if (playerConfirmation[0] == playerConfirmation[1] && playerConfirmation[1] == 1)
    {
		printf("SELECT!\n");
		playerConfirmation[0] = 0;
		playerConfirmation[1] = 0;
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
