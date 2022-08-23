#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.hpp"
#include "Entity.hpp"
#include <vector>

void Init();
SDL_Point *getSize();
SDL_bool vecAnyItemTrue(std::vector<SDL_bool> vec);
