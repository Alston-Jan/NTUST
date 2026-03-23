#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double a,b;
	int len, dot;
	char letter;

	while (cin >> a)
	{
		cin >> len >> dot >> letter;

		if (a > 0)
		{
			b = a * pow(10, dot);
			b = floor(b);
			a = b / pow(10, dot);
		}
		else
		{
			b = a * pow(10, dot);
			b = ceil(b);
			a = b / pow(10, dot);
		}
		
		cout << fixed << setw(len) << setfill(letter) << setprecision(dot) <<  a  << endl;

		len = 0, dot = 0, a = 0.0;
	}
}