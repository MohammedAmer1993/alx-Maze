#include "positions.h"

pos calculatePosInArr(void)
{
	pos current = {-1, -1};
	int x = sprite.x;
	int y = sprite.y;

	current.x = floor(x / CELL_SIZE);
	current.y = floor(y / CELL_SIZE);

	return (current);
}

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

collision calculateXCollison(pos current, double x)
{
	int xCor = 0;

	xCor = floor((sprite.x + round(x)) / CELL_SIZE);
	if (mapArr[current.y][xCor] == 1)
	{
		return (COLLISION_X_DIR);
	}
	else
	{
		return (COLLISION_NONE);
	}
}
collision calculateYCollison(pos current, int y)
{
	int yCor = 0;

	yCor = floor((sprite.y + round(y)) / CELL_SIZE);
	if (mapArr[yCor][current.x] == 1)
	{
		return (COLLISION_Y_DIR);
	}
	else
	{
		return (COLLISION_NONE);
	}
}

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
