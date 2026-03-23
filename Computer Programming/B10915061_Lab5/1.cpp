#include <stdio.h>
#include <math.h>

int main()
{
	int i=1;
	while(pow(i,3)<12000)
	{
		i++;
	}
	printf("n=%d",i);
 } 
