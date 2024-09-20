#include "raycasting_util.h"

pos directionVector(double angle)
{
	pos vector = {0, 0};
	if (angle >= 0 && angle < PI / 2)
	{
		vector.x = 1;
		vector.y = 1;
	}	
	else if (angle >= PI / 2 && angle < PI)
	{
		vector.x = -1;
		vector.y = 1;
	}
	else if (angle >= PI && angle < (3 * PI) / 2)
	{
		vector.x = -1;
		vector.y = -1;
	}
	else if (angle >= (3 * PI) / 2 && angle < 2 * PI)
	{
		vector.x = 1;
		vector.y = -1;
	}
	return (vector);
}


point getInitialState(double angle)
{
	pos current = calculatePosInArr();
	point intialState = {0, 0};

	if (angle > (3 * PI) / 2 && angle < (PI / 2) )
	{
		intialState.x = (((current.x + 1) * CELL_SIZE)) - sprite.x;
	}
	else
	{
		intialState.x = sprite.x;
	}
	if (angle > 0 && angle < PI)
	{
		intialState.y = (((current.y + 1) * CELL_SIZE)) - sprite.y;
	}
	else
	{
		intialState.y = sprite.y;
	}
	return (intialState);
}
