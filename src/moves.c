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
 * moveForward - make sprite move forward with respect to its angle
 * @angle: the angle of sprite
 * @mov: the step of sprite
 * Return: Nothing (void function)
 */
void moveForward(double *angle, int mov)
{
	pos current = calculatePosInArr();
	double xValue = 0;
	double yValue = 0;

	xValue = mov * cos((*angle));
	yValue = mov * sin((*angle));
	setAddedValueAfterColl(&xValue, &yValue, current);
	sprite.x += xValue;
	sprite.y += yValue;  /* int dosn't have dicimal BUG */

}

/**
 * moveBackward - make sprite move backward with respect to its angle
 * @angle: the angle of sprite
 * @mov: the step of sprite
 * Return: Nothing (void function)
 */
void moveBackward(double *angle, int mov)
{
	pos current = calculatePosInArr();
	double xValue = 0;
	double yValue = 0;

	xValue = -(mov * cos((*angle)));
	yValue = -(mov * sin((*angle)));
	setAddedValueAfterColl(&xValue, &yValue, current);
	sprite.x += xValue;
	sprite.y += yValue;

}

/**
 * moveLeft - make sprite move left perpendecular to angle
 * @angle: the angle of sprite
 * @mov: the step of sprite
 * Return: Nothing (void function)
 */
void moveLeft(double *angle, int mov)
{
	pos current = calculatePosInArr();
	double xValue = 0;
	double yValue = 0;

	xValue = mov * cos((*angle - (PI / 2)));
	yValue = mov * sin((*angle - (PI / 2)));
	setAddedValueAfterColl(&xValue, &yValue, current);
	sprite.x += xValue;
	sprite.y += yValue;
}

/**
 * moveRight - make sprite move right perpendecular to angle
 * @angle: the angle of sprite
 * @mov: the step of sprite
 * Return: Nothing (void function)
 */
void moveRight(double *angle, int mov)
{

	pos current = calculatePosInArr();
	double xValue = 0;
	double yValue = 0;

	xValue = mov * (cos(*angle + (PI / 2)));
	yValue = mov * (sin(*angle + (PI / 2)));
	setAddedValueAfterColl(&xValue, &yValue, current);
	sprite.x += xValue;
	sprite.y += yValue;
}
