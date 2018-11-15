
#include "./Entities/Turrets/GlueGunTurret.h"
#include <math.h>

GlueGunTurret::GlueGunTurret(sf::Vector2f p) {
    pos = p;
    fireRate = .2;
    counter = fireRate;
    counter1 = 0;
    counter2 = 0;
    firingRange = 300;
    withinfiringRange = false;
    linger = 2;
    attachShape();
    
    if (!turretImage.loadFromFile("resources/glueGunTurret.png")) {
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

void GlueGunTurret::fire() {
//    if (withinfiringRange)
//    {
////    GlueGunBullet *newBullet = new GlueGunBullet(pos, getInitBulletVel());
////    bullets.push_back(newBullet);
//    }
}

void GlueGunTurret::update(float dt) {
    counter += dt;
    counter1 += dt;
    counter2 += dt;
    
    sf::Vector2f ship1_init = (ref->ship1.pos - pos);
    sf::Vector2f ship2_init = (ref->ship2.pos - pos);
    float ship1_dist = pow((ship1_init.x*ship1_init.x + ship1_init.y*ship1_init.y),0.5);
    float ship2_dist = pow((ship2_init.x*ship2_init.x + ship2_init.y*ship2_init.y),0.5);
    
    
    if (ship2_dist < firingRange){
        counter2 = 0;
        ref->ship2.maxSpeed = MAXSPEED*.5;
        
        GlueBullet *newBullet = new GlueBullet(pos, normalize(ship2_init));
        bullets.push_back(newBullet);
//        std::cout << "fire2" << std::endl;
        
    }
    if (ship1_dist < firingRange) {
        counter1 = 0;
        ref->ship1.maxSpeed = MAXSPEED*.5;
        
        GlueBullet *newBullet = new GlueBullet(pos, normalize(ship1_init));
        bullets.push_back(newBullet);
//        std::cout << "fire2" << std::endl;
        
    }
    
    if (counter > linger){
        ref->ship1.maxSpeed = MAXSPEED;
    }
    if (counter2 > linger){
        ref->ship2.maxSpeed = MAXSPEED;
    }
    
    if (counter >= fireRate) {
        fire();
        counter = 0;
    }
    
    for (int i = 0; i < bullets.size(); i++) {
        bullets.at(i)->update(dt);
        sf::Vector2f position = bullets.at(i)->pos;
        sf::Vector2f bullet_init = (position - pos);
        float bullet_dist = pow((bullet_init.x*bullet_init.x + bullet_init.y*bullet_init.y),0.5);
        if (bullet_dist > firingRange){
            bullets.erase(bullets.begin() + i);
        }
    }
}

sf::Vector2f GlueGunTurret::getInitBulletVel() {
    sf::Vector2f ship1_init = (ref->ship1.pos - pos);
    sf::Vector2f ship2_init = (ref->ship2.pos - pos);
    float ship1_dist = pow((ship1_init.x*ship1_init.x + ship1_init.y*ship1_init.y),0.5);
    float ship2_dist = pow((ship2_init.x*ship2_init.x + ship2_init.y*ship2_init.y),0.5);


    if (ship1_dist < ship2_dist)
    {
        if (ship1_dist < firingRange) {withinfiringRange=true;}
        else {withinfiringRange=false;}
        return normalize(ship1_init);
    }
    else
    {
        if (ship1_dist < firingRange) {withinfiringRange=true;}
        else {withinfiringRange=false;}
        return normalize(ship2_init);
    }
}

sf::Vector2f GlueGunTurret::normalize(sf::Vector2f & v) {
    float length = sqrt((v.x * v.x) + (v.y * v.y));
    if (length != 0)
        return sf::Vector2f(v.x / length, v.y / length);
    else
        return v;
}
