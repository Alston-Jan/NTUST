#include<iostream>
#include<vector>
using namespace std;
class NumberGame {
public:

	void SetInput(int a);
	void ProcessInput();
	void SetFileName(string t);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
private:
	int num, num1[32];
	vector<int> num2;
	string file;

};
