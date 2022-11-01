#include "SteeringComponent.hpp"

SteeringComponent::SteeringComponent()
{
    this->steerAngle = 0.0;
    this->dSteerAngle = 0.5;
    this->maxRaceSteerAngle = 30.0;
}

SteeringComponent::~SteeringComponent()
{

}

const double& SteeringComponent::getSteerAngle()
{
    return this->steerAngle;
}

void SteeringComponent::steerLeft()
{
    if(-this->steerAngle < this->maxRaceSteerAngle)
    {
        this->steerAngle -= this->dSteerAngle;
    }
    else
    {
        this->steerAngle = this->steerAngle;
    }
}

void SteeringComponent::steerRight()
{
    if(this->steerAngle < this->maxRaceSteerAngle)
    {
        this->steerAngle += this->dSteerAngle;
    }
    else
    {
        this->steerAngle = this->steerAngle;
    }
}

void SteeringComponent::steerReturning()
{
    if(this->steerAngle > 0)
    {
        this->steerAngle -= this->dSteerAngle;
    }
    else if(this->steerAngle < 0)
    {
        this->steerAngle += this->dSteerAngle;
    }
    else
    {
        this->steerAngle = this->steerAngle;
    }
}
