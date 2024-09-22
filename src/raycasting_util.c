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


point getInitialState(double angle, point spriteCenter)
{
	pos current = getCurrentPos();
	point intialState = {0, 0};

	if (angle > (3 * PI) / 2 && angle < (PI / 2) )
	{
		intialState.x = ((current.x + 1) * CELL_SIZE) - spriteCenter.x;
	}
	else
	{
		intialState.x = spriteCenter.x - (current.x * CELL_SIZE);
	}
	if (angle > 0 && angle < PI)
	{
		intialState.y = ((current.y + 1) * CELL_SIZE) - spriteCenter.y;
	}
	else
	{
		intialState.y = spriteCenter.y - (current.y * CELL_SIZE);
	}
	return (intialState);
}


direction getBeamState(double angle)
{
	if (angle < 0.0001 && angle > -0.0001)
		return (BEAM_FORWARD);
	if (angle > 0.0 && angle < (PI / 2))
		return (BEAM_FORWARD_DOWN);
	if (angle < ((PI / 2) + 0.0001) && angle > ((PI / 2) - 0.0001))
		return (BEAM_DOWN);
	if (angle > (PI / 2) && angle < PI )
		return (BEAM_BACKWARD_DOWN);
	if (angle < PI + 0.0001 && angle > PI - 0.0001)
		return (BEAM_BACKWARD);
	if (angle > PI && angle < ((3 * PI) / 2))
		return (BEAM_BACKWARD_UP);
	if (angle < (((3 * PI) / 2) + 0.0001) && angle > (((3 * PI) / 2) - 0.0001))
		return (BEAM_UP);
	if (angle > ((3 * PI) / 2) && angle < (2 * PI))
		return (BEAM_FORWARD_UP);
	else
		return (BEAM_ERR);
}


pos getPositionForPoint(point endpoint)
{
	pos current = {0, 0};
	current.x = floor(endpoint.x / CELL_SIZE);
	current.y = floor(endpoint.y / CELL_SIZE);
	return (current);
}

collision calulateCollandTextureType(pos current)
{
	collision collisionState;
	switch (mapArr[current.y][current.x])
	{
	case 1:
		collisionState = COLLISION_DETECTED_TEXT_1;
		break;
	case 2:
		collisionState = COLLISION_DETECTED_TEXT_2;
		break;
	case 3:
		collisionState = COLLISION_DETECTED_TEXT_3;
		break;
	case 4:
		collisionState = COLLISION_DETECTED_TEXT_4;
		break;
	default:
		collisionState = COLLISION_NONE;
		break;
	}
	return collisionState;
}
