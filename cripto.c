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

/* ------------ Protótipos de Funções usadas na main----------*/
int criptoText(long,long);
int descriptoCode(long,long);
void getKeys(long*,long*,int);
/* ------------------------------------------------------------*/

int main(int argc, char *argv[]) {
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
        status=descriptoCode(CH1,CH2);
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
/* -----Protótipo de Função na getKeys ----------*/
long getnumber(char*,int);

/*	Essa Função recebe qual operação está sendo feita pela varaivel sentido
	E com essa informação lê o arquivo correto, guardando o valor das chaves
	Nas variaveis passadas por parâmetro.
*/
void getKeys(long*ch1,long*ch2,int sentido) {
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

long getnumber(char*b,int num) {
    if (num==1)
        return atoi(b);
    while(*b++ != ' ')
    	;
    return atoi(b);
}
/* ------------------------------------------------------------*/
/* ---- Protótipos de Funções usadas em cripto e descripto ----*/
long eleva(long,int);
int criptaChar(char,long,long);
void binarioInv(int,char *);
char descriptaLong(long,long,long);
/* ------------------------------------------------------------*/

/* ------Criptografa o texto inteiro linha por linha ----------*/
int criptoText(long CP1,long CP2) {
	FILE *fp = fopen("saida.txt", "w");
	long crip;
	char c;

	while ((c = getchar()) != EOF) {
		crip = criptaChar(c,CP1,CP2);
        fprintf(fp,"%ld ",crip);
    }
	fclose(fp);
    return 1;
}

int criptaChar(char entrada,long CP1,long CP2) {
	long saida = (long)entrada;	
	//if(isalpha(saida) || saida == ' ' || saida == '\n')
		saida = eleva(saida,CP1) % CP2;
	return saida;
}

int descriptoCode(long DP1, long DP2){
	FILE *fp = fopen("decode.txt", "w");
	long crip;
	char c;
	while(scanf("%ld",&crip)==1){
		c = descriptaLong(DP1,DP2,crip);
		fprintf(fp,"%c",c);
	}
	fclose(fp);	
	return 1;
}

char descriptaLong(long DP1,long DP2,long crip) {
    char saida;
    long resto = 0,valorfinal = 1;
	char bin[MAXBUF]="";
	binarioInv(DP1,bin);
	
    if(crip!='\n') {
        for(int i=0; bin[i] != '\0'; i++) {
            if (i==0)
                resto = crip%DP2;
            if (bin[i] =='1') {
                valorfinal *=resto;
                valorfinal = valorfinal % DP2;
            }
            resto = eleva(resto,2) % DP2;
        }
        saida = valorfinal;
    } else 
        saida = (char) crip;
    return saida;
}

/* Gera um array com o binario invertido para o id ser igual ao expoente */
void binarioInv(int n,char *bin) {
    int i=0;

    while(n>0) {
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
/* essa função recebe dois parametros e elava o primeiro pelo segundo*/
long eleva(long a,int b) {
    long aux=a;

    while(b-->1)
        a=a*aux;
    return a;
}
