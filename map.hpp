#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Map
{
    public:
    double xPos;
    double yPos;
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sp;

    void setTexturePath();
    void loadTexture();
    void setTexture();
    void setScale(double);
    void setPosition(double, double);

    Map(double idleXPos, double idleYPos, std::string idleTexturePath)
    {
        xPos = idleXPos;
        yPos = idleYPos;
        texturePath = idleTexturePath;
        loadTexture();
        setTexture();
        setScale(1.2);
        setPosition(xPos, yPos);
    }
};
