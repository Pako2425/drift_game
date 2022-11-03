#include "Player.hpp"

void Player::createComponents()
{
    this->createPositionComponent(640.0, 480.0, 0.0);
    this->createVelocityComponent(67.0);
    this->createSteeringComponent();
    this->createSpriteComponent();
    this->createCarDimensionsComponent();
    this->createGearboxComponent();
    this->createEngineComponent();
}

Player::Player()
{
    this->createComponents();
}

Player::~Player()
{

}

void Player::update(const float& dt)
{
    
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->spriteComponent->getSprite());
}
