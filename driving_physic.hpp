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

    void calculateRadiusOfCarTurningCircle(Car *);
    void calculateCarRotationAngle(Car *);
    void calculateNewCarAngle(Car *);
    void calculateNewCarPosition(Car *);

    Driving_Physic()
    {
        dt = 1.0/60.0;
    }
};
