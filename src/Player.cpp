#include <SDL2/SDL.h>
#include "Player.hpp"
#include "Vector2.hpp"

Player::Player(const char* name, Vector2 pos, int width, int height, SDL_Texture* texture):Entity()
{
    this->name = name;
    this->width = width;
    this->height = height;
    this->texture = texture;
    this->pos = pos;
    this->rect = SDL_Rect {pos.x, pos.y, width, height};
}

Vector2 Player::getPos()
{
    return this->pos;
}

void Player::update()
{
    this->rect = SDL_Rect {pos.x, pos.y, width, height};
}


bool Player::move(Vector2 movement) 
{
    this->pos += movement;
    return true;   
}