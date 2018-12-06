
#include "../../../include/Entities/Powerups/shield.h"
#include "../../../include/Globals.h"

shield::shield(sf::Vector2f p) {
	type = 3;
    pos = p;
	radius = 5;
  if (!pTexture.loadFromFile("../resources/shield.png")){
    printf("Shield Sprite Not Loaded");
  }
  pSprite.setTexture(pTexture);
  auto size = pSprite.getTexture()->getSize();
  pSprite.setScale(float(SCREENWIDTH)/(50*size.x), float(SCREENHEIGHT)/(50*size.y));
  pSprite.setPosition(p);

}
 
