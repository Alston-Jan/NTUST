#include <stdio.h>

int main()
{
	float time,per,mon;
	
	printf("Enter # of hours worked (-1 to end): ");
	scanf("%f",&time);
	
	while(time!=-1)
	{
		printf("Enter hourly rate of the worker ($00.00): ");
		scanf("%f",&per);
		
		if(time<=40)
		{
			mon=time*per;
		}
		else
		{
			time-=40;
			mon=40*per+time*per*1.5;
		}
		
		printf("Salary is $%.2f\n",mon);
		
		printf("Enter # of hours worked (-1 to end): ");
		scanf("%f",&time);
	}
}
