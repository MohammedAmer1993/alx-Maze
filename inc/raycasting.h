#ifndef RAYCASTING_H_
#define RAYCASTING_H_

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "def.h"
#include "positions.h"
#include "raycasting_util.h"

double calculateDistance(double angle);
double calculateCollDistance(double lengthForVerCollLine, double lengthForHorCollLine, double angle, point spriteCenter);
double calculateCollDistanceForward(point spriteCenter, collision *collFlag);
double calculateCollDistanceBackward(point spriteCenter, collision *collFlag);
double calculateCollDistanceDown(point spriteCenter, collision *collFlag);
double calculateCollDistanceUp(point spriteCenter, collision *collFlag);
#endif /* RAYCASTING_H_ */
