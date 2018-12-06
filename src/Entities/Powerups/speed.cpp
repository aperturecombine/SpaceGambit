
#include "../../../include/Entities/Powerups/speed.h"
#include "../../../include/Globals.h"

speed::speed(sf::Vector2f p) {
	pos = p;
	radius = 5;
  if (!pTexture.loadFromFile("../resources/speed.png")){
    printf("Health Sprite Not Loaded");
  }
  pSprite.setTexture(pTexture);
  auto size = pSprite.getTexture()->getSize();
  pSprite.setScale(float(SCREENWIDTH)/(50*size.x), float(SCREENHEIGHT)/(50*size.y));
  pSprite.setPosition(p);

}
