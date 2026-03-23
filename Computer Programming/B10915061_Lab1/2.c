#include <stdio.h>

int main()
{
	int time,sec,min,hr;
	
	printf("enter seconds\n");
	scanf("%d",&time);
	
	sec=time%60;
	hr=time/3600;
	min=(time-hr*3600-sec)/60;
	
	printf("%d:%d:%d",hr,min,sec);
}
