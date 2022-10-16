#include <SDL2/SDL.h>
#include "Tilemap.hpp"
#include "Tile.hpp"
#include <vector> 

Tilemap::Tilemap(){ }
Tilemap::Tilemap(std::vector<std::string> inputMap)
{
    this->inputMap = inputMap;
}

void Tilemap::generateTiles() 
{
    int x = 0, y = 0;
    for (std::string line : this->inputMap)
    {
        for (char _char : line)
        {
            this->map.push_back(Tile(Vector2(x, y)));
            x++;
        }
        y++;
    }
} 

std::vector<Tile> Tilemap::returnTiles() 
{
    return this->map;
}
