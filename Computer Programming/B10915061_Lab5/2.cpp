#include<stdio.h>
#include<math.h>

int main()
{
	int num,num1;
	
	scanf("%d",&num);
	
	num1=num;
	
	for(int i=2;i<num;i++)
	{
		while(num1%i==0)
		{
			printf("%d ",i);
			num1/=i;
		}
	}
}
