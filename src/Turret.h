#ifndef __turret_H_INCLUDED__   // if x.h hasn't been included yet...
#define __turret_H_INCLUDED__


#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
using namespace std;


class turret
{
public:
    // create an empty shape
    sf::CircleShape play_ball;
    sf::ConvexShape polygonBody;
    sf::ConvexShape polygonHead;
    sf::RectangleShape rectangle;
    
    
    int defense = 5;
    int attack = 2;
    sf::Vector2f direction;
    sf::Vector2f position;
    int speed = 0;
    int maxSpeed = 8;
    float directionChangeFactor = 0.5; //Direction Change Factor
    int width = 800;
    int height = 600;
    bool moveable;
    
    
    
    //Default Constructor
    turret()
    {
        
        play_ball.setRadius(20);
        play_ball.setPointCount(20);
        play_ball.setOrigin(-100, -100);
        direction.x = 0;
        direction.y = 0;
        position.x = play_ball.getPosition().x;
        position.y = play_ball.getPosition().y;
        speed = 2;
        
        sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
        rectangle.setSize(sf::Vector2f(300.f, 300.f));
        
        
        createTurret();
        
        moveable = true;
        
        
    }
    
    
    void move(int angle)
    {
        setDirection(angle);
        if (moveable)
        {
            rectangle.move(direction.x,direction.y);
        }
        moveItMoveIt();
        setPosition(play_ball);
        std::cout << "Turret Position: " << position.x << ", " << position.y << std::endl;
    }
    
    void setDirection(int angle)
    {
        switch(angle){
                
            case 90: // Moving straight up
                direction.x = 0;
                direction.y = -height/20;
//                if (direction.x > 0) {direction.x = direction.x - directionChangeFactor;} //resets x to zero if y > 0
//                if (direction.x < 0) {direction.x = direction.x + directionChangeFactor;} //resets x to zero if y < 0
//                if (direction.y > (-maxSpeed)) {direction.y = direction.y - directionChangeFactor;}
                break;
                
                
            case 180: // Moving straight left
                direction.x = -width/20;
                direction.y = 0;
//                if (direction.x > (-maxSpeed)) {direction.x = direction.x - directionChangeFactor;}
//                if (direction.y > 0) {direction.y = direction.y - directionChangeFactor;} //resets y to zero if y > 0
//                if (direction.y < 0) {direction.y = direction.y + directionChangeFactor;} //resets y to zero if y < 0
                break;
                
            case 270: // Moving straight down
                direction.x = 0;
                direction.y = height/20;
//                if (direction.x > 0) {direction.x = direction.x - directionChangeFactor;} //resets x to zero if y > 0
//                if (direction.x < 0) {direction.x = direction.x + directionChangeFactor;} //resets x to zero if y < 0
//                if (direction.y < maxSpeed) {direction.y = direction.y + directionChangeFactor;}
                break;

            case 360: // Moving straight right
                direction.x = width/20;
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
    
    void setPosition(sf::CircleShape shape)
    {
        position.x = shape.getPosition().x;
        position.y = shape.getPosition().y;
    }
    
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
        polygonBody.move(speed*direction.x, speed*direction.y);
        polygonHead.move(speed*direction.x, speed*direction.y);
    }
    
    void createTurret()
    {
        rectangle.setSize(sf::Vector2f(20, 20));
        rectangle.setOrigin(10,10);
        rectangle.setPosition(100, 100);
        
        polygonBody.setPointCount(4);
        polygonBody.setPoint(0, sf::Vector2f(0, -10));
        polygonBody.setPoint(1, sf::Vector2f(20, -10));
        polygonBody.setPoint(2, sf::Vector2f(20, 10));
        polygonBody.setPoint(3, sf::Vector2f(0, 10));
        polygonBody.setOutlineColor(sf::Color::White);
        polygonBody.setOutlineThickness(5);
        polygonBody.setFillColor(sf::Color::White);
        polygonBody.setPosition(200, 200);
        
        polygonHead.setPointCount(3);
        polygonHead.setPoint(0, sf::Vector2f(20, -15));
        polygonHead.setPoint(1, sf::Vector2f(30, -0));
        polygonHead.setPoint(2, sf::Vector2f(20, 15));
        polygonHead.setOutlineColor(sf::Color::White);
        polygonHead.setOutlineThickness(5);
        polygonHead.setFillColor(sf::Color::White);
        polygonHead.setPosition(210, 200);

    }
    
    void setMovement()
    {
        moveable = !moveable;
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
