#include <stdio.h>
#include <math.h>

int discriminant (float a,float b,float c)
{
	if(b*b-4*a*c>=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	float a,b,c,ans1,ans2;
	
	printf("Enter the coefficients X^2: ");
	scanf("%f",&a);
	printf("Enter the coefficients X: ");
	scanf("%f",&b);
	printf("Enter the coefficients integer: ");
	scanf("%f",&c);
	
	if(discriminant(a,b,c)==1)
	{
		ans1=(-b+sqrt(b*b-4*a*c))/2*a;
		ans2=(-b-sqrt(b*b-4*a*c))/2*a;
		printf("The equation has real roots.\n");
		printf("The roots of the equation is %f and %f",ans1,ans2);
	}
	else
	{
		printf("The equation has imaginary (or complex) roots.");
	}
}
