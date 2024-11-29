#ifndef _H_TESTE
#define _H_TESTE

//struct para armazenar os campos das fichas dos jogadores
typedef struct{
	char nome[50];
	char posicao[30];
	char naturalidade[30];
	char clube[50];
	int idade;
}jogador;

void imprime_vetor(jogador[], int);
void bubbleSort(jogador[], int);
void merge(jogador[], int, int, int);
void mergeSort(jogador[], int, int);
void countingSort(jogador[], int, int);
void radixSort(jogador[], int);

extern long int comparacoes;
extern long int trocas;

#endif