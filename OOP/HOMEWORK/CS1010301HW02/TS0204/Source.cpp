#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	vector<string> name(100);
	int count;
	vector<string> Salary(100), Award(100);

	while (cin >> count)
	{
		int longest[3] = { 0 };
		for (int i = 0; i < count; i++)
		{
			cin >> name[i] >> Salary[i] >> Award[i];
			if (name[i].size() > longest[0])
			{
				longest[0] = name[i].size();
			}
			if (Salary[i].size() > longest[1])
			{
				longest[1] = Salary[i].size();
			}
			if (Award[i].size() > longest[2])
			{
				longest[2] = Award[i].size();
			}
		}


		for (int i = 0; i < count; i++)
		{
			cout << right << setw(longest[0]) << fixed << name[i] << "|  " 
				<< right << setw(longest[1]) << fixed << Salary[i] << "|  "
				<< right << setw(longest[2]) << fixed << Award[i] << endl;
		}
	}
}