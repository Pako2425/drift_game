#include "map.hpp"

void Map::readMapTexture()
{
    Map::myMapTexture.loadFromFile(Map::myMapTexturePath);
}
