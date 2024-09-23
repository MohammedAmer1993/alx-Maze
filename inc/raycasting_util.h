#ifndef RAYCASTING_UTIL_H_
#define RAYCASTING_UTIL_H_

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "def.h"
#include "positions.h"

pos getPositionForPoint(point endpoint);
collision calulateCollandTextureType(pos current);
point getInitialState(double angle, SDL_Point);
direction getBeamState(double angle);

#endif /* RAYCASTING_UTIL_H_ */
