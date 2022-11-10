#pragma once 
#include <SDL2/SDL.h>
#include <vector>
#include "Tile.hpp"
#include <string>
class Tilemap
{
    private:
        std::vector<std::string> inputMap;
        std::vector<Tile> map;
        int size; 
    public:
        Tilemap(); 
        Tilemap(std::vector<std::string> inputMap); 
        Tilemap(std::vector<std::string> inputMap, int size); 
        std::vector<Tile> returnTiles(); // returns multiple objects of the 'Tile' class
        void generateTiles();
};