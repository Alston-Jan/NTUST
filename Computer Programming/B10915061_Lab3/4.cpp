#include <stdio.h>

int main()
{
	int a,b=-1,count=10,f=-1,s;
	
	while(count--)
	{
		printf("Input : ");
		scanf("%d",&a);
		if(a>f)
		{
			s=f;
			f=a;
		}
		
	}
	printf("First number is:%d Second number is:%d",f,s);
} 
 
