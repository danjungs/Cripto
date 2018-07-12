/* ---------------- Bibliotecas e Definições -------------------------- */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ERRO 0
#define OK 1
#define FIRST 2
#define SECOND 3
#define CRIPTO 5
#define DESCRIP 6
#define MAX_FOLDER 20
#define MAX 50
/* -------------------------------------------------------------------- */

/* -------------- Protótipos de Funções usadas no main ---------------- */
long getPrime(int);
int checkPrime(long);
long getCP(long,long,int);
long getDP(long,long);
void generateNumCrip(long,long);
void generateNumDescrip(long,long);
/* -------------------------------------------------------------------- */

int main(){
	long P1,P2;
	long CP1,CP2,DP;
	P1 =getPrime(FIRST);
	P2 =getPrime(SECOND);
	long Y = (P1-1)*(P2-1);
	if(checkPrime(P1) && checkPrime(P2)){
		CP1 = getCP(P1,P2,FIRST);
		CP2 = getCP(P1,P2,SECOND);
		DP = getDP(CP1,Y);
      generateNumCrip(CP1,CP2);
      generateNumDescrip(DP,CP2);
	}
	else
		printf("Numeros não são Primos!\n");
		
	printf("CP1: %ld\nCP2: %ld\nDP: %ld\n",CP1,CP2,DP);
	return 0;
}

// função retorna um primo pego pelo stdin
long getPrime(int num){
	char buffer[MAX];
	if (num == FIRST)
		printf ("Entre o primeiro primo: ");
	else
		printf ("Entre o segundo primo:  ");
	fgets (buffer, MAX, stdin);
	return atoi (buffer);
}

// função testa se o numero é primo
int checkPrime(long a){
   long c;
 
   for (c = 2 ; c <= a/2 ;c++){ 
      if ( a%c == 0 )
     		return ERRO;
   }
   return OK;
}

/* função calcula CP, caso seja o primero, ela fatora Y e testa com
   o banco de primos criado em primos.
   caso seja o segundo, ela retorna o produto dos dois primos.
*/
long getCP(long P1,long P2,int num){
	long primos[]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
	long Y = (P1-1)*(P2-1);
	int i= 0;
	
	if (num == FIRST){
		while(primos[i++]){
			if (Y % primos[i] != 0)
				break;
		}
		if (primos[i] != '\0')
			return primos[i];
	}
	return P1*P2;
}		

/*Função retorna o valor do numero que multiplicado por CP1 
  tem resto 1 na divisão por Y
*/
long getDP(long CP1,long Y){
	long c = 1;
	
	while(c++ < Y){
		if ((CP1*c)%Y == 1)
			break;
	}
	return c;
}

/* --------- Protótipos de Funções usadas nas funções a seguir -------- */
void writeFile(long,long,int);
/* -------------------------------------------------------------------- */

void generateNumCrip(long CP1,long CP2){
   writeFile(CP1,CP2,CRIPTO);
}
void generateNumDescrip(long DP,long CP2){
   writeFile(DP,CP2,DESCRIP);
}

/* função escreve em ASCII os dois LONGs que recebe
   o sentido decide se será gerado o numcripto ou o numdescripto
*/
void writeFile(long a,long b,int sentido){
   char folder[MAX_FOLDER];   
   if(sentido == CRIPTO)
      strcpy(folder,"numcripto.txt");
   else
      strcpy(folder,"numdescripto.txt"); 
     
   FILE *fp;
   fp = fopen(folder, "w");
   fprintf(fp,"%ld %ld",a,b);
   fclose(fp);          
}






		
