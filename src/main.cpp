#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Utils.hpp"
#include "Vector2.hpp"
#include "Entity.hpp"
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720
#define SCREEN_TITLE "Game v1.0.0"

int main(int argc, char **argv)
{
    Init();
    int x = 288;
    int y = 208;
    
    RenderWindow window(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    // entities & player
    Entity e1 = Entity("PLAYER", Vector2(0, 0), 100, 100, nullptr);
    
    SDL_Rect rect1 = {x, y, 100, 100};
    SDL_Rect rect2 = {50, 50, 100, 80};
    SDL_Rect backgroundRect {0,0, SCREEN_WIDTH, SCREEN_HEIGHT};

    // game bools

    SDL_Event e;
    bool running = true;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    while (running)
    {
        SDL_Delay(10);
        SDL_PollEvent(&e);

        switch (e.type)
        {
            case SDL_QUIT:
                running = false;
                break;
        }

        SDL_bool collision = SDL_HasIntersection(&rect1, &rect2);

        if (keystates[SDL_SCANCODE_LEFT] && !collision) rect1.x -= 2;
        if (keystates[SDL_SCANCODE_RIGHT] && !collision) rect1.x += 2;
        if (keystates[SDL_SCANCODE_UP] && !collision) rect1.y -= 2;
        if (keystates[SDL_SCANCODE_DOWN] && !collision) rect1.y += 2;



        // debug

        if (collision) std::cout << "Collision!\n";

        // render 

        window.clear();
        window.render(&backgroundRect, nullptr, 0,0,0,0);
        window.render(&rect1, nullptr, 242, 242, 242, 255);
        window.render(&rect2, nullptr, 0, 255, 0, 255);
        window.display();
    }

    // cleanup SDL

    SDL_Quit();
    return 0;
}
