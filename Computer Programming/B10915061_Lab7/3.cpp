#include <stdio.h>

int pow(int base,int exp)
{
	int ans=1;
	for(int i=1;i<=exp;i++)
	{
		ans*=base;
	}
	return ans;
}

int main()
{
	int base,exp;
	
	scanf("%d%d",&base,&exp);
	
	printf("%d",pow(base,exp));
}
