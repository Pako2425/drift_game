#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "car.hpp"
#include "map.hpp"

class Driving_Physic
{
    public:
    double dt;
    double turningRadius;
    double dCarRotationAngle;
    double newCarAngle;
    double newCarXPos;
    double newCarYPos;

    void calculateRadiusOfCarTurningCircle(Car *);
    void calculateCarRotationAngle(Car *);
    void calculateNewCarAngle(Car *);
    void calculateNewCarPosition(Car *);
    void calculateRPM(Car *);
    void calculateGear(Car *);
    void moveCar(Car *);

    Driving_Physic()
    {
        dt = 1.0/60.0;
    }
};
