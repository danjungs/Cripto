#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLIN 10000
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
int leCrip (long[], int);
long eleva(long,int);
void criptaLine(char *,long,long, long*);
void binarioInv(int,char *);
void descriptaLine(long *,char*,long, char*);
void writeCrip(long*);
void writeText(char*);
/* ------------------------------------------------------------*/

/* ------Criptografa o texto inteiro linha por linha ----------*/
int criptoText(long CP1,long CP2){
	char buffer[MAXLIN];
   long  *lineCrip = malloc(MAXLIN*sizeof(int));

	while (lelinha(buffer, MAXLIN)) {

      criptaLine(buffer,CP1,CP2,lineCrip);		
		writeCrip(lineCrip);
	}
	free(lineCrip);
	return 1;
}



void criptaLine(char *linha,long CP1,long CP2, long*saida)
 {
 	int i=0;
 	for(i=0; linha[i] != '\0';i++){
 		saida[i]= (long)linha[i];
 		saida[i]=  eleva(saida[i],CP1) % CP2;
 	}
   saida[i] = '\0';
 }

int descriptoText(long DP1,long DP2){
	long buffer[MAXLIN];
   char  *lineDescrip = malloc(MAXLIN*sizeof(int));
   char bin[MAXBUF]="";
   binarioInv(DP1,bin);
	while (leCrip(buffer, MAXLIN)) {
      descriptaLine(buffer,bin,DP2,lineDescrip);
      printf("inicio: %s  - fim. ",lineDescrip);
		writeText(lineDescrip);
	}
	free(lineDescrip);
	return 1;
}

/* Gera um array com o binario invertido para o id ser igual ao expoente */
void binarioInv(int n,char *bin) { 
	int i=0;
	while(n>0){
		if(n%2 ==0)
			strcat(bin,"0");
		else
			strcat(bin,"1");
		n /=2;
		i++;
	}
	bin[i] = '\0';
}
/* ----------------------------------------------------------------------*/

void descriptaLine(long *linha,char *binario,long DP2, char *saida){
	int j =0;
	long resto = 0,valorfinal = 1;

	for(j=0; linha[j] != '\0';j++){
		resto = 0;valorfinal = 1;
		for(int i=0;binario[i] != '\0';i++){
			if (i==0)
				resto = linha[j]%DP2;
			if (binario[i] =='1'){
				valorfinal *=resto;
			}
			resto = eleva(resto,2) % DP2;
		}
		valorfinal = valorfinal%DP2;
		saida[j] = valorfinal;
	}
	saida[j] = '\0';
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
	
int leCrip (long s[], int lim){

	int c, i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!=108; ++i)
		s[i] = c;
	if (c == 108)
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

void writeCrip(long *t){      
   FILE *fp;
   fp = fopen("saida.txt", "a");
   for(int i = 0; t[i] !='\0';i++)
      fputc(t[i],fp);
   fclose(fp);          
}	
	
void writeText(char *t){      
   FILE *fp;
   fp = fopen("decode.txt", "a");
   fprintf(fp,"%s",t);
   fclose(fp);          
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
