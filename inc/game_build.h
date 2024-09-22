#ifndef GAME_BUILD_H_
#define GAME_BUILD_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "util.h"

int maze_init(void);
int maze_load(void);
void maze_close(void);
int create2Dmap(void);
int drawMainSprite(double angle);
void draw_grid();


#endif /* GAME_BUILD_H_ */
