#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet() {}
    ~Bullet() {}
    
    virtual void update(float deltams) = 0;

	sf::Vector2f pos;
	sf::Vector2f vel;

	int radius;
};
