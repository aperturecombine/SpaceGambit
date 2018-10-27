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
    sf::CircleShape rocketShipObject;
    
    int defense = 5;
    int attack = 2;
    sf::Vector2f direction;
    float speed = 1;
    float maxSpeed = 10;
    float directionChangeFactor = 1; //Direction Change Factor
    int width = 800;
    int height = 600;
    
    
    
    //Default Constructor
    rocketShip()
    {
        // sf::CircleShape rocketShipObject;
        rocketShipObject.setRadius(20);
        rocketShipObject.setPointCount(20);
//        rocketShipObject.setOrigin(-100, -100);
        rocketShipObject.setPosition(rand() % 500 + 1,10 +rand() % 500 + 1);
        direction.x = 0;
        direction.y = 0;
        speed = 1;
        
    }
    
    
    void move(int angle)
    {
        setDirection(angle);
        // if (withinBonds())
        rocketShipObject.move(speed*direction.x, speed*direction.y);
//        std::cout << "Rocket Position: " << rocketShipObject.getPosition().x << ", " << rocketShipObject.getPosition().y<< std::endl;
//        std::cout << "\tRocket Speed: " << speed*direction.x << " - " << speed*direction.y << std::endl;
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
                if (direction.x > 0) {direction.x = direction.x - directionChangeFactor;} //resets x to zero if y > 0
                if (direction.x < 0) {direction.x = direction.x + directionChangeFactor;} //resets x to zero if y < 0
                if (direction.y > 0) {direction.y = direction.y - directionChangeFactor;} //resets y to zero if y > 0
                if (direction.y < 0) {direction.y = direction.y + directionChangeFactor;} //resets y to zero if y < 0
                break;
        }
    }
    
    
    bool withinBounds()
    {
        if(rocketShipObject.getPosition().x + 20 < width &&
           rocketShipObject.getPosition().x - 20 > 0 &&
           rocketShipObject.getPosition().y + 20 < height &&
           rocketShipObject.getPosition().y - 20 > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    sf::Vector2f getRocketPosition()
    {
        return rocketShipObject.getPosition();
    }
    
//    int getRocketPositionY()
//    {
//        return rocketShipObject.getPosition().y;
//    }
    
    
    
};



#endif
