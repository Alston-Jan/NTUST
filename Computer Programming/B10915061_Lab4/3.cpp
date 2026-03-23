#include <stdio.h>

int main()
{
	float totol=0,price,sold,a=0,b=0;
	int number;
	for(int i=0;i<5;i++)
	{
		printf("Enter the product number 1~5 (-1 to stop) : ");
		scanf("%d",&number);
		if(number==-1||number>5||number<1)
		{
			break;
		}
		
		printf("Enter the quantity sold for one day : ");
		for(int i=1;i<=7;i++){
		scanf("%f",&sold);
		a+=sold;
		}
	
		switch(number)
		{
		case 1:
			price=0;
			price=2.98*a;
			b+=price;
			break;
			
		case 2:
			price=0;
			price=4.50*a;
			b+=price;
			break;
			
		case 3:
			price=0;
			price=9.98*a;
			b+=price;
			break;
		
		case 4:
			price=0;
			price=4.49*a;
			b+=price;
			break;	
			
		case 5:
			price=0;
			price=6.87*a;
			b+=price;
			break;
		}
		a=0;
	}	
		
		printf("Total retail value of all products sold last week : %.2f\n",b);
		
	
	
}
