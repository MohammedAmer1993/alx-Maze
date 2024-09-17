#include "positions.h"

pos calculatePosInArr()
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
	int zz = round(x);
	xCor = floor((sprite.x + zz) / CELL_SIZE);
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
