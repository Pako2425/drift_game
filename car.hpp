#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Car
{
    public:
    double steerAngle;     //-30 - 30
    double dSteerAngle;
    double maxRaceSteerAngle;
    double maxDriftSteerAngle;
    int steeringWheelPosition;   //-540-540
    unsigned int xPos;
    unsigned int yPos;
    double speed;     //in m/s
    double maxSpeed;
    unsigned int angle;
    std::string myCarTexturePath;
    sf::Texture myCarTexture;

    void accelerate();
    void decelerate();
    void brake();
    void steerLeft();
    void steerRight();
    void steerReturning();
    void move();
    void readCarTexture();

    Car(unsigned int idleXPos, unsigned int idleYPos, unsigned int idleAngle, std::string texturePath)
    {
        steerAngle = 0.0;
        dSteerAngle = 0.0;
        maxRaceSteerAngle = 30.0;
        maxDriftSteerAngle = 45.0;
        steeringWheelPosition = 0;
        speed = 0.0;
        maxSpeed = 67.0;
        xPos = idleXPos;
        yPos = idleYPos;
        angle = idleAngle;
        myCarTexturePath = texturePath;
        readCarTexture();
    }
};
