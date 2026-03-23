#include <iostream>
#include <cmath>

using namespace std;

int row(int data[][9])
{
	for (int i = 0; i < 9; i++)
	{
		int adder = 0;
		for (int j = 0; j < 9; j++)
		{
			adder += pow(2,data[i][j]-1);
		}
		if (adder != 511)
			return 0;
	}
	return 1;
}

int column(int data[][9])
{
	for (int i = 0; i < 9; i++)
	{
		int adder = 0;
		for (int j = 0; j < 9; j++)
		{
			adder += pow(2,data[j][i]-1);
		}
		if (adder != 511)
			return 0;
	}
	return 1;
}

int block(int data[][9])
{
	int x = 0, y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			int adder = 0;
			for (int i = y; i < y + 3; i++)
			{
				for (int j = x; j < x + 3; j++)
				{
					adder += pow(2,data[i][j]-1);
				}
			}
			if (adder != 511)
				return 0;
			x += 3;
		}
		y += 3;
	}
	return 1;
}

int main()
{
	int data[9][9] = { 0 };

	while (cin >> data[0][0])
	{
		int x = 1;
		char a;
		cin >> a;
		for (int i = 0; i < 9; i++)
		{
			for (int j = x; j < 8; j++)
			{
				cin >> data[i][j];
				char a;
				cin >> a;
			}
			x = 0;
			cin >> data[i][8];
		}

		if (row(data))
		{
			if (column(data))
			{
				if (block(data))
				{
					cout << "True" << endl;
				}
				else
					cout << "False" << endl;
			}
			else
				cout << "False" << endl;
		}
		else
			cout << "False" << endl;
	}
}