#include <stdio.h>

int main()
{
	int a,b,c,d,num;
	
	printf("Input : ");
	scanf("%d",&num);
	
	a=num/1000;
	b=(num-a*1000)/100;
	c=(num%100)/10;
	d=num%10;
	
	a=(a+7)%10;
	b=(b+7)%10;
	c=(c+7)%10;
	d=(d+7)%10;
	
	printf("%d%d%d%d",c,d,a,b);
}
