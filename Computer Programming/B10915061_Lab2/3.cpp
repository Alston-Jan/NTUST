#include <stdio.h>

int main()
{
	float x,y;
	
	printf("Enter a point's x- and y-coordinates: ");
	scanf("%f %f",&x,&y);
	
	if(x>=0 && y>=0 && x+2*y<200)
	{
		printf("The point is in the triangle.");
	}
	else
	{
		printf("The point is not in the triangle.");
	}
}
