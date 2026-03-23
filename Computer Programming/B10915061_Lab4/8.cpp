#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int x=1,ans=1,b=0,c=0,d=0;
	while(x!=120)
	{
		int j=0;
		ans++;
		c=0;
		for(int i=2;i<(int)sqrt(ans)+1;i++)
		{
			if(ans%i==0)
			{
				j++;
				break;
			}
			
		}
		if(j==0)
		{
			b=ans;
			while(b!=0){
				c=c*10+b%10;
				b/=10;
			}
			if(c==ans)
			{
				d++;
				printf("%u ",ans);
				x++;
			}
			if(d==10)
			{
				printf("\n");
				d=0;
			}
			
		}
		
	}
}
