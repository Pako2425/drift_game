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

void Car::shiftGear(enum shifterAction action)
{
    switch(action)
    {
        case SHIFT_UP:
            if(!Car::prevShift)
            {
                if(Car::currentGear < 5)
                {
                    Car::currentGear ++;
                }
                Car::prevShift = true;
            }
            
            break;
        case SHIFT_DOWN:
            if(!Car::prevShift)
            {
                if(Car::currentGear > 0)
                {
                    Car::currentGear --;
                }
                Car::prevShift = true;
            }
            break;
        default:
            Car::currentGear = Car::currentGear;
            Car::prevShift = false;
    }
}

void Car::calculateWheelsAngleVelocity()
{
    Car::wheelsAngleVelocity = (static_cast<float>(Car::currentEngineRpm) / (Car::gearRatio[Car::currentGear] * Car::finalDrive));
}
