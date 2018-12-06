#include "../../../include/Entities/Bullets/GuidedBullet.h"

GuidedBullet::GuidedBullet(sf::Vector2f p, sf::Vector2f v, PlayState *refe) {
    pos = p;
    vel = v;
    speed = 300;
    isAlive = true;
    radius = 10;
    ref = refe;
    attachShape();
    loadFont();
}

void GuidedBullet::update(float dt) {
    sf::Vector2f ship1_init = (ref->ship1.pos - pos);
    float ship1_dist = pow((ship1_init.x*ship1_init.x + ship1_init.y*ship1_init.y),0.5);

    if(ref->twoPlayerMode)
    {
        sf::Vector2f ship2_init = (ref->ship2.pos - pos);
        
        float ship2_dist = pow((ship2_init.x*ship2_init.x + ship2_init.y*ship2_init.y),0.5);

        if (ship1_dist < ship2_dist)
        {
            if (ship1_dist != 0)
                vel = sf::Vector2f(ship1_init.x / ship1_dist, ship1_init.y / ship1_dist);
            else
                vel = ship1_init;
        }
            else
            {
                if (ship2_dist != 0)
                    vel = sf::Vector2f(ship2_init.x / ship2_dist, ship2_init.y / ship2_dist);
                else
                    vel = ship2_init;
            }
    }
    else
    {
        if (ship1_dist > 0)
            vel = sf::Vector2f(ship1_init.x / ship1_dist, ship1_init.y / ship1_dist);
    }

    bulletObject.setRotation(360.f + atan(vel.y/vel.x)*180/M_PI);
    if (vel.x > 0) {bulletObject.rotate(180.f);}
    pos += vel * speed * dt;

}

void GuidedBullet::loadFont(){

    if (!bulletImage.loadFromFile("resources/missle_frame2.png")) {
        //printf("Could not load\n");
    }

    bulletTexture.loadFromImage(bulletImage);
    bulletTexture.setSmooth(true);
    bulletObject.setTexture(bulletTexture);
}
