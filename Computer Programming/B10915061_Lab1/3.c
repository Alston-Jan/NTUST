#include <stdio.h>

int main()
{
	int num,ans;
	
	printf("enter a number\n");
	scanf("%d",&num);
	
	ans=num%2;
	
	if(ans==1)
	{
		printf("This number is Odd.");
	}
	else
	{
		printf("This number is Even.");
	}
}
