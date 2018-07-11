#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define OK 1
#define ERRO 0
#define MAX 50
#define CRIPTO 5
#define DESCRIP 6
#define MAX_FOLDER 20

void getPrime(long*,long*);
int checkPrime(long);
void getCP(long,long,long*,long*);
void getDP(long,long,long*);
void generateNumCrip(long,long);
void generateNumDescrip(long,long);

int main(){
	long P1,P2;
	long CP1,CP2,DP;
	getPrime(&P1,&P2);
	long Y = (P1-1)*(P2-1);
	if(checkPrime(P1) && checkPrime(P2)){
		getCP(P1,P2,&CP1,&CP2);
		getDP(CP1,Y,&DP);
      generateNumCrip(CP1,CP2);
      generateNumDescrip(DP,CP2);
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

void getCP(long P1,long P2,long *CP1,long *CP2){
	long primos[]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
	long Y = (P1-1)*(P2-1);
	int i= 0;
	
	*CP2 = P1*P2;
	while(primos[i++]){
		if (Y % primos[i] != 0)
			break;
	}
	if (primos[i] != '\0')
		*CP1 = primos[i];
}		

void getDP(long CP1,long Y,long *DP){
	long c = 1;
	
	while(c++ < Y){
		if ((CP1*c)%Y == 1)
			break;
	}
	*DP = c;
}

void writeFile(long,long,int);

void generateNumCrip(long CP1,long CP2){
   writeFile(CP1,CP2,CRIPTO);
}
void generateNumDescrip(long DP,long CP2){
   writeFile(DP,CP2,DESCRIP);
}

void writeFile(long a,long b,int sentido){
   char folder[MAX_FOLDER];   
   if(sentido == CRIPTO)
      strcpy(folder,"numcripto.txt");
   else
      strcpy(folder,"numdescripto.txt"); 
     
   FILE *fp;
   fp = fopen(folder, "w");
   fprintf(fp,"%ld ",a);
   fprintf(fp,"%ld",b);
   fclose(fp);          
}






		
