#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(sf::Texture& texture)
{
    this->sp.setTexture(this->texture);
    this->sp.setScale(0.20, 0.20);
    this->sp.setOrigin(this->texture.getSize().x*0.5, this->texture.getSize().y*0.85);
    this->sp.setPosition(this->xPos, this->yPos);
    this->sp.setRotation(this->angle);
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::setTexture(const sf::Texture& texture)
{
    this->sp.setTexture(texture);
}

void SpriteComponent::setScale(const double scale)
{
    this->sp.setScale(scale, scale);
}

void SpriteComponent::setOrigin(const double xOrigin, const double yOrigin)
{
    sf::Vector2f xyOrigin(xOrigin, yOrigin);
    this->sp.setOrigin(xyOrigin);
}

void SpriteComponent::setPosition(const double xPos, const double yPos)
{
    sf::Vector2f xyPos(xPos, yPos);
    this->sp.setPosition(xyPos);
}

void SpriteComponent::setRotation(const double angle)
{
    this->sp.setRotation(angle);
}
