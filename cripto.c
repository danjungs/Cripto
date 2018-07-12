#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLIN 1000
//int lelinha (char *linha, int max);
/* acha: imprime linhas combinando com padrao do primeiro arg. */

int criptoText();
int descriptoText();

int main(int argc, char *argv[]){
	
	int c,status=0;

	while (--argc > 0 && (*++argv)[0] == '-')
		c = *++argv[0];
		switch (c) {
			case 'c':
				status=criptoText();
				break;
			case 'd':
				status=descriptoText();
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

int lelinha (char[], int);
void writeFile(char[]);

int criptoText(){
	char buffer[MAXLIN];
	while (lelinha(buffer, MAXLIN)) {
		for(int i=0; buffer[i] != '\0';i++){
			if(isalpha(buffer[i]))
				buffer[i] = buffer[i] +1;
		}
		writeFile(buffer);
	}
	return 1;
}

int descriptoText(){
	char buffer[MAXLIN];
	while (lelinha(buffer, MAXLIN)) {
		for(int i=0; buffer[i] != '\0';i++){
			if(isalpha(buffer[i]))
				buffer[i] = buffer[i] -1;
		}
		writeFile(buffer);
	}
	return 1;
}

int lelinha (char s [], int lim){

	int c, i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	s[i]= '\0';
	return i;
	}
	
void writeFile(char t[]){      
   FILE *fp;
   fp = fopen("saida.txt", "a");
   fprintf(fp,"%s\n",t);
   fclose(fp);          
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
