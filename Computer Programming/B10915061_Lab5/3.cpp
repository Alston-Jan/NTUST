#include<stdio.h>

int main()
{
	int num;
	
	printf("Enter the number of lines: ");
	scanf("%d",&num);
	
	for(int i=num;i>0;i--)
	{
		for(int j=i;j>0;j--)
		{
			printf("%d ",j);
		}
		for(int k=2;k<=i;k++)
		{
			printf("%d ",k);
		}
		printf("\n");
	}
}
