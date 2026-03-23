#include <stdio.h>

unsigned long long int fibonacci(unsigned int n)
{
	unsigned long long int a=1 ,b=0 ,ans; //a=n-1 b=n-2
	
	if(n>2)
	{
		for(int i=3;i<=n;i++)
		{
			ans=a+b;
			b=a;
			a=ans;
		}
		return ans;
	}
	else if(n==2)
	{
		return 1;
	}
	else if(n==1)
	{
		return 0;
	}
}

int main()
{
	unsigned int n;
	
	scanf("%u",&n);
	
	printf("%llu\n",fibonacci(n));
	printf("\n");
	
	for(n=90;n<=95;n++)
	{
		printf("%u%25llu\n",n,fibonacci(n));	
	}
	
	printf("The largest Fibonacci number is ");
	printf("%llu\n",fibonacci(94));
}
