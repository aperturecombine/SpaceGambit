#include "../../../include/Entities/Bullets/RicochetBullet.h"

RicochetBullet::RicochetBullet(sf::Vector2f p, sf::Vector2f v, PlayState *refe) {
    pos = p;
    vel = v;
    speed = 800;
    isAlive = true;
    radius = 10;
    bounceCount = 0;
    bounceMax = 3;
    ref = refe;
    attachShape();
    loadFont();
}

void RicochetBullet::update(float dt) {
    checkBounds(dt);
    pos += (vel * speed * dt);
}


bool RicochetBullet::checkBounds(float dt){
    sf::Vector2f temp =  pos + (vel * speed * dt);
    if (temp.x < SCREENWIDTH && temp.x > 0)
    {
        if (temp.y < SCREENHEIGHT && temp.y > 0)
        {
            return true;
        }
        else
        {
            lifeCheck();
            vel.y *= -1;
            return false;
        }
    }
    else
    {

        lifeCheck();
        vel.x *= -1;
        return false;
    }

}

void RicochetBullet::lifeCheck(){
    bounceCount ++;
    if (bounceCount>bounceMax)
    {
        isAlive = false;
    }
    else
    {
        isAlive = true;
    }
}

void RicochetBullet::loadFont(){

  if (!bulletImage.loadFromFile("resources/ggunbullet.png")) {
      //printf("Could not load\n");
  }
  bulletTexture.loadFromImage(bulletImage);
  bulletTexture.setSmooth(true);
  bulletObject.setTexture(bulletTexture);
}