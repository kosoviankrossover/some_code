// incl
#include <stdio.h>

#define SUCCESS 0

int main(){
	int i = 8;
	for (int j=0; j<3; j++){
		printf("%d + %d = %d\n",i,j,i+j);
	}
	return(SUCCESS);
}