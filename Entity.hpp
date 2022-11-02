#pragma once
#include <SFML/Graphics.hpp>
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"
#include "SteeringComponent.hpp"
#include "EngineComponent.hpp"
#include "GearboxComponent.hpp"
#include "CarDimensionsComponent.hpp"
#include "SpriteComponent.hpp"


class Entity
{
private:
    void initVariables();

protected:
    PositionComponent* positionComponent;
    VelocityComponent* velocityComponent;
    SteeringComponent* steeringComponent;
    EngineComponent* engineComponent;
    GearboxComponent* gearboxComponent;
    CarDimensionsComponent* carDimensionsComponent;
    SpriteComponent* spriteComponent;

public:
    Entity();
    virtual ~Entity();

    void createPositionComponent(double xPos, double yPos, double angle);
    void createVelocityComponent(double maxSpeed);
    void createSteeringComponent();
    void createEngineComponent();
    void createGearboxComponent();
    void createCarDimensionsComponent();
    void createSpriteComponent();

    //accessors
    virtual PositionComponent* getPositionComponent();
    virtual VelocityComponent* getVelocityComponent();
    virtual SteeringComponent* getSteeringComponent();
    virtual EngineComponent* getEngineComponent();
    virtual GearboxComponent* getGearboxComponent();
    virtual CarDimensionsComponent* getCarDimensionsComponent();
    virtual SpriteComponent* getSpriteComponent();

    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target) = 0;
};
