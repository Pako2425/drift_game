#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent(double maxVelocity)
{
    this->maxVelocity = maxVelocity;
}

VelocityComponent::~VelocityComponent()
{

}

const double& VelocityComponent::getVelocity()
{
    return this->velocity;
}

const double& VelocityComponent::getMaxSpeed()
{
    return this->maxVelocity;
}

void VelocityComponent::accelerate()
{
    this->velocity += (this->maxVelocity - this->velocity)*0.002;
}

void VelocityComponent::decelerate()
{
    if(this->velocity >= 19.44)
    {
        this->velocity -= this->velocity*0.0011; 
    }
    else if(this->velocity < 19.44 && this->velocity > 0)
    {
        this->velocity = this->velocity - 0.021;
    }
    else
    {
        this->velocity = 0.0;
    }
}

void VelocityComponent::brake()
{
    if(this->velocity > 0.17)
    {
        this->velocity = this->velocity - 0.17;
    }
    else
    {
        this->velocity = 0.0;
    }
}
