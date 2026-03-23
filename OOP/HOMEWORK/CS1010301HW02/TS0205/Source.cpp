#include<iostream>
#include<string>
using namespace std;

string Add(string, string);
bool AllisNum(string);

int main()
{
	int number = 0;
	string str1, str2;
	while (cin >> number)
	{
		for (int i = 0; i < number; i++)
		{
			cin >> str1;
			cin >> str2;
			string num = Add(str1, str2);

			if (AllisNum(str1) && AllisNum(str2))
			{
				cout << Add(str1, str2) << endl;
			}
			else
			{
				cout << "Not a valid number, please try again." << endl;
			}
		}
	}
}

string Add(string num1, string num2)
{
	int a = 0, b = 0, carry = 0, sum = 0;


	if (num1.size() < num2.size())
	{
		string temp = num1;
		num1 = num2;
		num2 = temp;
	}
	int length1 = num1.size(), length2 = num2.size();

	while (length1 > 0)
	{
		a = num1[length1 - 1] - '0'; 
		if (length2 > 0)
		{
			b = num2[length2 - 1] - '0'; 
		}
		else
		{
			b = 0;
		}

		sum = a + b + carry;

		if (sum >= 10) 
		{
			num1[length1 - 1] = '0' + sum % 10;
			carry = 1;
		}
		else
		{
			num1[length1 - 1] = '0' + sum;
			carry = 0;
		}
		length1--;
		length2--;
	}
	if (carry == 1)
	{
		num1 = "1" + num1;
	}
	return num1;
}
bool AllisNum(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		int temp;
		temp = (int)str[i];
		if (temp >= '0' && temp <= '9')
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}