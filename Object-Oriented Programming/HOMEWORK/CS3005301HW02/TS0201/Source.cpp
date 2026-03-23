#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float Standard(float data[]);

int i = 0;
float j = 0, sum = 0;

int main()
{
	float data[100];
	double ava = 0;

	while (cin >> j)
	{
		for (i = 0; i < j; i++)
		{
			cin >> data[i];
			sum += data[i];
		}
		ava = sum / j;

		cout << "Average:" << ava << '\t' << "Standard deviation:" << Standard(data) << endl;

		sum = 0;
		ava = 0;
		for (i = 0; i < j; i++)
		{
			data[i] = 0;
		}
	}
}

float Standard(float data[])
{
	float sum = 0, ava = 0, Standard_deviation = 0;

	for (i = 0; i < j; i++)
	{
		sum += data[i];
	}

	ava = sum / j;

	for (i = 0; i < j; i++)
	{
		Standard_deviation += pow(data[i] - ava, 2);
	}
	return sqrt(Standard_deviation / j);
}