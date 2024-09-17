#ifndef UTIL_H_
#define UTIL_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include "def.h"

SDL_Surface *loadSurface(char *str);
SDL_Texture *createTextureFromSurface(SDL_Surface *surface);


#endif /* UTIL_H_ */
