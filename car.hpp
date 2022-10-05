#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Car
{
    public:
    double steerAngle;     //-30 - 30
    double dSteerAngle;
    double maxRaceSteerAngle;
    int steeringWheelPosition;   //-540-540
    double xPos;
    double yPos;
    double speed;     //in m/s
    double maxSpeed;
    double angle;
    double length;
    int gear;
    double idleRpm;
    double currentRpm;
    double maxRpm;
    double gearRatios[5];
    double rearAxleRatio;
    double wheelsDiameter;
    double wheelsCircumference;
    double center_x;
    double center_y;
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sp;

    void accelerate();
    void decelerate();
    void brake();
    void steerLeft();
    void steerRight();
    void steerReturning();
    void setPathToRightTexture();
    void loadTexture();
    void setTexture();
    void getCenterOfTexture();
    void setOrigin(double, double);
    void setScale(double);
    void setPosition(double, double);
    void setRotation(double);

    Car(double idleXPos, double idleYPos, double idleAngle, std::string idleTexturePath)
    {
        steerAngle = 0.0;
        dSteerAngle = 0.5;
        maxRaceSteerAngle = 30.0;
        steeringWheelPosition = 0;
        speed = 0.0;
        maxSpeed = 67.0;
        xPos = idleXPos;
        yPos = idleYPos;
        angle = idleAngle;
        texturePath = idleTexturePath;
        length = 4.3;
        gear = 1;
        idleRpm = 800.0;
        maxRpm = 7800.0;
        gearRatios[0] = 3.683;
        gearRatios[1] = 2.263;
        gearRatios[2] = 1.397;
        gearRatios[3] = 1.00;
        gearRatios[4] = 0.862;
        rearAxleRatio = 3.9;
        wheelsDiameter = 0.68;
        wheelsCircumference = M_PI*wheelsDiameter;
        loadTexture();
        setTexture();
        setScale(0.20);
        getCenterOfTexture();
        setOrigin(center_x, center_y*1.7);
        setPosition(xPos*1.0, yPos*1.0);
        setRotation(0.0);
    }
};
