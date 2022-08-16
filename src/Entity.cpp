#include "Entity.hpp"

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

void Entity::update() 
{
    this->rect = SDL_Rect {pos.x, pos.y, width, height};
}

