#include <stdio.h>

int main()
{
	int num=0,b;
	
	scanf("%d",&num);
	
	while(num!=0)
	{
		b=num%10;
		printf("%d\n",b);
		num/=10;
	}
}
