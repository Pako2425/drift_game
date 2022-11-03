#pragma once

#include "Entity.hpp"


class TrackMap : public Entity
{
private:


public:
    TrackMap();
    ~TrackMap();

    void update(const float& dt);
    void render(sf::RenderTarget* target);
};
