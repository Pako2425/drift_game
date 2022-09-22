#include "map.hpp"

void Map::loadTexture()
{
    Map::texture.loadFromFile(Map::texturePath);
}

void Map::setOrigin(double x, double y)
{
    Map::sp.setOrigin(x, y);
}
