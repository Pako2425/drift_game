#include "TrackMap.hpp"

TrackMap::TrackMap()
{
    this->createPositionComponent(0.0, 0.0, 0.0);
    this->createSpriteComponent();
}

TrackMap::~TrackMap()
{

}

void TrackMap::update(const float& dt)
{
    
}

void TrackMap::render(sf::RenderTarget* target)
{
    target->draw(this->spriteComponent->getSprite());
}
