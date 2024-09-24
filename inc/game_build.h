#ifndef GAME_BUILD_H_
#define GAME_BUILD_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "util.h"
#include "raycasting.h"

int maze_init(void);
int maze_load(void);
void maze_close(void);
int create2Dmap(void);
int drawMainSprite(double angle);
void drawLines(SDL_Point  *arr, int size);

#endif /* GAME_BUILD_H_ */
