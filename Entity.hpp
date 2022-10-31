#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
private:

protected:

public:
    Entity();
    virtual ~Entity();

    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget target) = 0;
};