#include <stdio.h>

int main()
{
	int in,out,a,b,c,d,e;
	
	printf("Input: ");
	scanf("%d",&in);
	
	a=in/10000;
	b=(in-a*10000)/1000;
	c=((in-a*10000)-b*1000)/100;
	e=in%10;
	d=((in%100)-e)/10;
	
	out=a+b+c+d+e;
	
	printf("Output: The sum of the digits is %d",out);
}
