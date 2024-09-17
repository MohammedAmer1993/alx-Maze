#ifndef MOVES_H_
#define MOVES_H_

#include <math.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <def.h>
#include "positions.h"

double angleIn360Range(double angle);
void moveForward(double *angle, int mov);
void moveBackward(double *angle, int mov);
void moveLeft(double *angle, int mov);
void moveRight(double *angle, int mov);

#endif /* MOVES_H_ */
