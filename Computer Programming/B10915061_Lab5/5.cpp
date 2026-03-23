#include<stdio.h>
#include<math.h>

int main()
{
	int count;
	
	for(int i=1;i<=7;i++)
	{
		for(int j=i+1;j<=7;j++)
		{
			printf("%d %d\n",i,j);
			count++;
		}
	}
	printf("The total number of all combinations is %d",count);
}
