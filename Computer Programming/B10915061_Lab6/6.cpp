#include <stdio.h>
#include <math.h>

double function(double x)
{
	double y=1,ave=(y+x/y)/2;
	
	while(fabs(y-x/y)>0.00001*y)
	{
		ave=(y+x/y)/2;
		y=ave;
	}
	return y;
}

int main()
{
	double x;
	printf("Enter a positive number: ");
	scanf("%lf",&x);
	printf("Square root: ");
	printf("%lf",function(x));
}
