#include <stdio.h>

int main()
{
	int a,b,c;
	printf("Input three number : ");
	scanf("%d%d%d",&a,&b,&c);
	
	if(a>=b+c||b>=a+c||c>=a+b)
	{
		printf("False");
	}
	else
	{
		printf("Ture");
	}
}
