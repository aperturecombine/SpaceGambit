#include "../../../include/Entities/Bullets/GuidedBullet.h"

GuidedBullet::GuidedBullet(sf::Vector2f p, sf::Vector2f v, PlayState *refe) {
    pos = p;
    vel = v;
    speed = 300;
    isAlive = true;
    radius = 5;
    ref = refe;
    attachShape();
    loadFont();
}

void GuidedBullet::update(float dt) {
    sf::Vector2f ship1_init = (ref->ship1.pos - pos);
    sf::Vector2f ship2_init = (ref->ship2.pos - pos);
    float ship1_dist = pow((ship1_init.x*ship1_init.x + ship1_init.y*ship1_init.y),0.5);
    float ship2_dist = pow((ship2_init.x*ship2_init.x + ship2_init.y*ship2_init.y),0.5);

    if (ship1_dist < ship2_dist)

        if (ship1_dist != 0) vel = sf::Vector2f(ship1_init.x / ship1_dist, ship1_init.y / ship1_dist);
        else vel = ship1_init;
    else
        if (ship2_dist != 0) vel = sf::Vector2f(ship2_init.x / ship2_dist, ship2_init.y / ship2_dist);
        else vel = ship2_init;

    pos += vel * speed * dt;

}

void GuidedBullet::loadFont(){
  system("dir");
  if (!bulletImage.loadFromFile("resources/ggunbullet.png")) {
      //printf("Could not load\n");
  }

  bulletTexture.loadFromImage(bulletImage);
  bulletTexture.setSmooth(true);
  bulletObject.setTexture(bulletTexture);
}
