#include "car.hpp"
#include <cmath>

void Car::accelerate()
{
    Car::speed = Car::speed + (Car::maxSpeed - Car::speed)*0.002;
}

void Car::decelerate()
{
    if(Car::speed >= 19.44)
    {
        Car::speed = Car::speed - Car::speed * 0.0011; 
    }
    else if(Car::speed < 19.44 && Car::speed > 0)
    {
        Car::speed = Car::speed - 0.021;
    }
    else
    {
        Car::speed = 0.0;
    }
}

void Car::brake()
{
    if(Car::speed > 0.17)
    {
        Car::speed = Car::speed - 0.17;
    }
    else
    {
        Car::speed = 0.0;
    }
}

void Car::steerRight()
{
    if(Car::steerAngle < Car::maxRaceSteerAngle)
    {
        Car::steerAngle += Car::dSteerAngle;
    }
}

void Car::steerLeft()
{
    if(Car::steerAngle > -Car::maxRaceSteerAngle)
    {
        Car::steerAngle -= Car::dSteerAngle;
    }
}

void Car::steerReturning()
{
    if(Car::steerAngle > 0)
    {
        Car::steerAngle -= Car::dSteerAngle;
    }
    else if(Car::steerAngle < 0)
    {
        Car::steerAngle += Car::dSteerAngle;
    }
    else
    {
        Car::steerAngle = Car::steerAngle;
    }
}

void Car::setTexturePath(std::string texturePath)   //function responsible for choose right texture
{

}

void Car::loadTexture()
{
    Car::texture.loadFromFile(Car::texturePath);
}

void Car::setTexture()
{
    Car::sp.setTexture(Car::texture);
}

void Car::getCenterOfTexture()
{
    Car::center_x = Car::texture.getSize().x/2.0;
    Car::center_y = Car::texture.getSize().y/2.0;
}

void Car::setOrigin(double x, double y)
{
    Car::sp.setOrigin(x, y);
}

void Car::setScale(double scale)
{
    Car::sp.setScale(scale, scale);
}

void Car::setPosition(double x, double y)
{
    Car::sp.setPosition(x, y);
}

void Car::setRotation(double angle)
{
    Car::sp.setRotation(angle);
}
