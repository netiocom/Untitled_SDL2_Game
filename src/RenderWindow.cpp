#include "RenderWindow.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Tile.hpp"
#include "Tilemap.hpp"

RenderWindow::RenderWindow(const char *title, int width, int height) {
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::clear() 
{
    SDL_RenderClear(this->renderer); 
}
                    // debug here
void RenderWindow::render(SDL_Rect *rect, std::vector<Uint8> color) {
    //std::cout << color[0] << ", " << color[1] << ", " << color[2] << ", " << color[3] << '\n';
    SDL_SetRenderDrawColor(this->renderer, color[0], color[1], color[2], color[3]);
    SDL_RenderFillRect(this->renderer, rect);
}

void RenderWindow::render(std::vector<Tile> tilemap) {
    for (Tile tile : tilemap)
    {
        
        SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(this->renderer, &tile.rect);
    }
}

// void RenderWindow::render(SDL_Rect rect)
// {

// }

void RenderWindow::display() 
{
    SDL_RenderPresent(this->renderer); 
}

SDL_Texture* RenderWindow::loadTexture(const char* file)
{
    auto surf = IMG_Load(file);
    if (!surf) std::cout << "Error loading texture (" << file << "): " << SDL_GetError() << '\n';
    SDL_Texture*  texture = SDL_CreateTextureFromSurface(this->renderer, surf);
    if (!texture) std::cout << "Error loading texture (" << file << "): " << SDL_GetError() << '\n';
    SDL_FreeSurface(surf);
    return texture;
}

void RenderWindow::render(Player player)
{
    SDL_RenderCopy(this->renderer, player.getTex(), nullptr, &player.rect);    
}

RenderWindow::~RenderWindow() 
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}
