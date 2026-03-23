#include <iostream>

using namespace std;

int main()
{
	int count = 1, in, ele = 1;
	cout << count << ' ' << ele << endl;
	count++;
	while (cin >> in)
	{
		if(in>ele)
			for (int i = ele; i <= in; i++)
			{
				cout << count;
				count++;
				cout << ' ' << i << endl;
			}
		else
			for (int i = ele; i >= in; i--)
			{
				cout << count;
				count++;
				cout << ' ' << i << endl;
			}
		ele = in;
	}
}