#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double a, b;

	while (cin >> a)
	{
		b = 4.0 / 3.0 * a * a * a * M_PI;
		cout << fixed << setprecision(6) << b << endl;
		a = 0;
	}
}