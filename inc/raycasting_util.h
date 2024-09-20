#ifndef RAYCASTING_UTIL_H_
#define RAYCASTING_UTIL_H_

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "def.h"
#include "positions.h"

pos directionVector(double angle);
point getInitialState(double angle);


#endif /* RAYCASTING_UTIL_H_ */
