#include <stdio.h>

int main()
{
	double distance,miles,price,cost;
	printf("Enter the driving distance:");
	scanf("%lf",&distance);
	printf("Enter miles per gallon:");
	scanf("%lf",&miles);
	printf("Enter price per gallon:");
	scanf("%lf",&price);
	
	cost=(distance/miles)*price;
	
	printf("The cost of driving is $");
	printf("%.2f",cost);
}
