#include "car.hpp"

void Car::steering()
{
    if(Car::steeringWheelPosition > 0 and Car::steeringWheelPosition < 540)
    {
        if(Car::steerLeft)
        {
            steeringWheelPosition += 10;
        }
        else
        {
            steeringWheelPosition -= 10;
        }
    }
    else if(Car::steeringWheelPosition < 0 and Car::steeringWheelPosition > -540)
    {
        if(Car::steerRight)
        {
            steeringWheelPosition -= 10;
        }
        else
        {
            steeringWheelPosition += 10;
        }
    }
    else
    {
        steeringWheelPosition = steeringWheelPosition;
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

void Car::shiftUp()
{
    if(Car::currentGear < 5)
    {
        Car::currentGear ++;
    }
}

void Car::shiftDown()
{
    if(Car::currentGear > 0)
    {
        Car::currentGear --;
    }
}