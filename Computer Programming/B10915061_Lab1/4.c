#include <stdio.h>

int main()
{
	int n1,n2,ans;
	
	printf("enter two numbers\n");
	scanf("%d %d",&n1,&n2);
	
	ans=n1%n2;
	
	if(ans==0)
	{
		printf("The first is a multiple of the second");
	}
	else
	{
		printf("The first is not a multiple of the second");
	}
	
}
