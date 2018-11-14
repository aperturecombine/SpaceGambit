

#include "BoomerangBullet.h"

BoomerangBullet::BoomerangBullet(sf::Vector2f p, sf::Vector2f v) {
    pos = p;
    vel = v;
    speed = 300;
    isAlive = true;
    radius = 5;
    returnCounter = 0;
    returnPoint = 2;
    isAlive = true;
    travelled = false;
}

void BoomerangBullet::update(float dt) {

    if (returnCounter >= 2*returnPoint){
        isAlive = false;
    }
    else if ((returnCounter >= returnPoint) && !travelled){
        vel.x = vel.x * -1;
        vel.y = vel.y * -1;
        travelled = true;
    }
    
    pos += vel * speed * dt;
    returnCounter += dt;
}

//bool BoomerangBullet::finished() {
//    if (returnCounter == 2*returnPoint){
//        return true;
//    }
//    
//    return false;
//}
