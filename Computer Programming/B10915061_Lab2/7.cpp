#include <stdio.h>

int main()
{
	int ye,m,q,h,j,k;
	
	printf("Enter year: ");
	scanf("%d",&ye);
	
	printf("Enter month (1-12): ");
	scanf("%d",&m);
	
	printf("Enter the day of the month (1-31): ");
	scanf("%d",&q);
	
	if(m<=2)
	{
		m=m+12;
		ye=ye-1;
	}
	
	j=ye/100;
	
	k=ye%100;
	
	h=(q+(26*(m+1))/10+k+k/4+j/4+5*j)%7;
	
	if(h==0)
	{
		printf("Day of the week is Saturday");
	}
	if(h==1)
	{
		printf("Day of the week is Sunday");
	}
	if(h==2)
	{
		printf("Day of the week is Monday");
	}
	if(h==3)
	{
		printf("Day of the week is Tuesday");
	}
	if(h==4)
	{
		printf("Day of the week is Wednesday");
	}
	if(h==5)
	{
		printf("Day of the week is Thursday");
	}
	if(h==6)
	{
		printf("Day of the week is Friday");
	}
}
