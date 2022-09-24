#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "car.hpp"
#include "map.hpp"

class Driving_Physic
{
    public:
    double dt;
    double carSpeed;
    double carLength;
    double carSteerAngle;
    double carAngle;

    double xMapPos;
    double yMapPos;
    double mapAngle;

    double turningRadius;
    double dCarRotationAngle;
    double new_xMapPos;
    double new_yMapPos;
    double new_MapAngle;

    void updateCarDataBase(Car *);
    void updateMapDataBase(Map *);
    void calculateRadiusOfCarTurningCircle();
    void calculateCarRotationAngle();
    void calculateNewMapAngle();
    void calculateNewMapPosition();
    void moveMap(Map *);

    Driving_Physic()
    {
        dt = 1.0/60.0;
        carSpeed = 0.0;
        carSteerAngle = 0.0;
        carAngle = 0.0;
    }
};
