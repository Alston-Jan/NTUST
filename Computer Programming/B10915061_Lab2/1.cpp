#include <stdio.h>

int main()
{
	float dol,usd,ntd;
	int vic;
	
	printf("Enter the exchange rate from USD to NTD: ");
	scanf("%f",&dol);
	
	printf("Enter 0 to convert USD to NTD and 1 vice versa: ");
	scanf("%d",&vic);
	
	if(vic==0)
	{
		printf("Enter the USD amount: ");
		scanf("%f",&usd);
		
		ntd=usd*dol;
		printf("$%.1f USD is %.f NTD.",usd,ntd);
	}
	else
	{
		printf("Enter the NTD amount: ");
		scanf("%f",&ntd);
		
		usd=ntd/dol;
		printf("$%.f NTD is %.1f USD.",ntd,usd);
	}
 } 
