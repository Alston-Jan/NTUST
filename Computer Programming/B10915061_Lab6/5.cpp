#include<stdio.h>

int reverse(int number)
{
	int ans=0;
	while(number!=0)
	{
		ans=ans*10+number%10;
		number/=10;
	} 
	return ans;
}

int main()
{
	int number;
	
	scanf("%d",&number);
	
	printf("%d",reverse(number));
}
