#include<iostream>
#include<fstream>
#include<vector>
#include"NumberGame.h"
using namespace std;
int i = 0, j = 0, x = 0, y = 0, z = 0;
void NumberGame::SetInput(int a)
{
	num = a;
}
void NumberGame::ProcessInput()
{
	while (num / 10 != 0)
	{
		if (num % 10 != 0)
		{
			num1[j] = num % 10;
			num /= 10;
			j++;
		}
		else
			num /= 10;
	}
	num1[j] = num;
	j++;
}
void NumberGame::SetFileName(string t)
{

	file = t;
}
void NumberGame::LoadNumberList()
{
	int x;
	fstream file1;
	file1.open(file, ios::in);
	if (!file1.is_open()) {
		cout << "don't";
	}
	while (file1 >> x)
	{
		num2.push_back(x);
	}

}
void NumberGame::PrintAllValid()
{
	int k, l;
	int n;
	int n1, n2, n3;
	for (n1 = 0; n1 < j; n1++)
	{
		if (num1[n1] == 2)
			x = 1;
		if (num1[n1] == 3)
			y = 1;
		if (num1[n1] == 4)
			z = 1;
	}
	if (x == 1)
	{
		for (n1 = 0; n1 < j; n1++)
		{
			if (num1[n1] == 4)
			{
				num1[n1] = 2;
				num1[j] = 2;
				j++;
			}
		}
	}
	if (y == 1)
	{
		for (n1 = 0; n1 < j; n1++)
		{
			if (num1[n1] == 9)
			{
				num1[n1] = 3;
				num1[j] = 3;
				j++;
			}
		}

	}
	if (z == 1)
	{
		for (n1 = 0; n1 < j; n1++)
		{
			if (num1[n1] == 8)
			{
				num1[n1] = 2;
				num1[j] = 2;
				num1[j + 1] = 2;
				j += 2;
			}
		}

	}
	for (n1 = 0; n1 < j; n1++)
	{
		for (n2 = n1 + 1; n2 < j; n2++)
		{
			if (num1[n1] < num1[n2])
			{
				n3 = num1[n1];
				num1[n1] = num1[n2];
				num1[n2] = n3;
			}
		}
	}
	for (k = 0; k < num2.size(); k++)
	{
		n = num2[k];

		for (l = 0; l < j; l++)
		{

			if (n % num1[l] == 0)
			{
				n /= num1[l];
				if (n == 1)
				{
					cout << num2[k] << endl;
					break;
				}

			}
		}

	}
}
void NumberGame::Reset()
{
	j = 0;
	x = 0;
	y = 0;
	z = 0;
	num2.clear();
};