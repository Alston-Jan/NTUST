#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream  file;
	file.open("scores.txt", ios::in);

	string name[100] ;
	int sco[100] = { 0 }, i = 0, top = 0, sce = 0, thi = 0, n[3] = { 0 };

	while (file >> name[i])
	{
		file >> sco[i];
		if (sco[i] > top)
		{
			top = sco[i];
			n[0] = i;
		}
		i++;
	}
	for (int j = 0; j < i + 1; j++)
	{
		if (sco[j] > sce && sco[j] < top)
		{
			sce = sco[j];
			n[1] = j;
		}
	}
	for (int j = 0; j < i + 1; j++)
	{
		if (sco[j] > thi && sco[j] < sce)
		{
			thi = sco[j];
			n[2] = j;
		}
	}
	
	for (int j = 0; j < 3; j++)
	{
		cout << name[n[j]] << endl << sco[n[j]] << endl;
	}
}