#include<string>
#include <vector>
using namespace std;
class Form
{
private:
	string key;
	vector<int> keysum;
	string wordfile;
	vector<string> wl;
public:
	void SetInputWord(string inputWord); 
	void ProcessInputWord(); 
	void SetFileName(string fileName); 
	void Load_CompareWord(); 
	void PrintFoundWords();
};