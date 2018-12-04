#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

extern float SCREENWIDTH;
extern float SCREENHEIGHT;
extern float VIEWWIDTH;
extern float VIEWHEIGHT;

extern float POSITIVE_INFTY;
extern float NEGATIVE_INFTY;
extern float MAXSPEED;
extern float STAGETIME;

extern sf::Keyboard::Key PlayerOne_Up;
extern sf::Keyboard::Key PlayerOne_Down;
extern sf::Keyboard::Key PlayerOne_Left;
extern sf::Keyboard::Key PlayerOne_Right;

extern sf::Keyboard::Key PlayerTwo_Up;
extern sf::Keyboard::Key PlayerTwo_Down;
extern sf::Keyboard::Key PlayerTwo_Left;
extern sf::Keyboard::Key PlayerTwo_Right;

/*
 Declare the extern here
 Define it in main.cpp until we figure out where we will actually move it...maybe lol
 
 
 
 


#define PlayerOne_Up sf::Keyboard::Up
#define PlayerOne_Down sf::Keyboard::Down
#define PlayerOne_Left sf::Keyboard::Left
#define PlayerOne_Right sf::Keyboard::Right

#define PlayerTwo_Up sf::Keyboard::W
#define PlayerTwo_Down sf::Keyboard::S
#define PlayerTwo_Left sf::Keyboard::A
#define PlayerTwo_Right sf::Keyboard::D
 */
