
#include "GuidedTurret.h"
#include <math.h>

GuidedTurret::GuidedTurret(sf::Vector2f p) {
    pos = p;
    fireRate = 10;
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

void GuidedTurret::fire() {
    GuidedBullet *newBullet = new GuidedBullet(pos, getInitBulletVel(), ref);
    bullets.push_back(newBullet);
}

void GuidedTurret::explode(){
    bullets.pop_back();
}

void GuidedTurret::update(float dt) {
    counter += dt;
    if (counter >= fireRate) {
        if(!bullets.empty()) explode();
        fire();
        counter = 0;
    }
    
    for (int i = 0; i < bullets.size(); i++) {
        bullets.at(i)->update(dt);
    }
}

sf::Vector2f GuidedTurret::getInitBulletVel() {
    sf::Vector2f ship1_init = (ref->ship1.pos - pos);
    sf::Vector2f ship2_init = (ref->ship2.pos - pos);
    float ship1_dist = pow((ship1_init.x*ship1_init.x + ship1_init.y*ship1_init.y),0.5);
    float ship2_dist = pow((ship2_init.x*ship2_init.x + ship2_init.y*ship2_init.y),0.5);
    
    if (ship1_dist < ship2_dist)
        return normalize(ship1_init);
    else
        return normalize(ship2_init);
}

sf::Vector2f GuidedTurret::normalize(sf::Vector2f & v) {
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
