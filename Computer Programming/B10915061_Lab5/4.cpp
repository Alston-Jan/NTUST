#include<stdio.h>
#include<math.h>

int main()
{
	float ans;
	
	for(int i=1;i<1000;i++)
	{
		ans+=(1/((float)sqrt(i)+(float)sqrt(i+1)));
	}
	printf("%f",ans);
}
