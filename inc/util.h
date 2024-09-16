#ifndef UTIL_H_
#define UTIL_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include "def.h"

int createSurface(char* str);
int createTextureFromSurface(SDL_Surface* surface);
void create2Dmap();
void drawMainSprite();


#endif /* UTIL_H_ */
