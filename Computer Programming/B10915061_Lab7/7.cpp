#include <stdio.h>

int Hanoi(int n,char start,char hole,char finish) 
{
	if(n==1)
	{
		printf("%c -> %c\n",start,finish);
	}
	else
	{
		Hanoi(n-1,start,finish,hole);
		Hanoi(1,start,hole,finish);
		Hanoi(n-1,hole,start,finish);	
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	Hanoi(n,'A','B','C');
}
