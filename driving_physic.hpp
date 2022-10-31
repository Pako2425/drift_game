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

    Driving_Physic();
    ~Driving_Physic();

    void calculateRadiusOfCarTurningCircle(const Car& anyCar);
    void calculateCarRotationAngle(const Car& anyCar);
    void calculateNewCarAngle(const Car& anyCar);
    void calculateNewCarPosition(const Car& anyCar);
    
    void updateCar(Car& anyCar);
};
