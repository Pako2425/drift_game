#include "car.hpp"
#include <cmath>

void Car::steer(enum steeringDirections direction, unsigned int dSteering)
{
    switch(direction)
    {
        case LEFT:
            if(Car::steeringWheelPosition < 540)
            {
                Car::steeringWheelPosition += dSteering;
            }
            break;
        case RIGHT:
            if(Car::steeringWheelPosition > -540)
            {
                Car::steeringWheelPosition -= dSteering;
            }
            break;
        default:
            if(Car::steeringWheelPosition > 0)
            {
                Car::steeringWheelPosition -= dSteering;
            }
            else if(Car::steeringWheelPosition < 0)
            {
                Car::steeringWheelPosition += dSteering;
            }
            else
            {
                Car::steeringWheelPosition = Car::steeringWheelPosition;
            }
            break;
    }
}

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

void Car::move()
{
    int dangle = Car::steeringWheelPosition*Car::speed;
    Car::angle = Car::angle + dangle;
    int dxPos = int( round(Car::speed*cos(1.0*Car::angle)) );
    int dyPos = int( round(Car::speed*sin(1.0*Car::angle)) );
    Car::xPos += dxPos;
    Car::yPos += dyPos;
}
