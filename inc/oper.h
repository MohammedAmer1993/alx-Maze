#ifndef OPER_H_
#define OPER_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "util.h"

int maze_init();
int maze_load();
int maze_close();
int create2Dmap();
int drawMainSprite(double angle);


#endif /* OPER_H_ */
