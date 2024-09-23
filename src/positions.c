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
collision calculateXCollison(pos current, double xVal)
{
	int xCor = 0;
	collision state = COLLISION_NONE;
	SDL_Point collPoints[3];
	getCollDetectionPoints(collPoints);
	for (int i = 0; i < 3; ++i)
	{
		xCor = floor((collPoints[i].x + xVal) / CELL_SIZE);
		printf("ix %d iy %d\n", collPoints[i].x, collPoints[i].y);
		if (mapArr[current.y][xCor] != 0)
		{
			state = COLLISION_X_DIR;
		}
	}
	return (state);
	printf("x cor %d y cor %d\n", current.x, current.y);
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
	collision state = COLLISION_NONE;
	SDL_Point collPoints[3];
	getCollDetectionPoints(collPoints);
	for (int i = 0; i < 3; ++i)
	{

		yCor = floor((collPoints[i].y + yVal) / CELL_SIZE);
		if (mapArr[yCor][current.x] != 0)
		{
			state =  COLLISION_Y_DIR;
		}
	}
	return (state);
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

SDL_Point getSprCenter()
{
	SDL_Point center = {0, 0};
	double diognalLen = sprite.w * sqrt(2);
	printf("%f mmmm\n", diognalLen);
	center.x = sprite.x + (diognalLen * cos(ANGLE_OF_DETECTOR)) / 2;
	center.y = sprite.y + (diognalLen * sin(ANGLE_OF_DETECTOR)) / 2;
	return (center);
}

void getCollDetectionPoints(SDL_Point *points)
{
	int x = 0;
	int y = 0;
	double len = sqrt((sprite.w * sprite.w) + ((sprite.w / 2) * (sprite.w / 2)));

	points[0].x = sprite.x;
	points[0].y = sprite.y;
	x = sprite.x + len * cos(FRONT_POINT_ANGLE);
	y = sprite.y + len * sin(FRONT_POINT_ANGLE);
	points[1].x = x;
	points[1].y = y;
	x = sprite.x + sprite.w * cos(BOTTOM_POINT_ANGLE);
	y = sprite.y + sprite.w * sin(BOTTOM_POINT_ANGLE);
	points[2].x = x;
	points[2].y = y;
}
