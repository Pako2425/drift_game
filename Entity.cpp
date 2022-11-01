#include "Entity.hpp"

void Entity::initVariables()
{
    this->positionComponent = NULL;
    this->velocityComponent = NULL;
    this->steeringComponent = NULL;
    this->engineComponent = NULL;
    this->gearboxComponent = NULL;
    this->carDimensionsComponent = NULL;
    this->spriteComponent = NULL;
}

Entity::Entity()
{
    this->initVariables();
}

Entity::~Entity()
{
    
}

void Entity::createPositionComponent(double xPos, double yPos, double angle)
{
    this->positionComponent = new PositionComponent(xPos, yPos, angle);
}

void Entity::createVelocityComponent(double maxSpeed)
{
    this->velocityComponent = new VelocityComponent(maxSpeed);
}

void Entity::createSteeringComponent()
{
    this->steeringComponent = new SteeringComponent();
}

void Entity::createEngineComponent()
{
    this->engineComponent = new EngineComponent();
}

void Entity::createGearboxComponent()
{
    this->gearboxComponent = new GearboxComponent();
}

void Entity::createCarDimensionsComponent()
{
    this->carDimensionsComponent = new CarDimensionsComponent();
}

void Entity::createSpriteComponent()
{
    this->spriteComponent = new SpriteComponent();
}
