#include "../../../include/Entities/Turrets/RailGunTurret.h"
#include <math.h>

RailGunTurret::RailGunTurret(sf::Vector2f p) {
    pos = p;
    fireRate = 5;
    counter = fireRate;
    firingRange = 500;
    withinfiringRange = false;
    attachShape();

    if (!turretImage.loadFromFile("resources/railGunTurret.png")) {
        printf("Could not load turret\n");
    }

    turretTexture.loadFromImage(turretImage);
    turretTexture.setSmooth(true);
    turretObject.setTexture(turretTexture);
    turretObject.setScale(.3, .3);
    turretObject.setOrigin((turretObject.getTexture()->getSize().x) / 2,
                           (turretObject.getTexture()->getSize().y) / 2);
    turretObject.setPosition(p);
}

void RailGunTurret::fire() {
    sf::Vector2f v = getInitBulletVel();
    turretObject.setRotation(360.f + atan(v.y/v.x)*180/M_PI);
    if (withinfiringRange)
    {
    BeamBullet *newBullet = new BeamBullet(pos, v, ref);

    bullets.push_back(newBullet);
    counter = 0;
    }
}

void RailGunTurret::update(float dt) {
    counter += dt;
    if (counter >= fireRate) {
        fire();
    }

    for (int i = 0; i < bullets.size(); i++) {
        bullets.at(i)->update(dt);
    }
}

sf::Vector2f RailGunTurret::getInitBulletVel() {
    sf::Vector2f ship1_init = (ref->ship1.pos - pos);
    float ship1_dist = pow((ship1_init.x*ship1_init.x + ship1_init.y*ship1_init.y),0.5);
    if(ref->twoPlayerMode){
        sf::Vector2f ship2_init = (ref->ship2.pos - pos);
        float ship2_dist = pow((ship2_init.x*ship2_init.x + ship2_init.y*ship2_init.y),0.5);
        
        if (ship1_dist < ship2_dist)
        {
            if (ship1_dist < firingRange) {withinfiringRange=true;}
            else {withinfiringRange=false;}
            return normalize(ship1_init);
        }
        else
        {
            if (ship2_dist < firingRange) {withinfiringRange=true;}
            else {withinfiringRange=false;}
            return normalize(ship2_init);
        }
    }
    else
    {
        if (ship1_dist < firingRange) {withinfiringRange=true;}
        else {withinfiringRange=false;}
        return normalize(ship1_init);
    }
}

sf::Vector2f RailGunTurret::normalize(sf::Vector2f & v) {
    float length = sqrt((v.x * v.x) + (v.y * v.y));
    if (length != 0)
        return sf::Vector2f(v.x / length, v.y / length);
    else
        return v;
}
