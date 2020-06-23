#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <json-c/json.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#define MX_SCREEN_WIDTH 800
#define MX_SCREEN_HEIGHT 800

typedef struct s_map {
    int size_x;
    int size_y;
    int *matrix;
} t_map;

typedef struct s_player {
    int x;
    int y;
} t_player;

t_map *mx_load_map(char *filename);

#endif
