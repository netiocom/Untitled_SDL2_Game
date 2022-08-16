#include "Utils.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

void Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        std::cout << "SDL_INIT_EVERYTHING failed, error: " << SDL_GetError() << '\n';
    }
    //if (IMG_Init(IMG_INIT_PNG) != 0) std::cout << "IMG_INIT_PNG failed, error: " << IMG_GetError() << '\n';
    //if (IMG_Init(IMG_INIT_JPG) != 0) std::cout << "IMG_INIT_JPG failed, error: " << IMG_GetError() << '\n';
}

SDL_Point getSize(SDL_Texture* texture)
{
    SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
	return size;
}