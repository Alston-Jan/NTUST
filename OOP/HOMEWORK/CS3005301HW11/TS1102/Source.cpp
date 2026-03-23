#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a = 0, b = 0;
	int c = 0, d = 0;
	int mat1[20][20] = { 0 };
	int mat2[20][20] = { 0 };
	int ans[20][20] = { 0 };
	while (cin >> a >> b >> c >> d)
	{
		if (b != c)  //column a not equal to row b
		{
			cout << "Matrix multiplication failed." << endl;
			break;
		}
		else
		{
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < b; j++)
				{
					cin >> mat1[i][j];
				}
			}
			for (int i = 0; i < c; i++)
			{
				for (int j = 0; j < d; j++)
				{
					cin >> mat2[i][j];
				}
			}
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < d; j++)
				{
					for (int k = 0; k < b; k++)
					{
						ans[i][j] += mat1[i][k] * mat2[k][j];
					}
				}
			}
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < d; j++)
				{
					if (j == d - 1)
					{
						cout << ans[i][j];
					}
					else
					{
						cout << ans[i][j] << " ";
					}
				}
				cout << '\n';
			}
		}
		mat1[20][20] = { 0 };
		mat2[20][20] = { 0 };
		ans[20][20] = { 0 };
	}
	return 0;
}