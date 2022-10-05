#include "map.hpp"

void Map::loadTexture()
{
    Map::texture.loadFromFile(Map::texturePath);
}

void Map::setTexture()
{
    Map::sp.setTexture(Map::texture);
}

void Map::setScale(double scale)
{
    Map::sp.setScale(scale, scale);
}

void Map::setPosition(double x, double y)
{
    Map::sp.setPosition(x, y);
}
