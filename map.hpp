#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Map
{
private:
    public:
    double xPos;
    double yPos;
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sp;

public:
    Map(double idleXPos, double idleYPos, std::string idleTexturePath);
    ~Map();
};
