#include<stdio.h>
#include<math.h>

int main()
{
	int a,ans;
	for(int num=2;num<=1200;num++)
	{
		a=0;
		for(int i=2;i<num;i++)
		{
			if(num%i==0)
			{
				a++;
			}
		}
		if(a==0)
		{
			if(num-ans==2)
			{
				printf("(%d,%d)\n",ans,num);
			}
			ans=num;
		}
	}
}
