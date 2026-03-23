#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int die()
{
	int num=0,sec=0;
	
	srand(time(NULL));
	num=2+rand()%11;
	
	printf("your point is %d\n" , num);
	
	if(num==7||num==11)
	{
		return 1;
	}
	else if(num==2||num==3||num==12)
	{
		return 0;
	}
	else
	{
	printf("your anther point is");
		while(num!=sec&&sec!=7)
		{
			sec=2+rand()%11;	
			printf(",%d",sec);
		}
		if(sec==7)
		{
			printf("\n");
			return 0;
		}
		if(sec==num)
		{
			printf("\n");
			return 1;
		}
	}
}

int main()
{
	int money=1000,wager;
	while(money>0)
	{
		printf("Your bank money :");
		printf("%d\n",money);
		
		printf("Enter the wager :");
		scanf("%d",&wager);
		while(wager>money)
		{
			printf("Enter the wager :");
			scanf("%d",&wager);
		}
		
		
		if(die()==1)
		{
			money+=wager;
			printf("you win!\n");
		}
		else 
		{
			printf("you lose!\n");
			money-=wager;
		}
	}
	printf("Sorry. You busted!");
}
