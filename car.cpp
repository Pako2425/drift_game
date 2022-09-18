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

void Car::move()
{
    int dangle = Car::steerAngle*Car::speed;
    Car::angle = Car::angle + dangle;
    int dxPos = int( round(Car::speed*cos(1.0*Car::angle)) );
    int dyPos = int( round(Car::speed*sin(1.0*Car::angle)) );
    Car::xPos += dxPos;
    Car::yPos += dyPos;
}

void Car::readCarTexture()
{
    Car::myCarTexture.loadFromFile(Car::myCarTexturePath);
}
