#pragma once

#include "Entity.hpp"

class Player : public Entity
{
private:
    void createComponents();

public:
    Player();
    ~Player();

    void update(const float& dt);
    void render(sf::RenderTarget* target);
};
