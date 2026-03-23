#include <stdio.h>
#include <math.h>

int function (int a)
{
	int ans=0;
	ans=pow(2,a)-1;
	return ans;
}

int main()
{
	printf("%2s%16s\n","p","2^p-1");
	for(int a=2;a<=31;a++)
	{
	int i=0;
		for(int j=2;j<sqrt(function (a))+1;j++)
		{
			if(function (a)%j==0)
			{
				i++;
				break;
			}
		}
		if(i==0)
		{
			printf("%2d,%15d\n",a,function (a));
		}
	}
}
