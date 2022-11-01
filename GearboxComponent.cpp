#include "GearboxComponent.hpp"

GearboxComponent::GearboxComponent()
{
    this->gear = 0;
    this->gearRatios[0] = 3.683;
    this->gearRatios[1] = 2.263;
    this->gearRatios[2] = 1.397;
    this->gearRatios[3] = 1.00;
    this->gearRatios[4] = 0.862;
    this->rearAxleRatio = 3.9;
}

GearboxComponent::~GearboxComponent()
{

}

const int& GearboxComponent::getGear()
{
    return this->gear;
}

const double& GearboxComponent::getRatio(const int gear)
{
    return this->gearRatios[gear];
}

const double& GearboxComponent::getRearAxleRatio()
{
    return this->rearAxleRatio;
}

void GearboxComponent::setGear(const int gear)
{
    this->gear = gear;
}
