#include "raycasting.h"


double calculateDistance(double angle)
{
	point spriteCenter = getSprCenter(angle);
	point initialStatePoint = getInitialState(angle, spriteCenter);
	double distanceForOneInXDir = 0;
	double distanceForOneInYDir = 0;
	double lengthForVerCollLine = 0;
	double lengthForHorCollLine = 0;
	double addWhenMovX = 0;
	double addWhenMovY = 0;
	double DistanceOfColl = -1;
	direction beamDir = getBeamState(angle);
	collision collFlag = COLLISION_NONE;

	switch (beamDir)
	{
	case BEAM_FORWARD:
		DistanceOfColl = calculateCollDistanceForward(spriteCenter, &collFlag);
		break;
	case BEAM_DOWN:
		DistanceOfColl = calculateCollDistanceDown(spriteCenter, &collFlag);
		break;
	case BEAM_BACKWARD:
		DistanceOfColl = calculateCollDistanceBackward(spriteCenter, &collFlag);
		break;
	case BEAM_UP:
		DistanceOfColl = calculateCollDistanceUp(spriteCenter, &collFlag);
		break;
	default:
		distanceForOneInXDir = sqrt(1 + tan(angle) * tan(angle));
		distanceForOneInYDir = sqrt(1 + (1 / tan(angle)) * (1 / tan(angle)));
		lengthForVerCollLine = fabs(initialStatePoint.x / cos(angle));
		lengthForHorCollLine = fabs(initialStatePoint.y / sin(angle));
		while (DistanceOfColl == -1)
		{
			lengthForVerCollLine += addWhenMovX;
			lengthForHorCollLine += addWhenMovY;
			DistanceOfColl = calculateCollDistance(lengthForVerCollLine, lengthForHorCollLine, angle, spriteCenter);
			addWhenMovX += distanceForOneInXDir;
			addWhenMovY += distanceForOneInYDir;
		}
		break;
	}
	return (DistanceOfColl);
}


double calculateCollDistance(double lengthForVerCollLine, double lengthForHorCollLine, double angle, point spriteCenter)
{
	point pointCollVer = {spriteCenter.x + lengthForVerCollLine * cos(angle), spriteCenter.y + lengthForVerCollLine * sin(angle)};
	point pointCollHor = {spriteCenter.x + lengthForHorCollLine * cos(angle), spriteCenter.y + lengthForHorCollLine * sin(angle)};
	point tmpVerPoint = {pointCollVer.x + cos(angle), pointCollVer.y + sin(angle)};
	point tmpHorPoint = {pointCollHor.x + cos(angle), pointCollHor.y + sin(angle)};

	printf("pointpos %f %f\n", lengthForVerCollLine, lengthForHorCollLine);
	
	pos pointPosIn2dArrForVerColl = {0, 0};
	pos pointPosIn2dArrForHorColl = {0, 0};

	if (lengthForVerCollLine <= lengthForHorCollLine)
	{
		pointPosIn2dArrForVerColl = getPositionForPoint(tmpVerPoint);
		if (calulateCollandTextureType(pointPosIn2dArrForVerColl) != COLLISION_NONE)
		{
			return (lengthForVerCollLine);
		}
		else if (calulateCollandTextureType(pointPosIn2dArrForHorColl) != COLLISION_NONE)
		{
			return (lengthForHorCollLine);
		}
		else
		{
			return (-1);
		}
	}
	else
	{
		pointPosIn2dArrForHorColl = getPositionForPoint(tmpHorPoint);
		if (calulateCollandTextureType(pointPosIn2dArrForHorColl) != COLLISION_NONE)
		{
			return (lengthForHorCollLine);
		}
		else if (calulateCollandTextureType(pointPosIn2dArrForVerColl) != COLLISION_NONE)
		{
			return (lengthForVerCollLine);
		}
		else
		{
			return (-1);
		}
	}
}

double calculateCollDistanceForward(point spriteCenter, collision *collFlag)
{
	pos current = getCurrentPos();
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

double calculateCollDistanceBackward(point spriteCenter, collision *collFlag)
{
	pos current = getCurrentPos();
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
	distanceForward = spriteCenter.x - collCordinate * CELL_SIZE;
	return (distanceForward);
}

double calculateCollDistanceDown(point spriteCenter, collision *collFlag)
{
	pos current = getCurrentPos();
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

double calculateCollDistanceUp(point spriteCenter, collision *collFlag)
{
	pos current = getCurrentPos();
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
	distanceForward = spriteCenter.y - collCordinate * CELL_SIZE;
	return (distanceForward);
}

