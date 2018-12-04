#include "../../../include/Entities/Turrets/RailGunTurret.h"
#include <math.h>

RailGunTurret::RailGunTurret(sf::Vector2f p) {
    pos = p;
    fireRate = 5;
    counter = fireRate/2;
    firingRange = (SCREENHEIGHT/3);
	damage = 5;
    withinfiringRange = false;
    attachShape();

    if (!turretImage.loadFromFile("resources/base_allgun.png")) {
        printf("Could not load turret\n");
    }

    turretTexture.loadFromImage(turretImage);
    turretTexture.setSmooth(true);
    turretObject.setTexture(turretTexture);
    turretObject.setOrigin(turretTexture.getSize().x/2, turretTexture.getSize().y/2);
    turretObject.setScale(.1, .1);
    turretObject.setPosition(p);
}

void RailGunTurret::fire() {
    if (withinfiringRange)
    {
    BeamBullet *newBullet = new BeamBullet(turretObject.getPosition(), v, ref);

    bullets.push_back(newBullet);
    counter = 0;
    }
}

void RailGunTurret::update(float dt) {
    counter += dt;
    if (counter >= fireRate) {
        fire();
    }
    v = getInitBulletVel();
    turretObject.setRotation(atan(v.y/v.x)*180/M_PI);
    if (v.x > 0) {turretObject.rotate(180.f);}
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
