#pragma once
#include <string.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "States/GameState.h"
#include "Renderer.h"
#include "Globals.h"
#include "States/PlayState.h"
#include "States/MenuState.h"
#include "States/GameStateManager.h"
#include "../include/Entities/Turrets/Turret.h"

class Renderer {
public:
	Renderer() {}
	Renderer(GameStateManager * g);
	void draw(sf::RenderWindow *window);
	void handleInput(sf::Event event);
	void setState(int newState);
	GameState * state;
	
	void setShipTypes(int s1, int s2) {
		shipTypes[0] = s1;
		shipTypes[1] = s2;
	}

	void changeVolume(int v) {
		volume = v;
		playMusic.setVolume(volume);
		menuMusic.setVolume(volume);
		pauseMusic.setVolume(volume);
	}
	int getVolume() { return volume; }

private:
	GameStateManager * gsm;
	void centerText(sf::Text *text, int y);

	void loadPauseFonts();

	void loadFont(sf::Font * font, std::string filename);
	void loadTexture(sf::Texture * texture, std::string filename);
	void loadImage(sf::Image * image, std::string filename);

	int currState;

	sf::Image image;
	sf::Font font;
	sf::Text text;
	sf::Texture texture;
	sf::Sprite background;
	std::string options[3] = { "Play", "Options", "Quit" };

	std::string oOptions[5] = { "Adjust Screen Resolution",
								"Adjust Volume       ",
								"Change Player 1 Controls",
								"Change Player 2 Controls",
								"Return to Menu" };
    
    std::string resolution[3]= {"720px by 720px", "1440px by 1440px", "2160px by 2160px"};
    std::string keybindings[3]= {"W,A,S,D", "Up Arrow, Down Arrow, Left Arrow, Right Arrow", "2160px by 2160px"};
    
    //Menu
    sf::Texture title;
    sf::Sprite titleImage;
    
    
	// PICKSTATE
	sf::Sprite sp[2];

	sf::Sprite rocket[2];
	sf::Texture imagePower[3];
	sf::Texture backgroundTexture;

	sf::RectangleShape strength[2];
	sf::RectangleShape speed[2];
	sf::RectangleShape defense[2];

	// PLAYSTATE
	sf::Texture hudTexture;

	sf::CircleShape bulletCircle;
	sf::Image hudImage;
	sf::Sprite hud;
	sf::RectangleShape bar;
	sf::RectangleShape health;
	sf::RectangleShape bar2;
	sf::RectangleShape health2;
	sf::Text text2;
	sf::Text stage;
	sf::Text stageCount;
	sf::Text timer;
	sf::Text levelCount;
	sf::Text levelNumber;
	sf::Text levelTimer;
	sf::Text timerCount;
	sf::Texture rocketShipTextures[2];
	sf::Image rocketShipImages[2];
	sf::Sprite rocketShipObjects[2];

	sf::RectangleShape pauseState;
	sf::Texture pauseTexture;
	sf::Sprite pauseSprite;

	sf::Texture textureP1;
	sf::Sprite sP1;
	sf::Texture textureP2;
	sf::Sprite sP2;
	sf::Texture textureP3;
	sf::Sprite sP3;
	sf::Texture textureP4;
	sf::Sprite sP4;

	sf::Music playMusic;
	sf::Music menuMusic;
	sf::Music pauseMusic;
	int volume = 50;

	// FINISHSTATE
	std::string fOptions[2] = { "Return to Menu", "Quit" };

	int shipTypes[2];
};
