#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLIN 100
#define FIRST 1
#define SECOND 2
#define CRIPTO 3
#define DESCRIP 4
#define MAXBUF 20
//int lelinha (char *linha, int max);
/* acha: imprime linhas combinando com padrao do primeiro arg. */

int criptoText(long,long);
int descriptoText(long,long);
void getKeys(long*,long*,int);

int main(int argc, char *argv[]){
	
	int c,status=0;
   long CH1,CH2;

	while (--argc > 0 && (*++argv)[0] == '-')
		c = *++argv[0];
		switch (c) {
			case 'c':            
            getKeys(&CH1,&CH2,CRIPTO);
				status=criptoText(CH1,CH2);
				break;
			case 'd':
            getKeys(&CH1,&CH2,DESCRIP);
				status=descriptoText(CH1,CH2);
				break;

			default:
				printf("Cripto: opção ilegal %c\n", c);
				argc = 0;
				break;
		}
		if(!status)
			printf("Operação falhou.\n");
		else
			printf("Operação feita com sucesso.\n");
	return 0;
}

long getnumber(char*,int);

void getKeys(long*ch1,long*ch2,int sentido){
	char *buffer =malloc(sizeof(long));
   FILE *fp;
   char folder[MAXBUF];   
   if(sentido == CRIPTO)
      strcpy(folder,"numcripto.txt");
   else
      strcpy(folder,"numdescripto.txt");
 
   fp = fopen(folder, "r");
	fgets (buffer, MAXBUF, fp);
	*ch1 = getnumber(buffer,FIRST);
	*ch2 = getnumber(buffer,SECOND);
	
	free(buffer);
}

long getnumber(char*b,int num){
	if (num==1)
		return atoi(b);
	while(*b++ != ' ');
		;
	return atoi(b);
}
/* ------------------------------------------------------------*/
/* -----Protótipos de Funções para cripto e descripto----------*/
int lelinha (char[], int);
void criptaLine(char *,long,long, long*);
void writeFile(long*);

/* ------------------------------------------------------------*/
/* ------Criptografa o texto inteiro linha por linha ----------*/
int criptoText(long CP1,long CP2){
	char buffer[MAXLIN];
   long  *lineCrip = malloc(MAXLIN*sizeof(int));
	while (lelinha(buffer, MAXLIN)) {
      criptaLine(buffer,CP1,CP2,lineCrip);		
		writeFile(lineCrip);
		for(int i = 0; lineCrip[i] !='\0';i++)
      	printf("Letra: %c cripto: %ld\n",buffer[i],lineCrip[i]);
	}
	free(lineCrip);
	return 1;
}

int descriptoText(long DP1,long DP2){
	char buffer[MAXLIN];
   long  *lineDescrip = malloc(MAXLIN*sizeof(int));
	while (lelinha(buffer, MAXLIN)) {
		for(int i=0; buffer[i] != '\0';i++){
			if(isalpha(buffer[i]))
				buffer[i] = buffer[i] -1;
		}
      criptaLine(buffer,DP1,DP2,lineDescrip);  // SÓ PRA COMPILAR
		writeFile(lineDescrip);
	}
	free(lineDescrip);
	return 1;
}

int lelinha (char s [], int lim){

	int c, i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n')
	 	s[i++] = c;
	s[i]= '\0';
	return i;
	}
	
long eleva(long a,int b){
	long aux=a;
	while(b-->1)
		a=a*aux;
	return a;
}

void criptaLine(char *linha,long CP1,long CP2, long*b)
 {
 	int i=0;
 	for(i=0; linha[i] != '\0';i++){
 		b[i]= (long)linha[i];
 		b[i]=  eleva(b[i],CP1) % CP2;
 	}
   b[i] = '\0';
 }

void writeFile(long *t){      
   FILE *fp;
   fp = fopen("saida.crp", "a");
   for(int i = 0; t[i] !='\0';i++)
      fputc(t[i],fp);
   fclose(fp);          
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
