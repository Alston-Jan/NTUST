#include <stdio.h>

int main()
{
	double kilograms,initial,final,cost;
	printf("Enter the amount of water in kilograms:");
	scanf("%lf",&kilograms);
	printf("Enter the initial temperature:");
	scanf("%lf",&initial);
	printf("Enter the final temperature:");
	scanf("%lf",&final);
	
	cost=kilograms*(final-initial)*4184;
	
	printf("The energy needed is %.1f",cost);
	
}
