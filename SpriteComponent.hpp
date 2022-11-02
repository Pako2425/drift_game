#pragma once
#include <SFML/Graphics.hpp>

class SpriteComponent
{
private:
    sf::Sprite sp;

public:
    SpriteComponent();
    ~SpriteComponent();

    //accessors
    sf::Sprite& getSprite();
};