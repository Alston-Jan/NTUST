#include <stdio.h>

int main()
{
	float x1,y1,r1,x2,y2,r2,d,a,b,out;
	
	printf("Enter circle1's center x-, y-coordinates, and radius:");
	scanf("%f %f %f",&x1,&y1,&r1);
	
	printf("Enter circle2's center x-, y-coordinates, and radius:");
	scanf("%f %f %f",&x2,&y2,&r2);
	
	d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	
	a=(r1+r2)*(r1+r2);
	b=(r1-r2)*(r1-r2);
	
	if(d<=b)
	{
		printf("Circle2 is inside circle1.");
	}
	else if(d<=a)
	{
		printf("Circle2 is overlap circle1.");
	} 
	else
	{
		printf("Circle2 does not overlap circle1.");
	} 
} 
 
