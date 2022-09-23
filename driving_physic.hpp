#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "car.hpp"
#include "map.hpp"

class Driving_Physic
{
    public:
    double dt;

    double calculateRadiusOfTurningCircle(double, double);
    double calculateCarRotationAngle(double, double, double);
    double calculateNewMapAngle(double, double, double);
    double calculateNewMapPosition(double, double, double, double);
    void moveMap(Car *, Map *);

    Driving_Physic()
    {
        dt = 1.0/60.0;
    }
};
