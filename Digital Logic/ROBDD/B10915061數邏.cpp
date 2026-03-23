#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm>
using namespace std;

struct Node
{
	char Variable;
	int high, low;	//1 and 0 to go.
	bool isRedundant;
};

void ROBDD(ifstream&);
void Show(string, Node*, int);
void Redundant(Node*, int);
void Save(string, Node*, int);

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ifstream fin(argv[1]);
		if (!fin)
		{
			cout << "file error!" << endl;
			return -1;
		}
		else
		{
			ROBDD(fin);
		}
	}
	else
	{
		cout << "parameter error!" << endl;
		return -1;
	}
	return 0;
}

void Show(string name,Node* n,int size)
{
	cout << "digraph " << name << " {" << endl;
	cout << "\t0 [label=\"0\", shape=box];" << endl;
	for (int i = 1; i < size; i++)
	{
		if(!n[i].isRedundant)
		printf("\t%d [label=\"%c\"];\n",i,n[i].Variable);
	}
	printf("\t%d [label=\"1\", shape=box];\n", size);
	cout << endl;
	for (int i = 1; i < size; i++)
	{
		if (!n[i].isRedundant)
		{
			printf("\t%d -> %d [label=\"0\", style=dotted]\n", i, n[i].high);
			printf("\t%d -> %d [label=\"1\", style=solid]\n", i, n[i].low);
		}
	}
	cout << "}" << endl;
}

void Redundant(Node* n, int size)
{
	bool f = false;
	for (int i = 1; i < size; i++)
	{
		if (n[i].isRedundant) continue;
		if (n[i].high == n[i].low)
		{
			n[i].isRedundant = true;
			f = true;
			for (int j = 1; j < size; j++)
			{
				if (n[j].high == i)
					{
						n[j].high = n[i].high;
					}
				if (n[j].low == i)
					{
						n[j].low = n[i].high;
					}
			}
		}
	}
	for (int i = 1; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (n[i].isRedundant)continue;
			if (n[j].isRedundant)continue;

			if (n[i].high == n[j].high && n[i].low == n[j].low && n[i].Variable == n[j].Variable)
			{
				n[j].isRedundant = true;
				f = true;
				for (int k = 1; k < size; k++)
				{
					if (n[k].high == j)
					{
						n[k].high = i;
					}
					if (n[k].low == j)
					{
						n[k].low = i;
					}
				}
			}
		}
	}
	if (f)
	{
		Redundant(n, size);
	}
}

void Save(string fileName,Node *n, int size)
{
	ofstream fout(fileName, ofstream::out);
	fout << "digraph " << fileName << " {" << endl;
	fout << "\t0 [label=\"0\", shape=box];" << endl;
	for (int i = 1; i < size; i++)
	{
		if (!n[i].isRedundant)
		{
			fout << "\t" << i << " [label=\"" << n[i].Variable << "\"];\n";
		}
	}
	fout << "\t" << size << " [label=\"1\", shape=box];\n";
	fout << endl;
	for (int i = 1; i < size; i++)
	{
		if (!n[i].isRedundant)
		{
			fout << "\t" << i << " -> " << n[i].high << " [label=\"0\", style=dotted]\n";
			fout << "\t" << i << " -> " << n[i].low << " [label=\"1\", style=solid]\n";
		}
	}
	fout << "}";

	fout.close();
}

void ROBDD(ifstream& f)
{
	string str;
	Node *n = NULL;
	int input = 0, output = 0;
	char *ilb = NULL;
	char *ob = NULL;
	while (!f.eof())
	{
		f >> str;
		if (str == ".i")
		{
			f >> input;
			n = new Node[(int)pow(2, input) + 1];
			for (int i = 0; i < (int)pow(2, input) + 1; i++)
			{
				n[i].isRedundant = false;
			}
			ilb = new char[input];
			for (int i = 1; i < pow(2,input-1); i++)
			{
				n[i].high = i * 2;
				n[i].low = i * 2 + 1;
			}
			for (int i = (int)pow(2, input - 1); i < (int)pow(2, input); i++)
			{
				n[i].high = 0;
				n[i].low = 0;
			}
			n[0].Variable = '0';
			n[(int)pow(2, input)].Variable = '1';
		}
		else if (str == ".o")
		{
			f >> output;
			ob = new char[output];
		}
		else if (str == ".ilb")
		{
			for (int i = 0; i < input; i++)
			{
				f >> ilb[i];
			}
			for (int i = 1; i < pow(2, input); i++)
			{
				n[i].Variable = ilb[(int)log2(i)];
			}
		}
		else if (str == ".ob")
		{
			for (int i = 0; i < output; i++)
			{
				f >> ob[i];
			}
		}
		else if (str == ".p")
		{
			int temp;
			bool *bit = new bool[(int)pow(2,input)];
			
			f >> temp;
			for (int i = 0; i < temp; i++)
			{
				string temp;
				f >> temp;
				reverse(temp.begin(), temp.end());
				for (int i = 0; i < pow(2, input); i++)
				{
					bit[i] = false;
				}
				for (int j = 0; j < (int)temp.length(); j++)
				{
					if (temp[j] == '1')
						{
							bit[j * 2+1] = true;
						}
					else if (temp[j] == '0')
					{
						bit[j * 2] = true;
					}
					else
					{
						bit[j * 2] = true;
						bit[j * 2 + 1] = true;
					}
				}
				f >> temp;
				for (int i = (int)pow(2,input-1); i < (int)pow(2, input); i++)
				{
					bool f=true;
					int temp = i * 2 - (int)pow(2, input);
					for (int j = 0; j < input; j++)
					{
						if (bit[temp % 2 + j * 2] == false)
							
								f = false;
						        temp /= 2;
					}
					if (n[i].high == 0 && f == true)
					
						n[i].high = (int)pow(2, input);

					f = true;
					temp = i * 2 + 1 - (int)pow(2, input);
					for (int j = 0; j < input; j++)
					{
						if (bit[temp % 2 + j * 2] == false)
							f = false;
						temp /= 2;
					}
					if (n[i].low == 0 && f == true)
						n[i].low = (int)pow(2, input);
				}
			}
		}
		else if (str == ".e")
		{
			Show("OBDD", n, (int)pow(2, input));
			Save("obdd", n, (int)pow(2, input));
			
			Redundant(n, (int)pow(2, input));
			
			Show("ROBDD",n, (int)pow(2, input));
			Save("robdd", n, (int)pow(2, input));
			break;
		}
	}
}
