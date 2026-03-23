#include <iostream>	
#include <vector>

using namespace std;

int main()
{
	int ar, am, br, bm;

	while (cin >> ar >> am >> br >> bm)
	{
		vector<int>A, B;

		for (int i = 0; i < ar; i++)
		{
			for (int j = 0; j < am; j++)
			{
				int tamp;
				cin >> tamp;
				A.push_back(tamp);
			}
		}

	}
}