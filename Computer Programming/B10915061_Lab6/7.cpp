#include <stdio.h>

int isPerfect(int num)
{
	int ans=0;
	for(int i=num-1;i>=1;i--)
	{
		if(num%i==0)
		{
			ans+=i;
		}
	}
	return ans;
}

int main()
{
	for(int num=1;num<=1000;num++)
	{
		int ans=0;
		ans=isPerfect(num);
		if(ans==num)
		{
			for(int i=num-1;i>=1;i--)
			{
				if(num%i==0)
				{
					printf("%d+",i);
				}
			}
			printf(" = %d\n",num);
		}
	}
}
