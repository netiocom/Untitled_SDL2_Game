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
}

Entity::Entity(const char* name, Vector2 pos, int width, int height, SDL_Texture* texture)
{
    this->name = name;
    this->width = width;
    this->height = height;   
    this->texture = texture;
    this->rect = SDL_Rect {pos.x, pos.y, width, height};
}

Entity::Entity(const char* name, Vector2 pos, int width, int height, std::vector<Uint8>rgba)
{
    this->name = name;
    this->width = width;
    this->height = height;
    this->rect = SDL_Rect {pos.x, pos.y, width, height};
    this->rgba = rgba;
}

std::vector<Uint8> Entity::getRGBA() {
    return this->rgba;
}


void Entity::update() 
{
    this->rect = SDL_Rect {pos.x, pos.y, width, height};
}

void Entity::getInfo()
{
    if (this->name == nullptr) {
        std::cout << "nullptr" << " @" << this->rect.x << ":" << this->rect.y << ":" << this->rect.w << ":" << this->rect.h << '\n';
    } else {
        std::cout << this->name << " @" << this->rect.x << ":" << this->rect.y << ":" << this->rect.w << ":" << this->rect.h << '\n';
    }
}


