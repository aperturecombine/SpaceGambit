
#include "../../../include/Entities/Powerups/health.h"
#include "../../../include/Globals.h"

health::health(sf::Vector2f p) {
	pos = p;
	radius = 5;
  if (!pTexture.loadFromFile("resources/health.png")){
    printf("Health Sprite Not Loaded");
  }
  pSprite.setTexture(pTexture);
  auto size = pSprite.getTexture()->getSize();
  pSprite.setScale(float(SCREENWIDTH)/(50*size.x), float(SCREENHEIGHT)/(50*size.y));
  pSprite.setPosition(p);

}
