#include <SDL2/SDL.h>
#include "Tilemap.hpp"
#include "Tile.hpp"
#include <vector> 

Tilemap::Tilemap(){ }
Tilemap::Tilemap(std::vector<std::string> inputMap)
{
    this->inputMap = inputMap;
    this->size = 32;
}

Tilemap::Tilemap(std::vector<std::string> inputMap, int size)
{
    this->inputMap = inputMap;
    this->size = size;
}

void Tilemap::generateTiles() 
{
    int x = 0, y = 0;
    for (std::string line : this->inputMap)
    {
        for (char const& c : line)
        {
            this->map.push_back(Tile(this->size, Vector2(x, y)));
            x++;
        }
        y++;
    }
} 

std::vector<Tile> Tilemap::returnTiles() 
{
    return this->map;
}
