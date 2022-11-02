#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{
    //this->sp.setTexture(texture);
    //this->sp.setScale(0.20, 0.20);
    //this->sp.setOrigin(texture.getSize().x*0.5, texture.getSize().y*0.85);
    //this->sp.setPosition(this->xPos, this->yPos);
    //this->sp.setRotation(this->angle);
}

SpriteComponent::~SpriteComponent()
{

}

sf::Sprite& SpriteComponent::getSprite()
{
    return this->sp;
}
