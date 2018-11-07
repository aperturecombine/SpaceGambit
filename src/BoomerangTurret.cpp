
#include "BoomerangTurret.h"
#include <math.h>

BoomerangTurret::BoomerangTurret(sf::Vector2f p) {
    pos = p;
    fireRate = .45;
    counter = 0;
    
    if (!turretImage.loadFromFile("resources/turret.png")) {
        printf("Could not load turret");
    }
    
    turretTexture.loadFromImage(turretImage);
    turretTexture.setSmooth(true);
    turretObject.setTexture(turretTexture);
    turretObject.setScale(.3, .3);
    turretObject.setOrigin((turretObject.getTexture()->getSize().x) / 2,
                           (turretObject.getTexture()->getSize().y) / 2);
    turretObject.setPosition(p);
}

void BoomerangTurret::fire() {
    BoomerangBullet *newBullet = new BoomerangBullet(pos, getInitBulletVel());
    bullets.push_back(newBullet);
}

void BoomerangTurret::update(float dt) {
    counter += dt;
    if (counter >= fireRate) {
        fire();
        counter = 0;
    }
    
    for (int i = 0; i < bullets.size(); i++) {
        bullets.at(i)->update(dt);
    }
}

sf::Vector2f BoomerangTurret::getInitBulletVel() {
    sf::Vector2f init = (ref->ship1.pos - pos);
    
    return normalize(init);
}

sf::Vector2f BoomerangTurret::normalize(sf::Vector2f & v) {
    float length = sqrt((v.x * v.x) + (v.y * v.y));
    if (length != 0)
        return sf::Vector2f(v.x / length, v.y / length);
    else
        return v;
}

/*void setDirection(int angle) {
 switch (angle) {
 case 90: // Moving straight up
 direction.x = 0;
 direction.y = -windowHeight / 20;
 break;
 
 case 180: // Moving straight left
 direction.x = -windowWidth / 20;
 direction.y = 0;
 break;
 
 case 270: // Moving straight down
 direction.x = 0;
 direction.y = windowHeight / 20;
 break;
 
 case 360: // Moving straight right
 direction.x = windowWidth / 20;
 direction.y = 0;
 break;
 
 default: // There should be no direction
 direction.x = 0;
 direction.y = 0;
 break;
 }
 }*/
