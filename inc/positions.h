#ifndef POSITIONS_H_
#define POSITIONS_H_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include "def.h"

pos getCurrentPos(void);
collision calculateXCollison(pos current, double xVal);
collision calculateYCollison(pos current, double yVal);
void setAddedValueAfterColl(double *xValue, double *yValue, pos current);
SDL_Point getSprCenter();
void getCollDetectionPoints(SDL_Point *points);
#endif /* POSITIONS_H_ */
