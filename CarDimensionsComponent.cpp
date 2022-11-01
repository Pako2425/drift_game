#include "CarDimensionsComponent.hpp"

CarDimensionsComponent::CarDimensionsComponent()
{
    this->length = 4.3;
    this->wheelsDiameter = 0.68;
    this->wheelsCircumference = M_PI*wheelsDiameter;
}

CarDimensionsComponent::~CarDimensionsComponent()
{

}

const double& CarDimensionsComponent::getLength()
{
    return this->length;
}

const double& CarDimensionsComponent::getWheelsDiameter()
{
    return this->wheelsDiameter;
}

const double& CarDimensionsComponent::getWheelsCircumference()
{
    return this->wheelsCircumference;
}
