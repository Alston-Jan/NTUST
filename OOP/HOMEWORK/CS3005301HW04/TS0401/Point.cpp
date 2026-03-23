#include "Point.h"

void Point::Set(int vertical, int horizontal)
{
	Point::vertical = vertical;
	Point::horizontal = horizontal;
}

void Point::Move(int x, int y)
{
	vertical += x;
	horizontal += y;
}
void Point::Rotate()
{
	int tamp;
	tamp = vertical;
	vertical = horizontal;
	horizontal = -tamp;
}
