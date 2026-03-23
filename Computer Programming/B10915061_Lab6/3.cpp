#include <stdio.h>

int isEven (int a)
{
	if(a>0)
	{
		if(a%2==1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	int a;
	
	printf("Enter an integer : ");
	scanf("%d",&a);
	
	while(a!=0)
	{
		
		
		if(isEven(a)==1)
		{
			printf("This integer is Odd\n");
		}
		else
		{
			printf("This integer is Even\n");
		}
		
		printf("Enter an integer : ");
		scanf("%d",&a);
	}
}
