#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

int main(){
	char *buffer =malloc(sizeof(long));
	fgets (buffer, MAX, stdin);
	long cp1 = atoi(buffer++);
	long cp2 = atoi(buffer);
	printf("%ld\n%ld\n",cp1,cp2);
	free(--buffer);
	return 0;
}
