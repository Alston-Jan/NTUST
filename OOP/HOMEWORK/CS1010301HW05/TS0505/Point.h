#ifndef Point_H
#define Point_H
#include <iostream>
using namespace std;

class Point
{
private:
	float vertical;
	float horizontal;

public:
	Point()
	{
		vertical = 0;
		horizontal = 0;
	}

	void Set(float vertical, float horizontal);
	void Move(float x, float y);
	void Rotate();
	void Reflect();
	float GetVertical() const { return horizontal; }
	float GetHorizontal() const { return vertical; }
};

#endif //Point_H