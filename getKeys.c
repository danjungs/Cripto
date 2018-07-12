#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

long getnumber(char*,int);

int main(){
	char *buffer =malloc(sizeof(long));
	fgets (buffer, MAX, stdin);
	long cp1 = getnumber(buffer,1);
	long cp2 = getnumber(buffer,2);
	
	printf("%ld\n%ld\n",cp1,cp2);
	free(buffer);
	return 0;
}

long getnumber(char*b,int num){
	if (num==1)
		return atoi(b);
	while(*b++ != ' ');
		;
	return atoi(b);
}
