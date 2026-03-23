#include <iostream>
#include <list>
using namespace std;

class StRec
{
public:
	string firstName;
	string lastName;
	string phone;

	bool operator==(const StRec& other) {
		if (firstName != other.firstName || lastName != other.lastName || phone != other.phone)
		{
			return false;
		}
		return true;
	}
};

int main() {
	string ISDP = "";
	list<StRec> StLIST;
	//bool modify = false;

	while (cin >> ISDP)
	{
		StRec st = { "" };

		if (ISDP == "print")
		{
			if (StLIST.empty())
			{
				cout << "Print Error\n";
			}
			else
			{
				list<StRec>::iterator j;
				for (j = StLIST.begin(); j != StLIST.end(); ++j) {
					StRec out = *j;
					cout << out.firstName << " " << out.lastName << " " << out.phone << endl;
				}
			}
		}
		else
		{
			cin >> st.firstName >> st.lastName >> st.phone;

			if (st.firstName.length() < 25 && st.lastName.length() < 30 && st.phone.length() < 15)
			{
				if (ISDP == "insert")
				{
					if (StLIST.size() < 10)
					{
						list<StRec>::iterator j;
						bool i = false;
						for (j = StLIST.begin(); j != StLIST.end(); ++j) {
							if (st == *j)
							{
								i = true;
								break;
							}
						}

						if (i)
						{
							cout << "Insert Error\n";
						}
						else
						{
							StLIST.push_back(st);
							//modify = true;
						}
					}
					else
					{
						cout << "Insert Error\n";
					}
				}
				else if (ISDP == "search")
				{
					list<StRec>::iterator j;
					bool s = false;

					int i = 0;
					for (j = StLIST.begin(); j != StLIST.end(); ++j) {
						if (st == *j)
						{
							cout << i << endl;
							s = true;
							//modify = true;
							break;
						}
						i++;
					}
					if (!s)
					{
						cout << "Search Error\n";
					}
				}
				else if (ISDP == "delete")
				{
					list<StRec>::iterator j;
					bool d = false;

					for (j = StLIST.begin(); j != StLIST.end(); ++j) {
						if (st == *j)
						{
							StLIST.erase(j);
							d = true;
							//modify = true;
							break;
						}
					}
					if (!d)
					{
						cout << "Delete Error\n";
					}
				}
				else
				{
					cout << "Input Error\n";
				}
			}
			else
			{
				cout << "Input Error\n";
			}
		}
	}

	return 0;
}