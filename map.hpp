#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Map
{
private:
    double xPos;
    double yPos;
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sp;

public:
    Map(double idleXPos, double idleYPos, std::string idleTexturePath);
    ~Map();

    const double& getXPos() const;
    const double& getYPos() const;
    const sf::Sprite& getSprite() const;
};
