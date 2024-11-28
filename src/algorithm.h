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

#endif