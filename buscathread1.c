/*
buscathread1.c
Vinicius Hardt Schreiner / 201420108
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char palavra[128];
char string[32];		  
int strFlag = 0;
clock_t tempoInit, tempoFin;
float tempoExec;

// Funcoes para leitura dos arquivos
	
void lerarquivo1(){
	//abertura do arquivo e busca no .txt
	FILE *arquivo;
	
	if (( arquivo = fopen("File1_test1.txt", "r")) == NULL ) { 
        printf("Falha ao abrir o arquivo"); 
        exit(1);
    }
	//inicia contagem do tempo de exec
	tempoInit = clock();

	while(fgets(palavra, 128, arquivo) != NULL) {
		if((strstr(palavra, string)) != NULL) {
			printf("\nString encontrada no arquivo 1\n");
			strFlag++;
			//termina contagem do tempo de exec
			tempoFin = clock();
			//converte o tempo de exec em ms
			tempoExec = (tempoFin - tempoInit)*1000/CLOCKS_PER_SEC;
			printf("Tempo de busca nos arquivos: %f ms\n",tempoExec);
		}
		
	}

	//fecha o arquivo
	if(arquivo) {
		fclose(arquivo);
	}

}


int main() {
	
//recebe a string a ser buscada
fflush(stdin);
printf("Digite a string a ser buscada!\n");
gets(string);

lerarquivo1();

if(strFlag == 0){
	printf("String nao encontrada!\n");
}
	
	return 0;
}
