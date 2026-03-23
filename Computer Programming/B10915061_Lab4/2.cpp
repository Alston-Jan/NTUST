#include <stdio.h>

int main()
{
	for(int j=4;j>=0;j--)
	{
		int a=0;
		scanf("%d",&a);
		if(a>30||a<1)
		{
			printf("Error");
			break;
		}
		for(int i=a;i>=0;i--)
		{
			printf("*");
		}
		printf("\n");
	}
}
