#include "../../../include/Entities/Bullets/GlueBullet.h"

GlueBullet::GlueBullet(sf::Vector2f p, sf::Vector2f v) {
    pos = p;
    vel = v;
    speed = 1000;
    isAlive = true;
    radius = 10;
    attachShape();
    loadFont();
}

void GlueBullet::update(float dt) {
    pos += vel * speed * dt;
    bulletObject.setRotation(360.f + atan(vel.y/vel.x)*180/M_PI);
    if (vel.x > 0) {bulletObject.rotate(180.f);}
}

void GlueBullet::checkBounds(float dt){
    sf::Vector2f temp =  pos + (vel * speed * dt);
    if (temp.x > SCREENWIDTH || temp.x < 0)
    {
        isAlive = false;
    }
    if (temp.y > SCREENHEIGHT || temp.y < 0)
    {
        isAlive = false;
    }
}

void GlueBullet::loadFont(){

    if (!bulletImage.loadFromFile("../resources/ggun_bullet.png")) {
        //  printf("Could not load\n ");
    }
    bulletTexture.loadFromImage(bulletImage);
    bulletTexture.setSmooth(true);
    bulletObject.setTexture(bulletTexture);
}
