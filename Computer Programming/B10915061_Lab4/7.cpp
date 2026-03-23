#include <stdio.h>

int main()
{
	for(int a=2;a<=1000;a++)
	{
		int j=0;
		for(int i=2;i<a;i++)
		{
			if(a%i==0)
			{
				j++;
			}
			
		}
		if(j==0)
		{
			printf("%d ",a);
		}
	}
}
