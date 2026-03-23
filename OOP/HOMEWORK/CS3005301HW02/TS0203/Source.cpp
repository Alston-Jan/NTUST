#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
	string input = "";

	while (cin >> input)
	{
		int size = 0;
		for (size = 0; pow(size, 2) < input.length(); size++) {}
		for (int j = 0; j < size; j++)
		{
			for (int i = j;i < input.length(); i += size)
			{
				cout << input[i];
			}
			cout << endl;
		}
	}

	return 0;
}