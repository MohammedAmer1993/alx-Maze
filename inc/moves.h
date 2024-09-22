#ifndef MOVES_H_
#define MOVES_H_

#include <math.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <def.h>
#include "positions.h"

double angleIn360Range(double angle);
void move(double angle, int mov, char sign, double quarter);
void correctionForXandY(double *Xval, double *Yval);
#endif /* MOVES_H_ */
