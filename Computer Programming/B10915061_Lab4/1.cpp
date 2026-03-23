#include <stdio.h>

int main()
{
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=i;j++)
		{
			printf("%s", "*");
		}
		
		printf("\n");
	}
	printf("\n");
	
	for(int i=0;i<=9;i++)
	{
		for(int j=9;j>=i;j--)
		{
			printf("%s", "*");
		}
		
		printf("\n");
	}
	printf("\n");
	
	for(int i=0;i<=9;i++)
	{
		for(int k=0;k<i;k++)
		{
			printf("%s", " ");	
		}
		for(int j=9;j>=i;j--)
		{
			printf("%s", "*");
		}
		
		printf("\n");
	}
	printf("\n");
	
	for(int i=0;i<=9;i++)
	{
		for(int k=0;k<i;k++)
		{
			printf("%s", "*");	
		}
		for(int j=9;j>=i;j--)
		{
			printf("%s", " ");
		}
		
		printf("\n");
	}
	printf("\n");
		
 } 
