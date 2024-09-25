#ifndef RAYCASTING_H_
#define RAYCASTING_H_

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "def.h"
#include "positions.h"
#include "raycasting_util.h"

double calculateDistance(double angle);
double calculateRayLen(double lengthForVerCollLine, double lengthForHorCollLine, double movVerUnit, double movHorUnit, double angle, SDL_Point spriteCenter);
double calculateRayLenForward(SDL_Point spriteCenter , collision *collFlag);
double calculateRayLenBackward(SDL_Point spriteCenter , collision *collFlag);
double calculateRayLenDown(SDL_Point spriteCenter , collision *collFlag);
double calculateRayLenUp(SDL_Point spriteCenter , collision *collFlag);
void getRayCastingArr(SDL_Point *arr, int size, double angle);
#endif /* RAYCASTING_H_ */
