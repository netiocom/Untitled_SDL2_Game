#pragma once
#include "Vector2.hpp"
#include "SDL2/SDL.h"

class Tile
{
    private:
        int tileSize = 32;
        Vector2 pos;
    public:
        SDL_Rect rect;
        Tile(int tileSize, Vector2 pos);
        Tile(Vector2 pos);
        SDL_Rect getRect();
};