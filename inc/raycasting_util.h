#ifndef RAYCASTING_UTIL_H_
#define RAYCASTING_UTIL_H_

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "def.h"
#include "positions.h"

pos getPositionForPoint(SDL_Point endpoint);
collision calulateCollandTextureType(SDL_Point current, collisionType type);
SDL_Point getInitialState(direction beamState, SDL_Point  spriteCenter);
direction getBeamState(double angle);

#endif /* RAYCASTING_UTIL_H_ */
