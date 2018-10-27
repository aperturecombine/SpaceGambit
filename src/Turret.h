#ifndef __turret_H_INCLUDED__   // if x.h hasn't been included yet...
#define __turret_H_INCLUDED__


#include <SFML/Graphics.hpp>
#include <math.h>
#include "machineGunBullet.h"
#include <iostream>
using namespace std;


class turret
{
public:
    // create an empty shape
    sf::RectangleShape turretObject;
    
    int defense = 5;
    int attack = 2;
    sf::Vector2f direction;
    sf::Vector2f position;

    //Direction Change Factor
    int windowWidth = 800;
    int windowHeight = 600;
    bool moveable;
    bool finalLocation;
    
    machineGunBullet b1;
    
    
    //Default Constructor
    turret(int x, int y)
    {
        direction.x = 0;
        direction.y = 0;
        position.x = x;
        position.y = y;
        
        b1 = machineGunBullet(sf::Vector2f(10,10),sf::Vector2f(10,10),sf::Vector2f(x,y));
        
        createTurret();
        
        moveable = true;
        finalLocation = false;
    }
    
    void fire(){
        b1.move();
    }
    
    
    void move(int angle)
    {
        setDirection(angle);
        if (false)
        {
            turretObject.move(direction.x,direction.y);
        }
        moveItMoveIt();
//        setPosition(play_ball);
        std::cout << "Turret Position: " << position.x << ", " << position.y << std::endl;
    }
    
    void setDirection(int angle)
    {
        switch(angle){
                
            case 90: // Moving straight up
                direction.x = 0;
                direction.y = -windowHeight/20;
//                if (direction.x > 0) {direction.x = direction.x - directionChangeFactor;} //resets x to zero if y > 0
//                if (direction.x < 0) {direction.x = direction.x + directionChangeFactor;} //resets x to zero if y < 0
//                if (direction.y > (-maxSpeed)) {direction.y = direction.y - directionChangeFactor;}
                break;
                
                
            case 180: // Moving straight left
                direction.x = -windowWidth/20;
                direction.y = 0;
//                if (direction.x > (-maxSpeed)) {direction.x = direction.x - directionChangeFactor;}
//                if (direction.y > 0) {direction.y = direction.y - directionChangeFactor;} //resets y to zero if y > 0
//                if (direction.y < 0) {direction.y = direction.y + directionChangeFactor;} //resets y to zero if y < 0
                break;
                
            case 270: // Moving straight down
                direction.x = 0;
                direction.y = windowHeight/20;
//                if (direction.x > 0) {direction.x = direction.x - directionChangeFactor;} //resets x to zero if y > 0
//                if (direction.x < 0) {direction.x = direction.x + directionChangeFactor;} //resets x to zero if y < 0
//                if (direction.y < maxSpeed) {direction.y = direction.y + directionChangeFactor;}
                break;

            case 360: // Moving straight right
                direction.x = windowWidth/20;
                direction.y = 0;
//                if (direction.x < maxSpeed) {direction.x = direction.x + directionChangeFactor;}
//                if (direction.y > 0) {direction.y = direction.y - directionChangeFactor;} //resets y to zero if y > 0
//                if (direction.y < 0) {direction.y = direction.y + directionChangeFactor;} //resets y to zero if y < 0
                break;
                
            default: // There should be no direction
                direction.x = 0;
                direction.y = 0;
                break;
        }
    }
    
//    void setPosition(sf::CircleShape shape)
//    {
//        position.x = shape.getPosition().x;
//        position.y = shape.getPosition().y;
//    }
    
    int getXPosition(sf::CircleShape shape)
    {
        return position.x;
    }
    
    int getYPosition(sf::CircleShape shape)
    {
        return position.y;
    }
    
    void moveItMoveIt()
    {

    }
    
    void createTurret()
    {
        turretObject.setSize(sf::Vector2f(100.f, 100.f));
        turretObject.setOrigin(10,10);
        turretObject.setPosition(position.x, position.y);
    }
    
    
    void setMovement()
    {
        moveable = !moveable;
        
        confirmLocation();

    }
    
    void confirmLocation()
    {
        if (finalLocation)
            {
                moveable = false;
            }
        else
        {
            moveable = true;
        }
    }
    
    
    
//    bool withinBonds()
//    {
//        if(play_ball.getPosition().x + 20 < windowWidth &&
//           play_ball.getPosition().x - 20 > 0 &&
//           play_ball.getPosition().y + 20 < windowHeight &&
//           play_ball.getPosition().y - 20 > 0)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
    
    
    
    
};



#endif
