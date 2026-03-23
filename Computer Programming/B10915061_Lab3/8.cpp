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
	
	if(a==7||a==8||a==9)
	{
		a-=7;
	}
	else
	{
		a=a+10-7;
	}
	
	if(b==7||b==8||b==9)
	{
		b-=7;
	}
	else
	{
		b=b+10-7;
	}
	
	if(c==7||c==8||c==9)
	{
		c-=7;
	}
	else
	{
		c=c+10-7;
	}
	
	if(d==7||d==8||d==9)
	{
		d-=7;
	}
	else
	{
		d=d+10-7;
	}
	
	printf("%d%d%d%d",c,d,a,b);
}
