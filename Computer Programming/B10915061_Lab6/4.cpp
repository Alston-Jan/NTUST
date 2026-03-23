#include <stdio.h>

int getPentagonalNumber(int number)
{
	return (number*(3*number-1)/2);
}

int main()
{
	for(int number=0;number<100;number++)
	{
		int i=0;
		while(i<10)
		{
			number++;
			i++;
			printf("%7d",getPentagonalNumber(number));
		}
		printf("\n");
	}
}
