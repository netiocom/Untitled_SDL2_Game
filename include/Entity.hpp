#pragma once
#include <SDL2/SDL.h>
#include "Vector2.hpp"

class Entity
{
private:
    const char *name;
    int height, width;
    Vector2 pos;
    SDL_Texture *texture;

public:
    Entity(const char* name, Vector2 pos, int width, int height);
    Entity(const char *name, Vector2 pos, int width, int height, SDL_Texture *texture);
    void move();
};