#include <stdio.h>

int main(){
	int a,b,c;
	
	for(a=1;a<=500;a++){
		for(b=1;b<a;b++){
			for(c=1;c<b;c++){
				if(a*a==b*b+c*c){
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
}
