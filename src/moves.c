#include "moves.h"


double angleIn360Range(double angle)
{
	while (angle < 0)
	{
		angle += (2 * PI);
	}
	while (angle > (2 * PI))
	{
		angle -= (2 * PI);
	}
	return (angle);
}


void moveForward(double *angle, int mov)
{
	pos current = calculatePosInArr();
	double xValue = 0;
	double yValue = 0;

	if (*angle >= 0 && *angle < (PI / 2))
	{
		xValue = (mov * cos((*angle)));
		yValue = (mov * sin((*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;  /* int dosn't have dicimal BUG */
	}
	else if ((*angle) >= (PI / 2) && (*angle) < PI)
	{
		xValue = -(mov * cos(PI - (*angle)));
		yValue = (mov * sin(PI - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if ((*angle) >= PI && (*angle) < ((3 * PI) / 2))
	{
		xValue = -(mov * sin(((3 * PI) / 2) - (*angle)));
		yValue = -(mov * cos(((3 * PI) / 2) - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if (((*angle) >= ((3 * PI) / 2)) && (*angle) < (2 * PI))
	{
		xValue = (mov * cos(2 * PI - (*angle)));
		yValue = -(mov * sin(2 * PI - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
}


void moveBackward(double *angle, int mov)
{
	pos current = calculatePosInArr();
	double xValue = 0;
	double yValue = 0;

	if (*angle >= 0 && *angle < (PI / 2))
	{
		xValue = -(mov * cos((*angle)));
		yValue = -(mov * sin((*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if ((*angle) >= (PI / 2) && (*angle) < PI)
	{
		xValue = (mov * cos(PI - (*angle)));
		yValue = -(mov * sin(PI - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if ((*angle) >= PI && (*angle) < ((3 * PI) / 2))
	{
		xValue = (mov * sin(((3 * PI) / 2) - (*angle)));
		yValue = (mov * cos(((3 * PI) / 2) - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if (((*angle) >= ((3 * PI) / 2)) && (*angle) < (2 * PI))
	{
		xValue = -(mov * cos(2 * PI - (*angle)));
		yValue = (mov * sin(2 * PI - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
}

void moveLeft(double *angle, int mov)
{
	pos current = calculatePosInArr();
	double xValue = 0;
	double yValue = 0;

	if (*angle >= 0 && *angle < (PI / 2))
	{
		xValue = -(mov * cos(PI - (*angle)));
		yValue = -(mov * sin(PI - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if ((*angle) >= (PI / 2) && (*angle) < PI)
	{
		xValue = -(mov * cos((*angle)));
		yValue = (mov * sin((*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if ((*angle) >= PI && (*angle) < ((3 * PI) / 2))
	{
		xValue = (mov * cos(2 * PI - (*angle)));
		yValue = (mov * sin(2 * PI - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if (((*angle) >= ((3 * PI) / 2)) && (*angle) < (2 * PI))
	{
		xValue = (mov * sin(((3 * PI) / 2) - (*angle)));
		yValue = -(mov * cos(((3 * PI) / 2) - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
}

void moveRight(double *angle, int mov)
{

	pos current = calculatePosInArr();
	double xValue = 0;
	double yValue = 0;

	if (*angle >= 0 && *angle < (PI / 2))
	{
		xValue = (mov * cos(PI - (*angle)));
		yValue = -(mov * cos(PI - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if ((*angle) >= (PI / 2) && (*angle) < PI)
	{
		xValue = -(mov * sin(((3 * PI) / 2) - (*angle)));
		yValue = (mov * cos(((3 * PI) / 2) - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if ((*angle) >= PI && (*angle) < ((3 * PI) / 2))
	{
		xValue = -(mov * cos(2 * PI - (*angle)));
		yValue = -(mov * sin(2 * PI - (*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
	else if (((*angle) >= ((3 * PI) / 2)) && (*angle) < (2 * PI))
	{
		xValue = (mov * cos((*angle)));
		yValue = -(mov * sin((*angle)));
		setAddedValueAfterColl(&xValue, &yValue, current);
		sprite.x += xValue;
		sprite.y += yValue;
	}
}
