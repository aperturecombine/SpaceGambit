#include "bullet.h"
#include<math.h>

class machineGunBullet : public bullet {
    
public:
    sf::CircleShape shell;
    sf::Vector2f direction;
    
    float speed = 0.15;
    int bulletRate = 500; //used in turret to determine how fast to shoot
    int radius = 10;
    int width = 800;
    int height = 600;
    
    machineGunBullet(){
        
    }
    
    machineGunBullet(sf::Vector2f ship1Coord, sf::Vector2f ship2Coord, sf::Vector2f turretLocation){
        
        //create the basic object of the bullet
        shell.setRadius(radius);
        shell.setPointCount(20);
        shell.setOrigin(radius/2, radius/2);
        
        shell.setPosition(turretLocation.x, turretLocation.y);
        
        
        //compare the distances between the turret and the ships
        //give the bullet the direction of the nearest ship
        //NOTE: if the ships are the same distance, the bullet will fly towrds the one winning the race
        if( dist(ship1Coord, turretLocation) < dist(ship2Coord, turretLocation))
        { // checks if ship1 is closer than ship2
            //shoots at ship1
            direction.x = speed*(turretLocation.x - ship1Coord.x)*-1/dist(ship1Coord, turretLocation);
            direction.y = speed*(turretLocation.y - ship1Coord.y)*-1/dist(ship1Coord, turretLocation);
            
        }
        else if(dist(ship1Coord, turretLocation) > dist(ship2Coord, turretLocation))
        { // checks if ship2 is closer than ship1
            //shoots at ship2
            direction.x = speed*(turretLocation.x - ship2Coord.x)*-1/dist(ship2Coord, turretLocation);
            direction.y = speed*(turretLocation.y - ship2Coord.y)*-1/dist(ship2Coord, turretLocation);
        }
        else if(ship1Coord.x > ship2Coord.x)
        { // here the distances are the same, so its checking if x-coordinate of ship1 is closer than ship2
            //shoots at ship1
            direction.x = speed*(turretLocation.x - ship1Coord.x)*-1/dist(ship1Coord, turretLocation);
            direction.y = speed*(turretLocation.y - ship1Coord.y)*-1/dist(ship1Coord, turretLocation);
        }
        else
        { // default cause: distances for both ships are the same, and the ship1 x-coordinate is further than ship2 x-coordinate
            //shoots at ship2
            direction.x = speed*(turretLocation.x - ship2Coord.x)*-1/dist(ship2Coord, turretLocation);
            direction.y = speed*(turretLocation.y - ship2Coord.y)*-1/dist(ship2Coord, turretLocation);
        }
        
    }
    
    float dist(sf::Vector2f location1, sf::Vector2f location2)
    {
        float distance;
        distance = pow(pow(location1.x - location2.x,2)+pow(location1.y - location2.y,2),0.5);
        return distance;
    }
    
    
    void move(){
        shell.move(direction.x, direction.y);
    }
    
    
    //NOTE: will need to change this later when the screen view is dynamic
    bool withinBounds(){
        if(shell.getPosition().x + radius/2 < width &&
           shell.getPosition().x - radius/2 > 0 &&
           shell.getPosition().y + radius/2 < height &&
           shell.getPosition().y - radius/2 > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
