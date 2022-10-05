#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Map
{
    public:
    double xPos;
    double yPos;
    double angle;
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sp;

    void setTexturePath();
    void loadTexture();
    void setTexture();
    void setScale(double);
    void setPosition(double, double);

    Map(double idleXPos, double idleYPos, double idleAngle, std::string idleTexturePath)
    {
        xPos = idleXPos;
        yPos = idleYPos;
        angle = idleAngle;
        texturePath = idleTexturePath;
        loadTexture();
        setTexture();
        setScale(1.2);
        setPosition(640.0, 480.0);
    }
};
