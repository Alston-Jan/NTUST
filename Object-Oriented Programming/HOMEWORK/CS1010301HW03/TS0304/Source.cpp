#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double k = 0;
	unsigned int year = 0, bit = 0, i = 1;

	while (cin >> year)
	{
		year = ((year - 1900) / 10) + 2;
		bit = pow(2, year);

		while (k < bit)
		{
			k = k + (log(i) / log(2));
			i++;
		}
		cout << i-2 << endl;
		i = 1,k = 0;
	}

}