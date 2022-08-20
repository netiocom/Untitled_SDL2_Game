#pragma once 
#include <vector>
#include "Tile.hpp"
#include <SDL2/SDL.h>

class Tilemap
{
    private:
    public:
        Tilemap(); 
        std::vector<Tile> returnTiles(); // returns multiple objects of the 'Tile' class
};