#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"
 
void helloWorld(void){
    printf("Hello World!\n");
}

void imprime_vetor(jogador jogadores[], int contador){
    printf("Jogadores ordenados por nome:\n");
    for (int i = 0; i < contador; i++) {
        printf("%s, %s, %s, %s, %d\n",
               jogadores[i].nome,
               jogadores[i].posicao,
               jogadores[i].naturalidade,
               jogadores[i].clube,
               jogadores[i].idade);
    }
}