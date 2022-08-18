#include "car.hpp"

void Car::steering()
{
    if(Car::steerLeft)
    {
        if(Car::steeringWheelPosition < 540)
        {
            Car::steeringWheelPosition += Car::dsteer;
        }
    }
    else if(Car::steerRight)
    {
        if(Car::steeringWheelPosition > -540)
        {
            Car::steeringWheelPosition -= Car::dsteer;
        }
    }
    else
    {
        if(Car::steeringWheelPosition > 0)
        {
            Car::steeringWheelPosition -= 10;
        }
        else if(Car::steeringWheelPosition < 0)
        {
            Car:;steeringWheelPosition += 10;
        }
        else
        {
            Car::steeringWheelPosition = Car::steeringWheelPosition;
        }
    }
    
}

void Car::workOfEngine()
{
    if(Car::gas)
    {
        if(Car::currentEngineRpm < Car::maxEngineRpm)
        {    
            Car::currentEngineRpm += 50;
        }
        else
        {
            Car::currentEngineRpm = Car::maxEngineRpm;
        }
    }
    else if(Car::brake)
    {
        if(Car::currentEngineRpm > Car::idleEngineRpm)
        {
            Car::currentEngineRpm -= 120;
        }
        else
        {
            Car::currentEngineRpm = Car::idleEngineRpm;
        }
    }
    else
    {
        if(Car::currentEngineRpm > Car::idleEngineRpm)
        {
            Car::currentEngineRpm -= 30;
        }
        else
        {
            Car::currentEngineRpm = Car::idleEngineRpm;
        }
    }
}

void Car::gearShifting()
{
    if(Car::shiftUp)
    {
        if(Car::currentGear < 5)
        {
            Car::currentGear ++;
        }
    }
    else if(Car::shiftDown)
    {
        if(Car::currentGear > 0)
        {
            Car::currentGear --;
        }
    }
    Car::currentEngineRpm = Car::currentGear * Car::wheelsAngleVelocity;
}
