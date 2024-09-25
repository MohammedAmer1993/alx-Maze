#include "raycasting.h"


void getRayCastingArr(SDL_Point *arr, int size, double angle)
{
	SDL_Point spriteCenter = getSprCenter();
	int j = 0;
	double len = 0;
	for (int i = (size / 2) - 1; i >= 0 ; --i)
	{
		
		len = calculateDistance(angle + (i * -0.05));
		arr[j].x = spriteCenter.x + len * cos(angle + (i * -0.05));
		arr[j].y = spriteCenter.y + len * sin(angle + (i * -0.05));
		++j;
		// printf("***********\n");
		// printf ("%f\n", len);
		// printf("*************\n");
	}
	for (int i = 1; i <= size / 2; ++i)
	{
		len = calculateDistance(angle + (i * 0.05));
		arr[j].x = spriteCenter.x + len * cos(angle + (i * 0.5));
		arr[j].y = spriteCenter.y + len * sin(angle + (i * 0.5));
		++j;
		// printf("***********\n");
		// printf ("%f\n", len);
		// printf("*************\n");
	}
}

double calculateDistance(double angle)
{
	SDL_Point spriteCenter = getSprCenter();
	direction beamDir = getBeamState(angle);
	printf("%d beamstate\n", beamDir);
	SDL_Point initialStatePoint = getInitialState(beamDir, spriteCenter);
	double distanceForOneInXDir = 0;
	double distanceForOneInYDir = 0;
	double lengthForVerCollLine = 0;
	double lengthForHorCollLine = 0;
	double lenOfRay = -1;
	collision collFlag = COLLISION_NONE;
	switch (beamDir)
	{
	case BEAM_FORWARD:
		lenOfRay = calculateRayLenForward(spriteCenter, &collFlag);
		break;
	case BEAM_DOWN:
		lenOfRay = calculateRayLenDown(spriteCenter, &collFlag);
		break;
	case BEAM_BACKWARD:
		lenOfRay = calculateRayLenBackward(spriteCenter, &collFlag);
		break;
	case BEAM_UP:
		lenOfRay = calculateRayLenUp(spriteCenter, &collFlag);
		break;
	default:
		distanceForOneInXDir = CELL_SIZE * sqrt(1 + tan(angle) * tan(angle));
		distanceForOneInYDir = CELL_SIZE * sqrt(1 + (1 / tan(angle)) * (1 / tan(angle)));
		lengthForVerCollLine = fabs(initialStatePoint.x / cos(angle));
		lengthForHorCollLine = fabs(initialStatePoint.y / sin(angle));
		lenOfRay = calculateRayLen(lengthForVerCollLine, lengthForHorCollLine, distanceForOneInXDir, distanceForOneInYDir, angle, spriteCenter);
		break;
	}
	return (lenOfRay);
}


double calculateRayLen(double lengthForVerCollLine, double lengthForHorCollLine, double movVerUnit, double movHorUnit, double angle, SDL_Point spriteCenter)
{
	SDL_Point pointCollVer = {spriteCenter.x + lengthForVerCollLine * cos(angle), spriteCenter.y + lengthForVerCollLine * sin(angle)};
	SDL_Point pointCollHor = {spriteCenter.x + lengthForHorCollLine * cos(angle), spriteCenter.y + lengthForHorCollLine * sin(angle)};
	double rayLen = -1;

	while (rayLen == -1)
	{
		if (lengthForVerCollLine >= lengthForHorCollLine)
		{
			if(calulateCollandTextureType(pointCollVer, VERTICAL_COLLISION) != COLLISION_NONE)
			{
				rayLen = lengthForVerCollLine;
			}
			else
			{
				lengthForVerCollLine += movHorUnit;
			}
		}
		else
		{
			if(calulateCollandTextureType(pointCollHor, HORIZONTAL_COLLISION) != COLLISION_NONE)
			{
				rayLen = lengthForHorCollLine;
			}
			else
			{
				lengthForHorCollLine += movVerUnit;
			}

		}
	}
	return (rayLen);
}


double calculateRayLenForward(SDL_Point spriteCenter, collision *collFlag)
{
	pos current = getPositionForPoint(spriteCenter);
	int collCordinate = 0;
	double distanceForward = 0;
	*collFlag = COLLISION_NONE;
	
	for (int i = current.x + 1; i < MAP_WIDTH; ++i)
	{
		switch (mapArr[current.y][i])
		{
		case COLLISION_DETECTED_TEXT_1:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_1;
			break;
		case COLLISION_DETECTED_TEXT_2:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_2;
			break;
		case COLLISION_DETECTED_TEXT_3:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_3;
			break;
		case COLLISION_DETECTED_TEXT_4:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_4;
			break;
		default:
			break;
		}
		if (*collFlag != COLLISION_NONE)
		{
			break;
		}
	}
	distanceForward = collCordinate * CELL_SIZE - spriteCenter.x;
	return (distanceForward);
}

double calculateRayLenBackward(SDL_Point spriteCenter, collision *collFlag)
{
	pos current = getPositionForPoint(spriteCenter);
	int collCordinate = 0;
	double distanceForward = 0;
	*collFlag = COLLISION_NONE;

	
	for (int i = current.x - 1; i >= 0; --i)
	{
		switch (mapArr[current.y][i])
		{
		case COLLISION_DETECTED_TEXT_1:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_1;
			break;
		case COLLISION_DETECTED_TEXT_2:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_2;
			break;
		case COLLISION_DETECTED_TEXT_3:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_3;
			break;
		case COLLISION_DETECTED_TEXT_4:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_4;
			break;
		default:
			break;
		}
		if (*collFlag != COLLISION_NONE)
		{
			break;
		}
	}
	distanceForward = spriteCenter.x - (collCordinate + 1) * CELL_SIZE;
	return (distanceForward);
}

double calculateRayLenDown(SDL_Point  spriteCenter, collision *collFlag)
{
	pos current = getPositionForPoint(spriteCenter);
	int collCordinate = 0;
	double distanceForward = 0;
	*collFlag = COLLISION_NONE;

	for (int i = current.y + 1; i < SCREEN_HEIGHT; ++i)
	{
		switch (mapArr[i][current.x])
		{
		case COLLISION_DETECTED_TEXT_1:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_1;
			break;
		case COLLISION_DETECTED_TEXT_2:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_2;
			break;
		case COLLISION_DETECTED_TEXT_3:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_3;
			break;
		case COLLISION_DETECTED_TEXT_4:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_4;
			break;
		default:
			break;
		}
		if (*collFlag != COLLISION_NONE)
		{
			break;
		}
	}
	distanceForward = collCordinate * CELL_SIZE - spriteCenter.y;
	return (distanceForward);
}

double calculateRayLenUp(SDL_Point  spriteCenter, collision *collFlag)
{
	pos current = getPositionForPoint(spriteCenter);
	int collCordinate = 0;
	double distanceForward = 0;
	*collFlag = COLLISION_NONE;
	for (int i = current.y - 1; i >= 0; --i)
	{
		switch (mapArr[i][current.x])
		{
		case COLLISION_DETECTED_TEXT_1:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_1;
			break;
		case COLLISION_DETECTED_TEXT_2:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_2;
			break;
		case COLLISION_DETECTED_TEXT_3:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_3;
			break;
		case COLLISION_DETECTED_TEXT_4:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_4;
			break;
		default:
			break;
		}
		if (*collFlag != COLLISION_NONE)
		{
			break;
		}
	}
	distanceForward = spriteCenter.y - (collCordinate + 1) * CELL_SIZE;
	return (distanceForward);
}




/* test 

double calculateRayLenForward(SDL_Point  spriteCenter, collision *collFlag)
{
	pos current = getCurrentPos();
	int collCordinate = 0;
	double distanceForward = 0;
	*collFlag = COLLISION_NONE;

	for (int i = current.y - 1; i >= 0; --i)
	switch (mapArr[i][current.x])
	for (int i = current.y + 1; i < SCREEN_HEIGHT; ++i)
	switch (mapArr[i][current.x])
	for (int i = current.x - 1; i >= 0; --i)
	switch (mapArr[current.y][i])
	for (int i = current.x + 1; i < MAP_WIDTH; ++i)
	switch (mapArr[current.y][i])


	{
		switch (mapArr[current.y][i])
		{
		case COLLISION_DETECTED_TEXT_1:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_1;
			break;
		case COLLISION_DETECTED_TEXT_2:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_2;
			break;
		case COLLISION_DETECTED_TEXT_3:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_3;
			break;
		case COLLISION_DETECTED_TEXT_4:
			collCordinate = i;
			*collFlag = COLLISION_DETECTED_TEXT_4;
			break;
		default:
			break;
		}
		if (*collFlag != COLLISION_NONE)
		{
			break;
		}
	}
	distanceForward = collCordinate * CELL_SIZE - spriteCenter.x;
	return (distanceForward);
}

*/
