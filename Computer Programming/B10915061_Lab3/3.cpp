#include <stdio.h>

int main()
{
	int num,test,i=2 ;
	printf("Input : ");
	scanf("%d",&num);
	
	while(i<num)
	{
		test=num%i;
		i++;
		if(test==0)
		{
			printf("Not");
			return 0;
		}	
	}
	
	printf("Yes");
}
