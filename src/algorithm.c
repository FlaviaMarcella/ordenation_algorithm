#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

//modificamos a função bubble sort para que ela troque strings
//ao invés de números. Para isso usamos a função strcmp, que vem
//com a implementação da biblioteca string.h que já é padrão da linguagem C
void bubbleSort(jogador jogadores[], int contador){
    char temp[50];
    int i,j;
    bool swapped;
    for(i=0;i<contador-1;i++){
        for(j=0; j<contador-i-1;j++){
            //a função strcmp compara duas strings e retorna
            // <0 se a primeira string em antes da segunda em ordem alfabética
            //0 se as strings são iguais
            //>0 se a primeira string vem depois da segunda em ordem alfabética
            if(strcmp(jogadores[j].nome, jogadores[j+1].nome)>0){
                //a função strcpy também é da biblioteca string.h, e copia uma
                //string de uma origem para um destino
                strcpy(temp, jogadores[j].nome);
                strcpy(jogadores[j].nome, jogadores[j+1].nome);
                strcpy(jogadores[j+1].nome, temp);
                swapped = true;
            }
        }
        //confere se houve troca de elementos. Se não houve a função termina
        if(!swapped)
            break;
    }
}

//função para mesclar duas metades ordenadas, usadas no merge sort
void merge(jogador jogadores[], int inicio, int meio, int fim){
    int dimE = meio - inicio + 1;
    int dimD = fim - meio;

    jogador esquerda[dimE], direita[dimD];
    int i,j;
    for(i=0;i<dimE;i++){
        esquerda[i]=jogadores[inicio+i];
    }
    for(j=0;j<dimD; j++){
        direita[j] = jogadores[meio + 1 + j];
    }

    i=0;j=0; int k=inicio;

    while(i<dimE && j<dimD){
        if(strcmp(esquerda[i].nome, direita[j].nome)<=0){
            jogadores[k] = esquerda[i];
            i++;
        }else{
            jogadores[k] = direita[j];
            j++;
        }
        k++;
    }
    while(i<dimE){
        jogadores[k] = esquerda[i];
        i++;
        k++;
    }
    while(j<dimD){
        jogadores[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(jogador jogadores[], int inicio, int fim){
    if(inicio < fim){
        int meio = inicio + (fim-inicio)/2;

        mergeSort(jogadores, inicio, meio);
        mergeSort(jogadores, meio+1, fim);

        merge(jogadores, inicio, meio, fim);
    }
}