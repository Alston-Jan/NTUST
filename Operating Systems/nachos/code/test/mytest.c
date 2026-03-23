#include "syscall.h"

main()
{
	FILE *in_file = fopen("In.log","r");

	if(in_file == NULL){
		printf("File Open Error!");
	}
	
	char x;
	fscanf(file, "%s", x);

	for(int i=0,i<=sizeof(x),i++){
		if(x[i] == 'j' || x[i] =='J'){
			Log(ERROR);
		}
		else{
			Log(x[i]);
		}
	}
}
