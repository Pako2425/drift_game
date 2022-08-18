#include "car.hpp"

void Car::steering(enum steeringDirections direction)
{
    switch(direction)
    {
        case LEFT:
            if(Car::steeringWheelPosition < 540)
            {
                Car::steeringWheelPosition += Car::dsteer;
            }
            break;
        case RIGHT:
            if(Car::steeringWheelPosition > -540)
            {
                Car::steeringWheelPosition -= Car::dsteer;
            }
            break;
        default:
            if(Car::steeringWheelPosition > 0)
            {
                Car::steeringWheelPosition -= 10;
            }
            else if(Car::steeringWheelPosition < 0)
            {
                Car::steeringWheelPosition += 10;
            }
            else
            {
                Car::steeringWheelPosition = Car::steeringWheelPosition;
            }
            break;
    }
}

void Car::pressPedal(enum carPedals pressedPedal)
{
    switch(pressedPedal)
    {
        case GAS:
            if(Car::currentEngineRpm < Car::maxEngineRpm)
            {    
                Car::currentEngineRpm += 50;
            }
            else
            {
                Car::currentEngineRpm = Car::maxEngineRpm;
            }
            break;
        case BRAKE:
            if(Car::currentEngineRpm > Car::idleEngineRpm)
            {
                Car::currentEngineRpm -= 120;
            }
            else
            {
                Car::currentEngineRpm = Car::idleEngineRpm;
            }
            break;
        default:
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

void Car::updateStateOfGerbox()
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


