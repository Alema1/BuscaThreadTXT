/*
buscathread2.
Vinicius Hardt Schreiner / 201420108
*/

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>

char palavra[128];
char string[32];		  
int strFlag = 0;
clock_t tempoInit, tempoFin;
float tempoExec;

// Funcoes para leitura dos arquivos
void * lerarquivo1(){
	//abertura do arquivo e busca no .txt
	FILE *arquivo;
	
	if (( arquivo = fopen("File1_test2.txt", "r")) == NULL ) {
        printf("Falha ao abrir o arquivo");
        exit(1);
    }
	//inicia contagem do tempo de exec
	tempoInit = clock();
	while(fgets(palavra, 128, arquivo) != NULL) {
		if((strstr(palavra, string)) != NULL) {
			printf("\nString encontrada no arquivo 1 pela thread 1\n");
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
		tempoFin = 0;
	}
return(NULL);
}

void * lerarquivo2(){

	FILE *arquivo;
	
	if (( arquivo = fopen("File2_test2.txt", "r")) == NULL ) {
        printf("Falha ao abrir o arquivo");
        exit(1);
    } 
	//inicia contagem do tempo de exec
	tempoInit = clock();
	while(fgets(palavra, 128, arquivo) != NULL) {
		if((strstr(palavra, string)) != NULL) {
			printf("\nString encontrada no arquivo 2 pela thread 2\n");
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
		tempoFin = 0;
	}

return(NULL);	
}
int main(){
//recebe a string a ser buscada
fflush(stdin);
printf("Digite a String a ser buscada:\n");
gets(string);

pthread_t t0, t1, t2, t3;
pthread_create(&t0, NULL, lerarquivo1,NULL);
pthread_create(&t1, NULL, lerarquivo2,NULL);
pthread_join(t0,NULL);
pthread_join(t1,NULL);

if(strFlag == 0){
	printf("String nao encontrada!\n");
}


return 0;
}
