#include "Tile.hpp"
#include "Vector2.hpp"
#include <iostream>

Tile::Tile(int tileSize, Vector2 pos) {
    this->tileSize = tileSize;
    this->pos = Vector2(this->tileSize, this->tileSize) * pos;
    //std::cout << Vector2(this->tileSize*pos.x, this->tileSize*pos.y) << '\n';
    this->rect = SDL_Rect {pos.x, pos.y, this->tileSize, this->tileSize};
} 

Tile::Tile(Vector2 pos) 
{
    this->pos = Vector2(this->tileSize, this->tileSize) * pos; 
    std::cout << Vector2(this->tileSize*pos.x, this->tileSize*pos.y) << '\n';
    this->rect = SDL_Rect {pos.x, pos.y, this->tileSize, this->tileSize};
}

SDL_Rect Tile::getRect()
{
    return this->rect;
}