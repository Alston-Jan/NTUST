#include <iostream>

using namespace std;

int main()
{
	int i, j;
	while (cin >> i >> j)
	{
		cout << i << " " << j << " ";
		int tamp;
		if (i > j)
		{
			tamp = i;
			i = j;
			j = tamp;
		}
		int count = 0, top = 0;;
		for (int a = i; a <= j; a++)
		{
			tamp = a;
			while (tamp != 1)
			{
				if (tamp % 2)
				{
					tamp = tamp * 3 + 1;
				}
				else
				{
					tamp /= 2;
				}
				count++;
			}
			count++;
			if (count > top)
			{
				top = count;
			}
			count = 0;
		}
		cout << top << endl;
	}
}