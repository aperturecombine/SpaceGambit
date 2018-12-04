#include "../../../include/Entities/Turrets/BoomerangTurret.h"
#include <math.h>

BoomerangTurret::BoomerangTurret(sf::Vector2f p) {

    fireRate = .45;
    counter = fireRate;
    firingRange = (SCREENHEIGHT/4);
	damage = 5;
    withinfiringRange = false;
    attachShape();

    if (!turretImage.loadFromFile("resources/bgun_normal.png")) {
        printf("Could not load turret");
    }
    loadbase(p);

    turretTexture.loadFromImage(turretImage);
    turretTexture.setSmooth(true);
    turretObject.setTexture(turretTexture);
    turretObject.setScale(.15, .15);
    turretObject.setOrigin(turretTexture.getSize().x/2, turretTexture.getSize().y/2);
    pos = p;
    turretObject.setPosition(p);
}

void BoomerangTurret::fire() {
    if (withinfiringRange)
    {
    BoomerangBullet *newBullet = new BoomerangBullet(turretObject.getPosition(), v);
    bullets.push_back(newBullet);
    counter = 0;
    }
}

void BoomerangTurret::update(float dt) {
    counter += dt;
    if (counter >= fireRate) {
        fire();
    }
    v = getInitBulletVel();
    turretObject.setRotation(atan(v.y/v.x)*180/M_PI);
    if (v.x > 0) {turretObject.rotate(180.f);}

    for (int i = 0; i < bullets.size(); i++) {

        bullets.at(i)->update(dt);
        if(!bullets.at(i)->isAlive)
        {
            bullets.erase(bullets.begin() + i);
        }
    }
}

sf::Vector2f BoomerangTurret::getInitBulletVel() {
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

sf::Vector2f BoomerangTurret::normalize(sf::Vector2f & v) {
    float length = sqrt((v.x * v.x) + (v.y * v.y));
    if (length != 0)
        return sf::Vector2f(v.x / length, v.y / length);
    else
        return v;
}
