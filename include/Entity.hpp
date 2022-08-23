#pragma once 
#include <SDL2/SDL.h>
#include "Vector2.hpp"
#include <vector>
#include <iostream>


class Entity
{
    private:
        int height, width;
        Vector2 pos;
        SDL_Texture *texture;
        std::vector<Uint8>rgba;

        

    public:
        // static int len = 0;
        const char* name;
        SDL_Rect rect;
        Entity();
        Entity(const char* name, Vector2 pos, int width, int height);
        Entity(const char* name, Vector2 pos, int width, int height, std::vector<Uint8>rgba);
        Entity(const char* name, Vector2 pos, int width, int height, SDL_Texture *texture);
        std::vector<Uint8> getRGBA();
        // int getAmountOfEntities();
        void update();
        void getInfo(); 
};