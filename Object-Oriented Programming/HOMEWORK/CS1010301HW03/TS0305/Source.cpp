#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void draw(int x, int y, char pictur[][1000])
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			pictur[i][j]='*';
		}
	}
}

void print(int x,int y,char pictur[][1000])
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << pictur[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int a = 0, b = 0;
	char pictur[1000][1000] = { 0 };
	string type;

	while (cin >> a >> b)
	{
		int wS = 0, xS = 0, yS = 0;
		int wT = 0, xT = 0, yT = 0;
		string side;
		int x1L = 0, x2L = 0, y1L = 0, y2L = 0, tamp = 0;
		draw(a, b, pictur);

		while (cin >> type)
		{
			switch (type[0])
			{
			case 'S':
				cin >> wS >> xS >> yS;
				for (int i = xS; i < xS + wS; i++)
				{
					for (int j = yS; j < yS + wS; j++)
					{
						pictur[j][i] = 'X';
					}
				}
				if (xS + wS > a || yS + wS > b)
				{
					cout << "Out of range." << endl;
					cout << endl;
					break;
				}
				else if (xS > a || yS > b)
				{
					cout << "Out of range." << endl;
					cout << endl;
					break;
				}
				else
				{
					print(a, b, pictur);
				}
				break;
			case 'T':
				cin >> wT >> xT >> yT >> side;
				wT -= 1;
				if (side == "LU")
				{
					if (xT - wT < 0 || yT - wT < 0)
					{
						cout << "Out of range." << endl;
						cout << endl;
						break;
					}
					for (int i = 0; i <= wT; i++)
					{
						pictur[yT][xT-i] = 'X';
						pictur[yT-i][xT] = 'X';
					}
					for (int i = xT - wT; i <= xT; i++)
					{
						for (int j = yT - wT; j <= yT; j++)
						{
							if (((yT - wT) - yT) * (i - (xT - wT)) == (j - yT) * (xT - (xT - wT)))
							{
								pictur[j][i] = 'X';
							}
						}
					}
				}
				else if (side == "LD")
				{
					if (yT + wT >= b || xT - wT < 0)
					{
						cout << "Out of range." << endl;
						cout << endl;
						break;
					}
					for (int i = 0; i <= wT; i++)
					{
						pictur[yT][xT - i] = 'X';
						pictur[yT + i][xT] = 'X';
					}
					for (int i = xT - wT; i <= xT; i++)
					{
						for (int j = yT; j <= yT + wT; j++)
						{
							if (((yT + wT) - yT) * (i - (xT - wT)) == (j - yT) * (xT - (xT - wT)))
							{
								pictur[j][i] = 'X';
							}
						}
					}
				}
				else if (side == "RU")
				{
					if (xT + wT >= a || yT - wT < 0)
					{
						cout << "Out of range." << endl;
						cout << endl;
						break;
					}
					for (int i = 0; i <= wT; i++)
					{
						pictur[yT][xT + i] = 'X';
						pictur[yT - i][xT] = 'X';
					}
					for (int i = xT; i <= xT + wT; i++)
					{
						for (int j = yT - wT; j <= yT; j++)
						{
							if (((yT - wT) - yT) * (i - (xT + wT)) == (j - yT) * (xT - (xT + wT)))
							{
								pictur[j][i] = 'X';
							}
						}
					}
				}
				else if (side == "RD")
				{
					if (xT + wT >= a || yT + wT >= b)
					{
						cout << "Out of range." << endl;
						cout << endl;
						break;
					}
					for (int i = 0; i <= wT; i++)
					{
						pictur[yT][xT + i] = 'X';
						pictur[yT + i][xT] = 'X';
					}
					for (int i = xT; i <= xT + wT; i++)
					{
						for (int j = yT; j <= yT + wT; j++)
						{
							if (((yT + wT) - yT) * (i - (xT + wT)) == (j - yT) * (xT - (xT + wT)))
							{
								pictur[j][i] = 'X';
							}
						}
					}
				}
				if (xT >= a || yT >= b)
				{
					cout << "Out of range." << endl;
					cout << endl;
					break;
				}
				else
				{
					print(a, b, pictur);
				}
				break;
			case 'L':
				cin >> x1L >> y1L >> x2L >> y2L;
				if (x1L >= x2L && y1L >= y2L)
				{
					for (int i = x2L; i <= x1L; i++)
					{
						for (int j = y2L; j <= y1L; j++)
						{
							if ((y1L - y2L) * (i - x2L) == (j - y2L) * (x1L - x2L))
							{
								pictur[j][i] = 'X';
							}
						}
					}
				}
				else if (x1L >= x2L && y2L >= y1L)
				{
					for (int i = x2L; i <= x1L; i++)
					{
						for (int j = y1L; j <= y2L; j++)
						{
							if ((y1L - y2L) * (i - x2L) == (j - y2L) * (x1L - x2L))
							{
								pictur[j][i] = 'X';
							}
						}
					}
				}
				else if (x2L >= x1L && y1L >= y2L)
				{
					for (int i = x1L; i <= x2L; i++)
					{
						for (int j = y2L; j <= y1L; j++)
						{
							if ((y1L - y2L) * (i - x2L) == (j - y2L) * (x1L - x2L))
							{
								pictur[j][i] = 'X';
							}
						}
					}
				}
				else if (x2L >= x1L && y2L >= y1L)
				{
					for (int i = x1L; i <= x2L; i++)
					{
						for (int j = y1L; j <= y2L; j++)
						{
							if ((y1L - y2L) * (i - x2L) == (j - y2L) * (x1L - x2L))
							{
								pictur[j][i] = 'X';
							}
						}
					}
				}
				if (x1L >= a || y1L >= b || x2L >= a || y2L >= b)
				{
					cout << "Out of range." << endl;
					cout << endl;
					break;
				}
				else
				{
					print(a, b, pictur);
				}
				break;
			case 'E':
				return 0;
				break;
			}
		}
	}
}