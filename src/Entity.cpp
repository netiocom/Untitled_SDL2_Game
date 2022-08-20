#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

Entity::Entity(){}

Entity::Entity(const char* name, Vector2 pos, int width, int height)
{
    this->name = name;
    this->width = width;
    this->height = height;  
    this->rect = SDL_Rect {pos.x, pos.y, width, height}; 
    //this->len++;
}

Entity::Entity(const char* name, Vector2 pos, int width, int height, SDL_Texture* texture)
{
    this->name = name;
    this->width = width;
    this->height = height;   
    this->texture = texture;
    this->rect = SDL_Rect {pos.x, pos.y, width, height};
    //this->len++;
}

Entity::Entity(const char* name, Vector2 pos, int width, int height, std::vector<Uint8>rgba)
{
    this->name = name;
    this->width = width;
    this->height = height;
    this->texture = texture;
    this->rect = SDL_Rect {pos.x, pos.y, width, height};
    this->rgba = rgba;
    //this->len++;
}

std::vector<Uint8> Entity::getRGBA() {
    return this->rgba;
}

// int Entity::getAmountOfEntities() {
//     return this->len; 
// }

void Entity::update() 
{
    this->rect = SDL_Rect {pos.x, pos.y, width, height};
}

