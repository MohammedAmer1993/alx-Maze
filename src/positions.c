#include "positions.h"

/**
 * calculatePosInArr - calculate the position of sprite on 2dmap
 * Return: a structure pos (x,y) coordinate with respect to 2dmap
 */
pos calculatePosInArr(void)
{
	pos current = {-1, -1};
	int x = sprite.x;
	int y = sprite.y;

	current.x = floor(x / CELL_SIZE);
	current.y = floor(y / CELL_SIZE);

	return (current);
}

/**
 * calculateCollison - detect a collison
 * @current: the postion of sprite with respect to 2dmap
 * Return: enum cosslision
 */
collision calculateCollison(pos current)
{
	if (mapArr[current.y][current.x] == 1)
	{
		return (COLLISION_DETECTED);
	}
	else
	{
		return (COLLISION_NONE);
	}
}

/**
 * calculateXCollison - detect if collison is going to happen in x direction
 * @current: posion of sprite with respect to 2dmap
 * @xVal: the added value in x direction
 * Return: enum collision
 */
collision calculateXCollison(pos current, double xVal)
{
	int xCor = 0;

	xCor = floor((sprite.x + round(xVal)) / CELL_SIZE);
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
collision calculateYCollison(pos current, double yVal)
{
	int yCor = 0;

	yCor = floor((sprite.y + round(yVal)) / CELL_SIZE);
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
void setAddedValueAfterColl(double *xValue, double *yValue, pos current)
{
	if (calculateXCollison(current, *xValue) == COLLISION_X_DIR)
	{
		*xValue = 0;
	}
	if (calculateYCollison(current, *yValue) == COLLISION_Y_DIR)
	{
		*yValue = 0;
	}
}
