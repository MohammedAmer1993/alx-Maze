#include "raycasting.h"


double calculateDistance(double angle)
{
	double lengthForInitialX = 0;
	double lengthForInitialY = 0;
	point initialState = getInitialState(angle);

	lengthForInitialX = initialState.x / cos(angle);
	lengthForInitialY = initialState.y / sin(angle);

	printf("first coll %f  sec coll %f\n", lengthForInitialX, lengthForInitialY);
	return (0);
}
