#include <SFML/Graphics.hpp>
#include "../include/States/GameStateManager.h"
#include <Box2D/Box2D.h>
#include "../include/Globals.h"


float SCREENWIDTH = 2160;
float SCREENHEIGHT = SCREENWIDTH;
float RESOLUTION = 720;
float POSITIVE_INFTY = 100000000000000;
float NEGATIVE_INFTY = -100000000000000;
float MAXSPEED = 500;
float STAGETIME = 30;


sf::Keyboard::Key PlayerOne_Up = sf::Keyboard::Up;
sf::Keyboard::Key PlayerOne_Down = sf::Keyboard::Down;
sf::Keyboard::Key PlayerOne_Left = sf::Keyboard::Left;
sf::Keyboard::Key PlayerOne_Right = sf::Keyboard::Right;


sf::Keyboard::Key PlayerTwo_Up = sf::Keyboard::W;
sf::Keyboard::Key PlayerTwo_Down = sf::Keyboard::S;
sf::Keyboard::Key PlayerTwo_Left = sf::Keyboard::A;
sf::Keyboard::Key PlayerTwo_Right = sf::Keyboard::D;





int main() {

	GameStateManager gsm;
	gsm.start();
}
