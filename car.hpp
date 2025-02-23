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
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sp;

public:    
    //HUD
    int steeringWheelPosition;   //-540-540

    Car(double idleXPos, double idleYPos, double idleAngle, std::string idleTexturePath);
    virtual ~Car();

    void move(const double dx, const double dy, const double dAngle);

    void accelerate();
    void decelerate();
    void brake();
    void steerLeft();
    void steerRight();
    void steerReturning();
    void calculateRPM();
    void calculateGear();

    void setPathToRightTexture();

    const sf::Sprite& getSprite() const;
    const double& getXPos() const;
    const double& getYPos() const;
    const double& getVelocity() const;
    const double& getAngle() const;
    const double& getSteerAngle() const;
    const int& getGear() const;
    const double& getCurrentRpm() const;
    const double& getLength() const;
    void update();
};
