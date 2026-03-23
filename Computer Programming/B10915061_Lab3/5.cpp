#include <stdio.h>

int main()
{
	int count=100,a,b,c,num;
	while(count<1000)
	{
		a=count/100;
		c=count%10;
		b=(count-a*100)/10;
		
		num=a*a*a+b*b*b+c*c*c;
		
		if(num==count)
		{
			printf("%d\n",count);
		}
		
		count+=1;
	}
}
