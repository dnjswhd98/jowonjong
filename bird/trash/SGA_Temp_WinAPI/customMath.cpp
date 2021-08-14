#include "setDefine.h"
#include "customMath.h"

float Util::getDistance(float startX, float startY, float endX, float endY)
{
	float x = endX - startX;
	float y = endY - startY;

	return sqrtf(x * x + y * y);
}

float Util::getAngle(float startX, float startY, float endX, float endY)
{
	float x = endX - startX;
	float y = endY - startY;
	float distance = sqrtf(x *x + y * y);
	float angle = acos(x / distance);

	if (endY > startY)
	{
		angle = PI2 - angle;
	}

	return angle;
}
