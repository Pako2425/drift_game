#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class SteeringWheel
{
    public:
    double xPos;
    double yPos;
    double x_textureCenter;
    double y_textureCenter;
    double angleOfSteeringWheel;
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sp;

    void loadTexture();
    void setTexture();
    void getCenterOfTexture();
    void setOrigin(double, double);
    void setScale(double);
    void setPosition(double, double);
    void setRotation(double);

    SteeringWheel(double idleXPos, double idleYPos, std::string idleTexturePath)
    {
        texturePath = idleTexturePath;
        xPos = idleXPos;
        yPos = idleYPos;
        angleOfSteeringWheel = 0.0;
        loadTexture();
        setTexture();
        setScale(0.80);
        getCenterOfTexture();
        setOrigin(x_textureCenter, y_textureCenter);
        setPosition(xPos*1.0, yPos*1.0);
        setRotation(0.0);
    }
};
