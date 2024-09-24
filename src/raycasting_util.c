#include "raycasting_util.h"

direction getBeamState(double angle)
{
	if ((angle >= ((2 * PI) - 0.000881) && angle <= 2 * PI ) || (angle >= 0 && angle <= 0.000881))
		return (BEAM_FORWARD);
	if (angle > 0.000881 && angle < (PI / 2) - 0.00173)
		return (BEAM_FORWARD_DOWN);
	if (angle >= (PI / 2) - 0.00173 && angle <= (PI / 2) + 0.00173)
		return (BEAM_DOWN);
	if (angle > (PI / 2) + 0.00173 && angle < PI - 0.000881 )
		return (BEAM_BACKWARD_DOWN);
	if (angle >= PI - 0.000881 && angle <= PI + 0.000881)
		return (BEAM_BACKWARD);
	if (angle > PI + 0.000881 && angle < ((3 * PI) / 2) - 0.0173)
		return (BEAM_BACKWARD_UP);
	if (angle >= ((3 * PI) / 2) - 0.0173 && angle <= ((3 * PI) / 2) + 0.0173)
		return (BEAM_UP);
	if (angle > ((3 * PI) / 2) + 0.0173 && angle < ((2 * PI) + 0.000881))
		return (BEAM_FORWARD_UP);
	else
		return (BEAM_ERR);
}



point getInitialState(direction beamState, SDL_Point spriteCenter)
{


	pos current = getCurrentPos();
	point intialState = {0, 0};

	switch (beamState)
	{
	case BEAM_FORWARD_DOWN:
		intialState.x = (current.x + 1) * CELL_SIZE - spriteCenter.x;
		intialState.y = (current.y + 1) * CELL_SIZE - spriteCenter.y;
		break;
	
	case BEAM_BACKWARD_DOWN:
		intialState.x = spriteCenter.x - (current.x * CELL_SIZE);
		intialState.y = (current.y + 1) * CELL_SIZE - spriteCenter.y;
		break;
	
	case BEAM_BACKWARD_UP:
		intialState.x = spriteCenter.x - (current.x * CELL_SIZE);
		intialState.y = spriteCenter.y - current.y * CELL_SIZE;
		break;

	case BEAM_FORWARD_UP:
		intialState.x = (current.x + 1 ) * CELL_SIZE - spriteCenter.x;
		intialState.y = spriteCenter.y - (current.y * CELL_SIZE);;
		break;
	
	default:
		break;
	}
	printf("cent .x %d   cent.y %d\n", spriteCenter.x, spriteCenter.y);
	printf("inist x %f  inist y %f\n", intialState.x, intialState.y);
	return (intialState);
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
