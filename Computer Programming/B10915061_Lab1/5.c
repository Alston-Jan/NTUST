#include <stdio.h>

int main()
{
	double spe,acc,length;
	printf("Enter speed and acceleration:");
	scanf("%lf %lf",&spe,&acc);
	
	length=spe*spe/(2*acc);
	
	printf("The minimum runway length for this airplane is ");
	printf("%.3f",length);
	printf(" meters.");
}
