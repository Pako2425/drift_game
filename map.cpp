#include "map.hpp"

Map::Map(double idleXPos, double idleYPos, std::string idleTexturePath)
{
    xPos = idleXPos;
    yPos = idleYPos;
    texturePath = idleTexturePath;

    this->texture.loadFromFile(this->texturePath);
    this->sp.setTexture(this->texture);
    this->sp.setScale(1.2, 1.2);
    this->sp.setPosition(this->xPos, this->yPos);
}

Map::~Map()
{

}

const double& Map::getXPos() const
{
    return this->xPos;
}

const double& Map::getYPos() const
{
    return this->yPos;
}

const sf::Sprite& Map::getSprite() const
{
    return this->sp;
}