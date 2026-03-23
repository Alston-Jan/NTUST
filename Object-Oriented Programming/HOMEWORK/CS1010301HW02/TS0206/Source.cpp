#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int incom = 0;
	float rate = 0;
	while (cin >> incom)
	{
		if (incom <= 750)
		{
			rate = incom * 0.01;
		}
		else if (incom > 750 && incom <= 2250)
		{
			rate = 7.5 + (incom - 750) * 0.02;
		}
		else if (incom > 2250 && incom <= 3750)
		{
			rate = 37.5 + (incom - 2250) * 0.03;
		}
		else if (incom > 3750 && incom <= 5250)
		{
			rate = 82.5 + (incom - 3750) * 0.04;
		}
		else if (incom > 5250 && incom <= 7000)
		{
			rate = 142.5 + (incom - 5250) * 0.05;
		}
		else
		{
			rate = 230 + (incom - 7000) * 0.06;
		}

		cout << fixed << setprecision(2) << rate << endl;
		rate = 0;
	}
}