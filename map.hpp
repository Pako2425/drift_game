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
    void setOrigin(double, double);
    void setPosition(double, double);
    void setRotation(double);

    Map(std::string idleTexturePath)
    {
        texturePath = idleTexturePath;
        loadTexture();
    }
};
