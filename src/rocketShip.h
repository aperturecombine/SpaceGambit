#ifndef __rocketShip_H_INCLUDED__   // if x.h hasn't been included yet...
#define __rocketShip_H_INCLUDED__


#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
using namespace std;


class rocketShip
{
public:
    // create an empty shape
    sf::CircleShape play_ball;
    
    int defense = 5;
    int attack = 2;
    sf::Vector2f direction;
    int speed = 0;
    int maxSpeed = 6;
    float directionChangeFactor = 2; //Direction Change Factor
    int width = 800;
    int height = 600;
    
    
    
    //Default Constructor
    rocketShip()
    {
        // sf::CircleShape play_ball;
        play_ball.setRadius(20);
        play_ball.setPointCount(20);
        play_ball.setOrigin(-100, -100);
        direction.x = 0;
        direction.y = 0;
        speed = 2;
        
    }
    
    
    void move(int angle)
    {
        setDirection(angle);
        // if (withinBonds())
        play_ball.move(speed*direction.x, speed*direction.y);
        std::cout << "Rocket Position: " << play_ball.getPosition().x << ", " << play_ball.getPosition().y << std::endl;
    }
    
    
    
    void setDirection(int angle)
    {
        switch(angle){
            case 45: // Moving right and up
                if (direction.x < maxSpeed) {direction.x = direction.x + directionChangeFactor;}
                if (direction.y > (-maxSpeed)) {direction.y = direction.y - directionChangeFactor;}
                break;
                
            case 90: // Moving straight up
                if (direction.x > 0) {direction.x = direction.x - directionChangeFactor;} //resets x to zero if y > 0
                if (direction.x < 0) {direction.x = direction.x + directionChangeFactor;} //resets x to zero if y < 0
                if (direction.y > (-maxSpeed)) {direction.y = direction.y - directionChangeFactor;}
                break;
                
            case 135: // Moving left and up
                if (direction.x > (-maxSpeed)) {direction.x = direction.x - directionChangeFactor;}
                if (direction.y > (-maxSpeed)) {direction.y = direction.y - directionChangeFactor;}
                break;
                
            case 180: // Moving straight left
                if (direction.x > (-maxSpeed)) {direction.x = direction.x - directionChangeFactor;}
                if (direction.y > 0) {direction.y = direction.y - directionChangeFactor;} //resets y to zero if y > 0
                if (direction.y < 0) {direction.y = direction.y + directionChangeFactor;} //resets y to zero if y < 0
                break;
                
            case 225: // Moving left and down
                if (direction.x > (-maxSpeed)) {direction.x = direction.x - directionChangeFactor;}
                if (direction.y < maxSpeed) {direction.y = direction.y + directionChangeFactor;}
                break;
                
            case 270: // Moving straight down
                if (direction.x > 0) {direction.x = direction.x - directionChangeFactor;} //resets x to zero if y > 0
                if (direction.x < 0) {direction.x = direction.x + directionChangeFactor;} //resets x to zero if y < 0
                if (direction.y < maxSpeed) {direction.y = direction.y + directionChangeFactor;}
                break;
                
            case 315: // Moving right and down
                if (direction.x < maxSpeed) {direction.x = direction.x + directionChangeFactor;}
                if (direction.y < maxSpeed) {direction.y = direction.y + directionChangeFactor;}
                break;
                
            case 360: // Moving straight right
                if (direction.x < maxSpeed) {direction.x = direction.x + directionChangeFactor;}
                if (direction.y > 0) {direction.y = direction.y - directionChangeFactor;} //resets y to zero if y > 0
                if (direction.y < 0) {direction.y = direction.y + directionChangeFactor;} //resets y to zero if y < 0
                break;
                
            default: // There should be no direction
                if (direction.x > 0) {direction.x = direction.x - 0.5*directionChangeFactor;} //resets x to zero if y > 0
                if (direction.x < 0) {direction.x = direction.x + 0.5*directionChangeFactor;} //resets x to zero if y < 0
                if (direction.y > 0) {direction.y = direction.y - 0.5*directionChangeFactor;} //resets y to zero if y > 0
                if (direction.y < 0) {direction.y = direction.y + 0.5*directionChangeFactor;} //resets y to zero if y < 0
                break;
        }
    }
    
    
    bool withinBonds()
    {
        
        
        if(play_ball.getPosition().x + 20 < width &&
           play_ball.getPosition().x - 20 > 0 &&
           play_ball.getPosition().y + 20 < height &&
           play_ball.getPosition().y - 20 > 0)
        {
            return true;
        }
        else
        {
            
            
            
            return false;
        }
    }
    
    
};



#endif
