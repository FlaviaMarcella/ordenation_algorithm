#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include "algorithm.h"


int main(int argc, char *argv[]) {

	// Configura o locale para suportar UTF-8
    setlocale(LC_ALL, "");

    if (argc != 2) {
        printf("Uso: %s <algoritmo>\n", argv[0]);
        printf("1: Método de ordenação simples\n");
        printf("2: Método de ordenação ótimo\n");
        printf("3: Método de ordenação em tempo linear\n");
        return 1;
    }

    int algoritmo = atoi(argv[1]);

	if (algoritmo < 1 || algoritmo > 3) {
		printf("Opção inválida\n");
		return 1;
	}

	//funcao para abrir o arquivo
	FILE *arquivo = fopen("./src/jogadores.csv","r");
	if(arquivo == NULL){
		printf("erro ao abrir o arquivo\n");
		return 1;
	}


//vetor de structs de jogadores
jogador jogadores[1200];
int contador = 0;
char linha[256];

	//iteração para preencher o vetor com os dados lidos do arquivo
	while (fgets(linha,sizeof(linha),arquivo)){
		//ignora o cabeçalho
		if (contador == 0 &&strchr(linha,',')){
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

	double tempo1 = 0;
	clock_t inicio = 0;
	clock_t fim = 0;

	// Seleciona o algoritmo de ordenação com base no argumento
    switch (algoritmo) {
        case 1:
            inicio = clock();
            bubbleSort(jogadores, contador);
            fim = clock();
            break;
        case 2:
            inicio = clock();
            mergeSort(jogadores, 0, contador - 1);
            fim = clock();
            break;
        case 3:
            inicio = clock();
            radixSort(jogadores, contador);
            fim = clock();
            break;
        default:
            printf("Algoritmo inválido. Use 1, 2 ou 3.\n");
            return 1;
    }


	tempo1 += (double)(fim-inicio)/CLOCKS_PER_SEC;

	// Função para imprimir o vetor de jogadores ordenado
	imprime_vetor(jogadores, contador);

	// Imprime o tempo de execução
    printf("Tempo de execução: %f segundos\n", tempo1);
    printf("Número de comparações: %lld\n", comparacoes);
    printf("Número de trocas: %lld\n", trocas);
    printf("Memória total gasta: %zu bytes\n", sizeof(jogadores) + contador * sizeof(jogador));


	return 0;
}


