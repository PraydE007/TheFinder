#include "header.h"

int main() {
    int running = 1;
    SDL_Event event;

    t_map *map = mx_load_map("res/maps/map1.json");

    // ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ MAP ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ //
    // // // // // // // // // // // // // // // // // // // //

    // int lenX = 24;
    // int lenY = 24;
    // int sizeX = MX_SCREEN_WIDTH / lenX;
    // int sizeY = MX_SCREEN_HEIGHT / lenY;
    // int arr[24][24] =  {{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-2,-1,-1, 0, 0, 0,-1,-1,-1, 0, 0, 0,-1,-1,-2, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-2,-1,-1, 0, 0, 0,-1,-1,-1, 0, 0, 0,-1,-1,-2, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-2,-1,-1, 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-2,-1,-1,-1,-1,-1, 0,-2, 0,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-2,-1,-1,-1,-1,-1, 0,-2, 0,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-2, 0, 0, 0,-1,-1,-1,-2,-1,-1,-1, 0, 0, 0,-2, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0,-1,-1,-1,-2, 0,-1,-1,-2,-1,-1, 0,-2,-1,-1,-1, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0,-2, 0,-1,-1,-2,-1,-1, 0,-2, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0,-2, 0, 0, 0,-2, 0, 0, 0,-2, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0,-2,-1,-1,-1,-1,-1,-1,-1,-2, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0,-2,-1,-2,-1,-2,-1,-2,-1,-2, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 0, 0, 0, 0, 0, 0,-2,-1,-2,-1,-2,-1,-2,-1,-2, 0, 0, 0, 0, 0, 0, 0,-1},
    //                     {-1, 3, 0, 0, 0, 0, 0,-2,-1,-2,-1,-2,-1,-2,-1,-2, 0, 0, 0, 0, 0, 0, 4,-1},
    //                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

    // // // // // // // // // // // // // // // // // // // //

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 && IMG_Init(IMG_INIT_PNG)) {
        printf("Failed to init SDL\n");
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow(
        "Map", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        MX_SCREEN_WIDTH, MX_SCREEN_HEIGHT, SDL_WINDOW_ALWAYS_ON_TOP
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture *texture[map->size_x * map->size_y];
    for (int y = 0; y < map->size_y; y++) {
        for (int x = 0; x < map->size_x; x++) {
            if (map->matrix[(x * map->size_x) + y] == -1)
                texture[map->size_x * y + x ] = IMG_LoadTexture(renderer, "res/texture/blockofplatform.png");
            if (map->matrix[(x * map->size_x) + y]  == -2)
                texture[map->size_x * y + x] = IMG_LoadTexture(renderer, "res/texture/download.png");
            if (map->matrix[(x * map->size_x) + y]  == 0)
                texture[map->size_x * y + x] = IMG_LoadTexture(renderer, "res/texture/space.png");
            if (map->matrix[(x * map->size_x) + y]  == 3)
                texture[map->size_x * y + x] = IMG_LoadTexture(renderer, "res/trash/trashbox1.png");
            if (map->matrix[(x * map->size_x) + y]  == 4)
                texture[map->size_x * y + x] = IMG_LoadTexture(renderer, "res/trash/trashbox2.png");
        }
    }

    while (running) {

        while(SDL_PollEvent(&event)) {
            if ((SDL_QUIT == event.type)
                || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
                running = 0;
        }

        // ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ DRAW ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ //
        // // // // // // // // // // // // // // // // // // // //

        SDL_RenderClear(renderer);

        int scale_x = MX_SCREEN_WIDTH / map->size_x;
        int scale_y = MX_SCREEN_HEIGHT / map->size_y;

        for (int y = 0; y < 24; y++) {
            for (int x = 0; x < 24; x++) {
                SDL_Rect rect = {scale_x * x, scale_y * y, scale_x, scale_y};

                SDL_RenderCopy(renderer, texture[(x * map->size_x) + y], NULL, &rect);
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(120);

        // // // // // // // // // // // // // // // // // // // //
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

