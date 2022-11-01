#pragma once
#include <cmath>

class CarDimensionsComponent
{
private:
    double length;
    double wheelsDiameter;
    double wheelsCircumference;

public:
    CarDimensionsComponent();
    ~CarDimensionsComponent();

    //accessors
    const double& getLength();
    const double& getWheelsDiameter();
    const double& getWheelsCircumference();
};