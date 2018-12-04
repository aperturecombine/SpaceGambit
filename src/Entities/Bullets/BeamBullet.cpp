#include "../../../include/Entities/Bullets/BeamBullet.h"

BeamBullet::BeamBullet(sf::Vector2f p, sf::Vector2f v, PlayState *refe) {
    pos = p;
    vel = v;
    speed = 1000;
    isAlive = true;
    radius = 10;
    ref = refe;
    timePassed = 0;
    attachShape();
    loadFont();
    bulletObject.setRotation(360.f + atan(vel.y/vel.x)*180/M_PI);
    if (vel.x > 0) {bulletObject.rotate(180.f);}
}

void BeamBullet::update(float dt) {
    timePassed +=dt;
    if (timePassed>0.25)
        pos += vel * speed * dt;

}

void BeamBullet::loadFont(){

    if (!bulletImage.loadFromFile("resources/ggun_bullet.png")) {
        printf("Could not load \n");
    }
    bulletTexture.loadFromImage(bulletImage);
    bulletTexture.setSmooth(true);
    bulletObject.setTexture(bulletTexture);
}
