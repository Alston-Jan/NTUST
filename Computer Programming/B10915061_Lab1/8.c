#include <stdio.h>

int main()
{
	int n1,n2,n3,Sum,Average,Product,Smallest,Largest;
	printf("Enter three different integers:");
	scanf("%d %d %d",&n1,&n2,&n3);
	
	Sum=n1+n2+n3;
	Average=Sum/3;
	Product=n1*n2*n3;
	
	printf("Sum is %d\n",Sum);
	printf("Average is %d\n",Average);
	printf("Product is %d\n",Product);
	
	
	if(n1<n2)
	{
		Smallest=n1;
		if(Smallest>n3)
		{
			Smallest=n3;
		}
	}
	else
	{
		Smallest=n2;
		if(Smallest>n3)
		{
			Smallest=n3;
		}
	}
	
	printf("Smallest is %d\n",Smallest);
	
	
	if(n1>n2)
	{
		Largest=n1;
		if(Largest<n3)
		{
			Largest=n3;
		}
	}
	else
	{
		Largest=n2;
		if(Largest<n3)
		{
			Largest=n3;
		}
	}
	
	printf("Largest is %d\n",Largest);
}
