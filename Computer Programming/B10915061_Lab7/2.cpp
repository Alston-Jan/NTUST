#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int number,ans;
	char again='y';
	while(again =='y')
	{
		printf("I have a number between 1 and 1000\n");
		printf("Can you guess my number?\n");
		printf("Please type your first guess.\n");
		
		scanf("%d",&number);
	
		srand(time(NULL));
		ans=1+rand()%1000;
		//Anser!!
		//printf("%d\n",ans);  
	
		while(ans!=number)
		{
		
			if(ans>number)
			{
				printf("Too low! Try again.\n");
			}
			else if(ans<number)
			{
				printf("Too high! Try again.\n");
			}
			scanf("%d",&number);
		}
		printf("Excellent! You guessed the number.\n");
		printf("Would you like to play again (y or n)?\n");
		scanf("%s",&again);
		//getchar();
	}
}
