#include "RenderWindow.hpp"
#include <SDL2/SDL.h>

RenderWindow::RenderWindow(const char *title, int width, int height) {
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::clear() 
{
    SDL_RenderClear(this->renderer); 
}

void RenderWindow::render(SDL_Rect *rect, SDL_Texture *tex, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    
    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
    SDL_RenderFillRect(this->renderer, rect);
}

void RenderWindow::display() 
{
    SDL_RenderPresent(this->renderer); 
}

RenderWindow::~RenderWindow() 
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}
