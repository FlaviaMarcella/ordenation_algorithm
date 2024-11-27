#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithm.h"



int main(){
	//funcao para abrir o arquivo
	FILE *arquivo = fopen("jogadores.csv","r");
	if(arquivo == NULL){
		printf("erro ao abri o arquivo\n");
		return 1;
	}


//vetor de structs de jogadores
jogador jogadores[1200];
int contador = 0;
char linha[256];

	//iteração para preencher o vetor com os dados lidos do arquivo
	while (fgets(linha,sizeof(linha),arquivo)){
		//ignora o cabeçalho
		if (contador == 0 &&strchr(linha,",")){
			contador++;
			continue;
		}

		//divide a linha usando "," como delimitador
		char *campo = strtok(linha,",");
		if(campo!=NULL){
			//copia a string em campo para o campo da struct
			strcpy(jogadores[contador].nome, campo);
		}
		campo = strtok(NULL,",");
		if(campo!=NULL){
			strcpy(jogadores[contador].posicao, campo);
		}
		campo = strtok(NULL,",");
		if(campo!=NULL){
			strcpy(jogadores[contador].naturalidade, campo);
		}
		campo = strtok(NULL,",");
		if(campo!=NULL){
			strcpy(jogadores[contador].clube, campo);
		}
		campo = strtok(NULL,",");
		if(campo!=NULL){
			jogadores[contador].idade = atoi(campo);
		}
		contador++;
	}

	fclose(arquivo);

	imprime_vetor(jogadores,contador);
}


