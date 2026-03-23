#include <stdio.h>

int lcm(int a,int b)
{
	int ansA,ansB;
	for(int i=1;i<=b;i++)
	{
		ansA=a*i;
		for(int j=1;j<=a;j++)
		{
			ansB=b*j;
			if(ansA==ansB)
			{
				return ansB;
			}
		}
	}
}

int main()
{
	int a,b;
	
	scanf("%d%d",&a,&b);
	
	printf("%d",lcm(a,b));
}
