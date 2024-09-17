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


void moveForward(double* angle, int mov)
{
	if (*angle >= 0 && *angle < (PI / 2))
	{
		sprite.x += (mov * cos((*angle)));
		sprite.y += (mov * sin((*angle)));	
	}
	else if ((*angle) >= (PI / 2) && (*angle) < PI)
	{
		sprite.x -= (mov * cos(PI - (*angle)));    
		sprite.y += (mov * sin(PI - (*angle)));
	}
	else if ((*angle) >= PI && (*angle) < ((3 * PI) / 2))
	{
		sprite.x -= (mov * sin(((3 * PI) / 2) - (*angle)));
		sprite.y -= (mov * cos(((3 * PI) / 2) - (*angle)));	
	}
	else if ((*angle) >= 0 && (*angle) < (2 * PI))
	{
		sprite.x += (mov * cos(2 * PI - (*angle)));
		sprite.y -= (mov * sin(2 * PI - (*angle)));	
	}
}
// void moveBackward(double angel){}
// void moveLeft(double angel){}
// void moveRight(double angle){}
