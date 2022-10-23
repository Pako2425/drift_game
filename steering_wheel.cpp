#include "steering_wheel.hpp"

void SteeringWheel::loadTexture()
{
    SteeringWheel::texture.loadFromFile(SteeringWheel::texturePath);
}

void SteeringWheel::setTexture()
{
    SteeringWheel::sp.setTexture(SteeringWheel::texture);
}

void SteeringWheel::getCenterOfTexture()
{
    SteeringWheel::x_textureCenter = SteeringWheel::texture.getSize().x/2.0;
    SteeringWheel::y_textureCenter = SteeringWheel::texture.getSize().y/2.0;
}

void SteeringWheel::setOrigin(double x, double y)
{
    SteeringWheel::sp.setOrigin(x, y);
}

void SteeringWheel::setScale(double scale)
{
    SteeringWheel::sp.setScale(scale, scale);
}

void SteeringWheel::setPosition(double x, double y)
{
    SteeringWheel::sp.setPosition(x, y);
}

void SteeringWheel::setRotation(double angle)
{
    SteeringWheel::sp.setRotation(angle);
}

void SteeringWheel::readCarData(const Car& anyCar)
{
    SteeringWheel::angleOfSteeringWheel = anyCar.getSteerAngle()*15.0;
}

void SteeringWheel::showData()
{
    SteeringWheel::setRotation(SteeringWheel::angleOfSteeringWheel);
}
