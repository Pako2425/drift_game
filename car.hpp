#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Car
{
    public:
    double steerAngle;     //-30 - 30
    double dSteerAngle;
    double maxRaceSteerAngle;
    int steeringWheelPosition;   //-540-540
    unsigned int xPos;
    unsigned int yPos;
    double speed;     //in m/s
    double maxSpeed;
    unsigned int angle;
    double length;
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
    void setTexturePath(std::string);
    void loadTexture();
    void setTexture();
    void getCenterOfTexture();
    void setOrigin(double, double);
    void setScale(double);
    void setPosition(double, double);
    void setRotation(double);

    Car(unsigned int idleXPos, unsigned int idleYPos, unsigned int idleAngle, std::string idleTexturePath)
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
        loadTexture();
        //getCenterOfTexture();
    }
};
