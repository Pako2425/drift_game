#include "Player.hpp"

Player::Player()
{
    this->createPositionComponent(640.0, 480.0, 0.0);
    this->createVelocityComponent(67.0);
    this->createSteeringComponent();
    this->createSpriteComponent();
    this->createCarDimensionsComponent();
    this->createGearboxComponent();
    this->createEngineComponent();
}

Player::~Player()
{

}

