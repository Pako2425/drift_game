#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Map
{
    public:
    int xMapPos;
    int yMapPos;
    std::string myMapTexturePath;
    sf::Texture myMapTexture;

    void readMapTexture();
    
    Map(std::string texturePath)
    {
        myMapTexturePath = texturePath;
        readMapTexture();
    }
};
