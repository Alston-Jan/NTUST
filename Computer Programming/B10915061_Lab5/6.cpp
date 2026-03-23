#include<stdio.h>
#include<math.h>

int main()
{
	int num,first=0,secand,i;
	
	printf("Enter numbers: ");
	while(scanf("%d",&num)!=EOF)
	{
		if(num==0)
		{
			break;
		}
		secand=num;
		if(secand>first)
		{
			first=secand;
			i=0;
		}
		if(secand==first)
		{
			i++;
		}
	}
	
	printf("The largest number is %d\n",first);
	printf("The occurrence count of the largest number is %d",i);
}
