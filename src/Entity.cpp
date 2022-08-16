#include "Entity.hpp"


Entity::Entity(const char* name, Vector2 pos, int width, int height)
{
    this->name = name;
    this->width = width;
    this->height = height;   
}

Entity::Entity(const char* name, Vector2 pos, int width, int height, SDL_Texture* texture)
{
    this->name = name;
    this->width = width;
    this->height = height;   
    this->texture = texture;
}