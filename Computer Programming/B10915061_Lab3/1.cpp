#include <stdio.h>

int main()
{
	float mon,pay;
	
	printf("Enter sales in dollars (-1 to end): ");
	scanf("%f",&mon);
	
	while(mon!=-1)
	{
		pay=mon*0.09+200;
		printf("Salary is: $%.2f\n",pay);
		
		printf("Enter sales in dollars (-1 to end): ");
		scanf("%f",&mon);
	}
 } 
