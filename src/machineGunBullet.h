#include "bullet.h"
#include<math.h>

class machineGunBullet : public bullet {
    
public:
    sf::CircleShape shell;
    sf::Vector2f direction;
    
    int speed = 0;
    int radius = 10;
    int width = 800;
    int height = 600;
    
    machineGunBullet(sf::Vector2f direction1, sf::Vector2f direction2, sf::Vector2f turretLocation){
        
        //create the basic object of the bullet
        shell.setRadius(radius);
        shell.setPointCount(20);
        shell.setOrigin(-100, -100);
    
        
        speed = 2;
        
        //compare the distances between the turret and the ships
        //give the bullet the direction of the nearest ship
        //NOTE: if the ships are the same distance, the bullet will fly towrds the one winning the race
        if( pow(pow(direction1.x - turretLocation.x,2)+pow(direction1.y - turretLocation.y,2),.5) < pow(pow(direction2.x - turretLocation.x,2)+pow(direction2.y - turretLocation.y,2),.5)){
            
            direction.x = speed*(turretLocation.x - direction1.x)*-1;
            direction.y = speed*(turretLocation.y - direction1.y);
            
        }
        else if(pow(pow(direction1.x - turretLocation.x,2)+pow(direction1.y - turretLocation.y,2),.5) > pow(pow(direction2.x - turretLocation.x,2)+pow(direction2.y - turretLocation.y,2),.5)){
            direction.x = speed*(turretLocation.x - direction2.x)*-1;
            direction.y = speed*(turretLocation.y - direction2.y);
        }
        
        else if(direction1.x > direction2.x){
            direction.x = speed*(turretLocation.x - direction1.x)*-1;
            direction.y = speed*(turretLocation.y - direction1.y);
        }
        
        else {
            direction.x = speed*(turretLocation.x - direction2.x)*-1;
            direction.y = speed*(turretLocation.y - direction2.y);
        }
        
    }
    
    void disposeObject()
    {
        delete this;
    }
    
    void move(){
        shell.move(direction.x, direction.y);
        if(!withinBounds()){
            disposeObject();
        }
    }
    
    
    //NOTE: will need to change this later when the screen view is dynamic
    bool withinBounds(){
        if(shell.getPosition().x + 20 < width &&
           shell.getPosition().x - 20 > 0 &&
           shell.getPosition().y + 20 < height &&
           shell.getPosition().y - 20 > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
