#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Map
{
    public:
    int xMapPos;
    int yMapPos;
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sp;

    void loadTexture();
    void setOrigin(double, double);

    
    Map(std::string idleTexturePath)
    {
        texturePath = idleTexturePath;
        loadTexture();
    }
};
