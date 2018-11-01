
#pragma once

#include <SFML/Graphics.hpp>

class bullet {
public:
    bullet() {}
    ~bullet() {}
    
    virtual void move() = 0;
    virtual bool withinBounds() = 0;
};
