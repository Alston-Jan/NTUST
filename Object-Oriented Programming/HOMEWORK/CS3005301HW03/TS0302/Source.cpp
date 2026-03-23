#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	fstream  file,out;
	file.open("grade.txt", ios::in);
	out.open("grades.Output", ios::out);

	int input, grade[6] = { 0 };

	while (file >> input)
	{
		grade[input]++;
	}
	for (int i = 0; i < 6; i++)
	{
		out << grade[i] << " grade(s) of " << i << endl;
	}
}