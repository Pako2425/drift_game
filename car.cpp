#include "car.hpp"

void Car::updateStateOfSteeringSystem()
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

void Car::driveSystem()
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

void Car::shiftGear()
{
    if(Car::shiftUp and !Car::prevShift)
    {
        if(Car::currentGear < 5)
        {
            Car::currentGear ++;
            Car::currentEngineRpm = static_cast<int>(Car::wheelsAngleVelocity * Car::gearRatio[Car::currentGear] * Car::finalDrive);
        }
    }
    else if(Car::shiftDown and !Car::prevShift)
    {
        if(Car::currentGear > 0)
        {
            Car::currentGear --;
            Car::currentEngineRpm = static_cast<int>(Car::wheelsAngleVelocity * Car::gearRatio[Car::currentGear] * Car::finalDrive);
        }
    }
    Car::prevShift = Car::shiftUp or Car::shiftDown;
}
