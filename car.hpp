#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Car
{
private:
    //position
    double xPos;
    double yPos;
    double angle;
    
    //velocity
    double velocity;     //in m/s
    double maxVelocity;
    
    //steering
    double steerAngle;     //-30 - 30
    double dSteerAngle;
    double maxRaceSteerAngle;
    
    //engine
    double idleRpm;
    double currentRpm;
    double maxRpm;

    //gearbox
    int gear;
    double gearRatios[5];
    double rearAxleRatio;

    //other_components
    double length;
    double wheelsDiameter;
    double wheelsCircumference;
    
    //Sprite components
    double center_x;
    double center_y;
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sp;

public:
    //HUD
    int steeringWheelPosition;   //-540-540

    Car(double idleXPos, double idleYPos, double idleAngle, std::string idleTexturePath);
    virtual ~Car();

    void move(const double dx, const double dy, const double dAngle);
    void update();

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
    void setOrigin();
    void setScale(double);
    void setPosition();
    void setRotation();
};
