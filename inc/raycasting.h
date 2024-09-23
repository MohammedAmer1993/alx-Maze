#ifndef RAYCASTING_H_
#define RAYCASTING_H_

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "def.h"
#include "positions.h"
#include "raycasting_util.h"

double calculateDistance(double angle);
double calculateCollDistance(double lengthForVerCollLine, double lengthForHorCollLine, double angle, SDL_Point);
double calculateCollDistanceForward(SDL_Point, collision *collFlag);
double calculateCollDistanceBackward(SDL_Point, collision *collFlag);
double calculateCollDistanceDown(SDL_Point, collision *collFlag);
double calculateCollDistanceUp(SDL_Point, collision *collFlag);
#endif /* RAYCASTING_H_ */
