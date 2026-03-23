#include <stdio.h>

int solution (int a,int b,int c)
{
	if(a*a==(b*b+c*c)||b*b==(a*a+c*c)||c*c==(a*a+b*b))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int a,b,c;
	
	printf("Enter a set of integers : ");
	scanf("%d %d %d",&a,&b,&c);
	
	if(solution(a,b,c)==1)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
 } 
