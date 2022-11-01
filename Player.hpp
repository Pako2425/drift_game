#pragma once

#include "Entity.hpp"

class Player : Entity
{
private:


public:
    Player();
    ~Player();

    void update(const float& dt);
    void render(sf::RenderTarget target);
};