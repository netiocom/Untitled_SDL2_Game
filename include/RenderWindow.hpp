#pragma once
#include <SDL2/SDL.h>
#include "Entity.hpp"
#include "Player.hpp"
#include <vector>

class RenderWindow {
    public:
        RenderWindow(const char *title, int width, int height);
        void clear();
        void render(SDL_Rect *rect, std::vector<Uint8> color);
        void render(Entity* entity);
        void render(Player player);
        SDL_Texture* loadTexture(const char* file);
        void display();
        ~RenderWindow();

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
};
