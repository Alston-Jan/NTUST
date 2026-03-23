#include <stdio.h>

int main()
{
	int n1,n2,sum,product,difference,quotient,remainder;
	printf("enter two numbers\n");
	
	scanf("%d %d",&n1,&n2);
	
	sum=n1+n2;
	product=n1*n2;
	difference=n1-n2;
	quotient=n1/n2;
	remainder=n1%n2;
	printf("sum=%d product=%d difference=%d quotient=%d remainder=%d",sum,product,difference,quotient,remainder);
 } 
