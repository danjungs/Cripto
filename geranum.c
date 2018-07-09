#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define OK 1
#define ERRO 0
#define MAX 50

void getPrime(long*,long*);
int checkPrime(long);
void getCP(long,long,long,long);
void getDP(long,long,long);

int main(){
	long P1,P2;
	long CP1,CP2,DP;
	getPrime(&P1,&P2);
	printf("P1: %ld\nP2: %ld\n",P1,P2);
	if(checkPrime(P1) && checkPrime(P2)){
		// getCP(P1,P2,CP1,CP2);
		// getDP(P1,P2,DP);
		printf("Numeros são Primos!\n");
	}
	else
		printf("Numeros não são Primos!\n");
		
	printf("CP1: %ld\nCP2: %ld\nDP: %ld\n",CP1,CP2,DP);
	return 0;
}

void getPrime(long *a,long *b){
	char buffer[MAX];
	printf ("Entre o primeiro primo: ");
	fgets (buffer, MAX, stdin);
	*a = atoi (buffer);
	
	printf ("Entre o segundo primo:  ");
	fgets (buffer, MAX, stdin);
	*b = atoi (buffer);
}

int checkPrime(long a){
   long c;
 
   for (c = 2 ; c <= a/2 ;c++){ 
      if ( a%c == 0 )
     		return ERRO;
   }
   return OK;
}
