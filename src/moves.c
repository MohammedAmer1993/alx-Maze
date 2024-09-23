#include "moves.h"

/**
 * angleIn360Range - make sure the angle is in 360 range
 * @angle: the angle of the sprite
 * Return: the angle of the sprite after correcting it to be in range 360
 */
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

/**
 * move - make sprite move forward, backward, left and right with respect to its angle
 * @angle: the angle of sprite
 * @mov: the step of sprite
 * @sign: to determine if he moving forward or backward
 * @quarter: to determine the perpendcular movement, righ or left
 * Return: Nothing (void function)
 */
void move(double angle, int mov, char sign, double quarter)
{
	pos current = getCurrentPos();
	double xValue = 0;
	double yValue = 0;

	xValue = sign * mov * cos((angle + quarter));
	yValue = sign * mov * sin((angle + quarter));
	correctionForXandY(&xValue, &yValue);
	setAddedValueAfterColl(&xValue, &yValue, current);
	sprite.x += xValue;
	sprite.y += yValue;  /* int dosn't have dicimal BUG */
	
}


void correctionForXandY(double *Xval, double *Yval)
{
	if (*Xval > 0)
	{
		*Xval = ceil(*Xval);
	}
	else
	{
		*Xval = -1 * ceil(-1 * (*Xval));
	}
	if (*Yval > 0)
	{
		*Yval = ceil(*Yval);
	}
	else
	{
		*Yval = -1 * ceil(-1 * (*Yval));
	}
}
