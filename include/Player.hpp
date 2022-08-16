#pragma once
#include "Entity.hpp"
#include "Vector2.hpp"
#include <SDL2/SDL.h>

class Player : public Entity
{
    private:
        const char *name;
        int height, width;
        Vector2 pos;
        SDL_Texture *texture;
        

    public:
        SDL_Rect rect;
        Player(const char* name, Vector2 pos, int width, int height, SDL_Texture* texture);
        bool move(Vector2 movement);
        Vector2 getPos();
        void update();
};