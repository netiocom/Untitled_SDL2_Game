#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "RenderWindow.hpp"
#include "Utils.hpp"
#include "Vector2.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720
#define SCREEN_TITLE "Game v1.0.0"

int main(int argc, char **argv)
{
    Init();

    RenderWindow window(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);


    // textures
    SDL_Texture* playerTex = window.loadTexture("../../assets/Player/microsoft.png");


    //Player player = Player("PLAYER", Vector2(250, 250), 100, 100, nullptr);
    Player player = Player("PLAYER", Vector2(250, 250), 100, 100, playerTex);


    // entity vectors

    std::vector<Entity> ENTITIES  = {
        Entity("BACKGROUND", Vector2(0,0), SCREEN_WIDTH, SCREEN_HEIGHT, std::vector<Uint8>{255, 0, 0, 255}), // the order MATTERS
        Entity(nullptr, Vector2(100, 100), 100, 100, std::vector<Uint8>{0, 255, 0, 255}),
    };

    std::vector<Entity> RGBA_Entities = {
        Entity("BACKGROUND", Vector2(0,0), SCREEN_WIDTH, SCREEN_HEIGHT, std::vector<Uint8>{255, 0, 0, 255}), // the order MATTERS
        Entity(nullptr, Vector2(100, 100), 100, 100, std::vector<Uint8>{0, 255, 0, 255}),
    };

    // for (auto entity: ENTITIES)
    // {
    //     if (entity.name != nullptr)
    //     {
    //         colldingEntities.push_back(entity)
    //     }
    // }


    std::vector<Entity> textureEntities = {

    };



    //entities.reserve(Entity.getAmountOfEntities());
    
    // game bools

    SDL_Event event;
    bool running = true;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    while (running)
    {
        SDL_Delay(10);
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        }

       

        // for (auto entities: collidingEntities) 
        // {
        //     // collision[0] = (SDL_HasIntersection(&player.rect, &entities.rect));

        // }
        

        // if (keystates[SDL_SCANCODE_LEFT] && !collision)
        //     player.move(Vector2(-2, 0));
        // if (keystates[SDL_SCANCODE_RIGHT] && !collision)
        //     player.move(Vector2(2, 0));
        // if (keystates[SDL_SCANCODE_UP] && !collision)
        //     player.move(Vector2(0, -2));
        // if (keystates[SDL_SCANCODE_DOWN] && !collision)
        //     player.move(Vector2(0, 2));

        // debug
        std::cout << player.getPos() << '\n';
        // if (collision)
        //     std::cout << "Collision!\n";

        // update
        player.update();

        // render
        window.clear();
        for (auto entity: RGBA_Entities)
        {
            window.render(&entity.rect, entity.getRGBA());
        }
        window.render(player);
        //window.render(&player.rect, nullptr, 0, 0, 255, 255);
        //window.render(&e.rect, nullptr, 0, 255, 0, 255);
        // window.render(&rect1, nullptr, 242, 242, 242, 255);
        // window.render(&rect2, nullptr, 0, 255, 0, 255);
        window.display();
    }

    // cleanup SDL

    SDL_Quit();
    return 0;
}
