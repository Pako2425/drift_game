#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class VelocityComponent
{
private:
    double velocity;     //in m/s
    double maxVelocity;
    void initVariables();
public:
    VelocityComponent(double maxSpeed);
    ~VelocityComponent();
    //accessors
    const double& getVelocity();
    const double& getMaxSpeed();
    //functions
    void accelerate();
    void decelerate();
    void brake();
    //update
};
