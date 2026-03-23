#include "Point.h"

void Point::Set(float vertical, float horizontal)
{
	Point::vertical = vertical;
	Point::horizontal = horizontal;
}

void Point::Move(float x, float y)
{
	vertical += x;
	horizontal += y;
}
void Point::Rotate()
{
	float tamp;
	tamp = vertical;
	vertical = horizontal;
	if(horizontal != 0)
		horizontal = -tamp;
}

void Point::Reflect()
{
	if(vertical != 0)
		vertical = -vertical;

	if (horizontal != 0)
		horizontal = -horizontal;
}

