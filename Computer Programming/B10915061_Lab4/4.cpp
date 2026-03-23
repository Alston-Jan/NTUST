#include <stdio.h>
#include <math.h>

int main()
{
	for(float i=10000;i<=100000;i+=10000)
	{
		float totol=0;
		for(int a=1;a<=i;a++)
		{
			totol=totol+4*pow(-1,a+1)/(2*a-1);
		}
		printf("%.0f totol=%f\n",i,totol);
	}
}
