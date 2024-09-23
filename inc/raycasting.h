#ifndef RAYCASTING_H_
#define RAYCASTING_H_

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "def.h"
#include "positions.h"
#include "raycasting_util.h"

double calculateDistance(double angle);
double calculateRayLen(double lengthForVerCollLine, double lengthForHorCollLine, double angle, SDL_Point);
double calculateRayLenForward(SDL_Point, collision *collFlag);
double calculateRayLenBackward(SDL_Point, collision *collFlag);
double calculateRayLenDown(SDL_Point, collision *collFlag);
double calculateRayLenUp(SDL_Point, collision *collFlag);
#endif /* RAYCASTING_H_ */
