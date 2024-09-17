#ifndef GAME_BUILD_H_
#define GAME_BUILD_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "util.h"

int maze_init();
int maze_load();
int maze_close();
int create2Dmap();
int drawMainSprite(double angle);


#endif /* GAME_BUILD_H_ */
