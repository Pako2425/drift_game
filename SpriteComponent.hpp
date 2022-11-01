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
    const sf::Sprite getSprite();

    //functions
    void setTexture(const sf::Texture& texture);
    void setScale(const double scale);
    void setOrigin(const double xOrigin, const double yOrigin);
    void setPosition(const double xPos, const double yPos);
    void setRotation(const double angle);

};