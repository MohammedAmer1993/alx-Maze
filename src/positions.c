#include "positions.h"

/**
 * getCurrentPos - calculate the position of sprite on 2dmap
 * Return: a structure pos (x,y) coordinate with respect to 2dmap
 */
pos getCurrentPos(void)
{
	pos current = {-1, -1};
	int x = sprite.x;
	int y = sprite.y;

	current.x = floor(x / CELL_SIZE);
	current.y = floor(y / CELL_SIZE);

	return (current);
}


/**
 * calculateXCollison - detect if collison is going to happen in x direction
 * @current: posion of sprite with respect to 2dmap
 * @xVal: the added value in x direction
 * Return: enum collision
 */
collision calculateXCollison(pos current, point spriteCenter, double xVal)
{
	int xCor = 0;
	xCor = floor((spriteCenter.x + round(xVal)) / CELL_SIZE);
	if (mapArr[current.y][xCor] == 1)
	{
		return (COLLISION_X_DIR);
	}
	else
	{
		return (COLLISION_NONE);
	}
}

/**
 * calculateYCollison - detect if collison is going to happen in y direction
 * @current: posion of sprite with respect to 2dmap
 * @yVal: the added value in y direction
 * Return: enum collision
 */
collision calculateYCollison(pos current, point spriteCenter, double yVal)
{
	int yCor = 0;

	yCor = floor((spriteCenter.y + round(yVal)) / CELL_SIZE);
	if (mapArr[yCor][current.x] == 1)
	{
		return (COLLISION_Y_DIR);
	}
	else
	{
		return (COLLISION_NONE);
	}
}

/**
 * setAddedValueAfterColl - set added value to 0 if collison happens
 * @xValue: pointer to the added value in x direction
 * @yValue: pointer to the added value in y direction
 * @current: postion of sprite with respect to 2dmap
 * Return: Nothing (void function)
 */
void setAddedValueAfterColl(double *xValue, double *yValue, pos current, point spriteCenter)
{
	if (calculateXCollison(current, spriteCenter,*xValue) == COLLISION_X_DIR)
	{
		*xValue = 0;
	}
	if (calculateYCollison(current, spriteCenter, *yValue) == COLLISION_Y_DIR)
	{
		*yValue = 0;
	}
}

point getSprCenter(double angle)
{
	point center = {0, 0};
	double diognalLen = sprite.w * sqrt(2);
	center.x = sprite.x + (diognalLen * cos(angle)) / 2;
	center.y = sprite.y + (diognalLen * sin(angle)) / 2;
	return (center);
}
