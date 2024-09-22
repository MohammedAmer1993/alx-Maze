#ifndef POSITIONS_H_
#define POSITIONS_H_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include "def.h"

pos getCurrentPos(void);
collision calculateXCollison(pos current, point spriteCenter, double xVal);
collision calculateYCollison(pos current, point spriteCenter, double yVal);
void setAddedValueAfterColl(double *xValue, double *yValue, pos current, point spriteCenter);
point getSprCenter(double angle);

#endif /* POSITIONS_H_ */
