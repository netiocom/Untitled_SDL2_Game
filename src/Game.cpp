#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <string>
#include "RenderWindow.hpp"
#include "Utils.hpp"
#include "Vector2.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "Tilemap.hpp"
#include "Game.hpp"
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720
#define SCREEN_TITLE "Game v1.0.0"

void grun()
{
    Init();
    

    RenderWindow window(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    // textures
    SDL_Texture *playerTex = window.loadTexture("../../assets/Player/microsoft.png");

    // Player player = Player("PLAYER", Vector2(250, 250), 100, 100, nullptr);
    Player player = Player("PLAYER", Vector2(250, 250), 100, 100, playerTex, Vector2(2, 2));

    // tilemap
    std::vector<std::string> map = {
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
    };


    Tilemap tilemap = Tilemap(map, 64);
    tilemap.generateTiles();

    // entity vectors

    std::vector<Entity> ENTITIES = {
        Entity("BACKGROUND", Vector2(0, 0), SCREEN_WIDTH, SCREEN_HEIGHT, std::vector<Uint8>{0, 0, 0, 255}), // the order MATTERS
        Entity(nullptr, Vector2(100, 100), 100, 100, std::vector<Uint8>{0, 255, 0, 255}),
    };

    std::vector<Entity> RGBA_Entities = {
        ENTITIES[0],
        ENTITIES[1],
    };

    for (auto entity : ENTITIES)
    {
        entity.getInfo();
    }

    std::vector<Entity> collidingEntities = {
        ENTITIES[1]

    };

    std::vector<SDL_bool> intersectingEntities = {
        SDL_HasIntersection(&player.rect, &collidingEntities[0].rect)
    };

    // game bools
    SDL_Event event;
    bool running = true, onSurface;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    Vector2 movement = Vector2(2,2);

    while (running)
    {
        SDL_Delay(10);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            }
        }

        if (player.rect.y <= 500)
        {
            player.move(Vector2(0, 2));
            onSurface = false;
        } else {
            onSurface = true;
        }

        std::vector<SDL_bool> intersectingEntities = {
            SDL_HasIntersection(&player.rect, &collidingEntities[0].rect)};

        SDL_bool collision = vecAnyItemTrue(intersectingEntities);

        if (keystates[SDL_SCANCODE_LEFT] && !collision)
            player.move(Vector2(-player.getSpeed().x, 0));
        if (keystates[SDL_SCANCODE_RIGHT] && !collision)
            player.move(Vector2(player.getSpeed().x, 0));
        if (keystates[SDL_SCANCODE_UP] && !collision && onSurface)
            // player.gravity = false; 
            

            player.move(Vector2(0, -player.getSpeed().y));
        if (keystates[SDL_SCANCODE_DOWN] && !collision)
            player.move(Vector2(0, player.getSpeed().y));










        player.update();
        window.clear();
        for (auto entity : RGBA_Entities)
        {
            window.render(&entity.rect, entity.getRGBA());
        }
        window.render(tilemap.returnTiles());
        window.render(player);
        window.display();
    }
    
    SDL_Quit();
    player.del();
}
