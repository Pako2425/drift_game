#include "PositionComponent.hpp"

PositionComponent::PositionComponent(double xPos, double yPos, double angle)
{
    this->xyPos.x = xPos;
    this->xyPos.y = yPos;
    this->angle = angle;
}

PositionComponent::~PositionComponent()
{

}

const sf::Vector2f& PositionComponent::getPosition()
{
    return this->xyPos;
}

const double& PositionComponent::getAngle()
{
    return this->angle;
}

void PositionComponent::move(const double dx, const double dy, const double dAngle)
{
    this->xyPos.x += dx;
    this->xyPos.y += dy;
    this->angle += dAngle;
}
