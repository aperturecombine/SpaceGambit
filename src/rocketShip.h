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
    float startSpeed = 1;
    float maxSpeed = 10;
    float directionChangeFactor = 1; //Direction Change Factor
    int width = 800;
    int height = 600;
    int radius = 20;
    
    
    
    //Default Constructor
    rocketShip()
    {
        // sf::CircleShape rocketShipObject;
        rocketShipObject.setRadius(radius);
        rocketShipObject.setPointCount(20);
        rocketShipObject.setOrigin(radius, radius);
        rocketShipObject.setPosition(rand() % 500 + 1,10 +rand() % 500 + 1); // random rocket start placement
        direction.x = 0;
        direction.y = 0;
    }
    
    
    void move(int angle)
    {
        setDirection(angle);
        movement();
        
        //        std::cout << "Rocket Position: " << rocketShipObject.getPosition().x << ", " << rocketShipObject.getPosition().y<< std::endl;
        //        std::cout << "\tRocket startSpeed: " << startSpeed*direction.x << " - " << startSpeed*direction.y << std::endl;
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
        direction.x = (startSpeed*direction.x);
        direction.y = (startSpeed*direction.y);
    }
    
    
    bool withinBounds(){
        if(rocketShipObject.getPosition().x + radius <= width &&
           rocketShipObject.getPosition().x - radius >= 0 &&
           rocketShipObject.getPosition().y + radius <= height &&
           rocketShipObject.getPosition().y - radius >= 0)
        {

            return true;
        }
        else
        {
            return false;
        }
    }
    
    void movement()
    {
        /*
         Calculates where the rocket will move next
         Adjusts movement if the rocket would move off the screen
         */
        int newShipPositionX = rocketShipObject.getPosition().x + direction.x;
        int newShipPositionY = rocketShipObject.getPosition().y + direction.y;
        bool notMoved = true;
        
        if(newShipPositionX + radius> width)
        {
            rocketShipObject.setPosition(width - radius, rocketShipObject.getPosition().y + direction.y);
            notMoved = false;
        }
        if(newShipPositionX - radius < 0)
        {
            rocketShipObject.setPosition(radius, rocketShipObject.getPosition().y + direction.y);
            notMoved = false;
        }
        
        if(newShipPositionY + radius > height)
        {
            rocketShipObject.setPosition(rocketShipObject.getPosition().x + direction.x, height - radius);
            notMoved = false;
        }
        if(newShipPositionY - radius < 0)
        {
            rocketShipObject.setPosition(rocketShipObject.getPosition().x + direction.x, radius);
            notMoved = false;
        }
        
        
        if (notMoved) // If none of the previous condition occur, then move
        {
            rocketShipObject.move(direction.x, direction.y);
        }
    }
    
    
    
    
    
    sf::Vector2f getRocketPosition()
    {
        return rocketShipObject.getPosition();
    }
    
    
    
};



#endif
