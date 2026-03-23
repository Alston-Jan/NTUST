#include <stdio.h>

int main()
{
	float he,we,bmi;
	
	printf("Enter your weight and height: ");
	scanf("%f %f",&we,&he);
	
	bmi=we/(he*he);
	
	if(bmi<18.5)
	{
		printf("Underweight");
	}
	else if(bmi>=18.5 && bmi<=24.9)
	{
		printf("Normal");
	}
	else if(bmi>=25 && bmi<=29.9)
	{
		printf("Overweight");
	}
	else if(bmi>=30)
	{
		printf("Obese");
	}
}
