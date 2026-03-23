#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	unsigned int a[1]={0};
	
	srand(time(NULL));
	
	for(unsigned int i=1;i<=1000;i++)
	{
		unsigned int count = rand()%2;
		++a[count];
	}
	
	printf("%s%10s\n","heads","tails");
	
	printf("%5d%10d",a[0],a[1]);
	
}
 
