
#include "../../../include/Entities/Turrets/GuidedTurret.h"
#include <math.h>

GuidedTurret::GuidedTurret(sf::Vector2f p) {
    pos = p;
    fireRate = 5;
    counter = fireRate;
    firingRange = (SCREENHEIGHT/4);
	damage = 5;
    withinfiringRange = false;
    attachShape();
    loadbase(p);
    if (!turretbase.loadFromFile("resources/base_allgun.png")) {
        printf("Could not load turret\n");
    }
    turretTexturebase.loadFromImage(turretbase);
    turretTexturebase.setSmooth(true);
    turretObjectbase.setTexture(turretTexture);
    turretObjectbase.setScale(.3, .3);
    turretObjectbase.setOrigin((turretObjectbase.getTexture()->getSize().x) / 2,
                           (turretObject.getTexture()->getSize().y) / 2);
    turretObjectbase.setPosition(p);
        printf("Where is seg \n");
    if (!turretImage.loadFromFile("resources/missile_normal.png")) {
        printf("Could not load turret\n");
    }

    turretTexture.loadFromImage(turretImage);
    turretTexture.setSmooth(true);
    turretObject.setTexture(turretTexture);
    turretObject.setScale(.3, .3);
    turretObject.setOrigin(turretTexture.getSize().x/2, turretTexture.getSize().y/2);
    turretObject.setPosition(p);
}

void GuidedTurret::fire() {
    if (withinfiringRange)
    {
    GuidedBullet *newBullet = new GuidedBullet(pos, v, ref);
    bullets.push_back(newBullet);
    counter = 0;
    }
}

void GuidedTurret::explode(){
    bullets.pop_back();
}

void GuidedTurret::update(float dt) {
    counter += dt;
    if (counter >= fireRate) {
        if(!bullets.empty()) {explode();}
        fire();
    }
    v = getInitBulletVel();
    turretObject.setRotation(atan(v.y/v.x)*180/M_PI);
    if (v.x > 0) {turretObject.rotate(180.f);}

    for (int i = 0; i < bullets.size(); i++) {
        bullets.at(i)->update(dt);
    }
}

sf::Vector2f GuidedTurret::getInitBulletVel() {
    sf::Vector2f ship1_init = (ref->ship1.pos - pos);
    float ship1_dist = pow((ship1_init.x*ship1_init.x + ship1_init.y*ship1_init.y),0.5);

    // std::cout << "Single PLayer Check getInit: " << std::endl;
    if(ref->twoPlayerMode)
    {
        sf::Vector2f ship2_init = (ref->ship2.pos - pos);
        float ship2_dist = pow((ship2_init.x*ship2_init.x + ship2_init.y*ship2_init.y),0.5);

        if (ship1_dist < ship2_dist)
        {
            if (ship1_dist < firingRange)
            {
                withinfiringRange=true;
            }
            else
            {
                withinfiringRange=false;
            }
            return normalize(ship1_init);
        }
        else
        {
            if (ship2_dist < firingRange)
            {
                withinfiringRange=true;
            }
            else
            {
                withinfiringRange=false;
            }
            return normalize(ship2_init);
        }
    }
    else
    {

        if (ship1_dist < firingRange)
        {
            withinfiringRange=true;

        }
        else
        {
            withinfiringRange=false;
        }
        return normalize(ship1_init);
    }
}

sf::Vector2f GuidedTurret::normalize(sf::Vector2f & v) {
    float length = sqrt((v.x * v.x) + (v.y * v.y));
    if (length != 0)
        return sf::Vector2f(v.x / length, v.y / length);
    else
        return v;
}
