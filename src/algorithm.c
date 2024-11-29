#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "algorithm.h"

long long trocas = 0;
long long comparacoes = 0;

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
            //conta o número de comparações feitas
            comparacoes++;
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
                //conta o número de trocas feitas
                trocas++;
            }
        }
        //confere se houve troca de elementos. Se não houve a função termina
        if(!swapped)
            break;
    }
}

//função para mesclar duas metades ordenadas, usadas no merge sort
//da mesma forma que o bubble sort, a função foi adaptada para ordenar
//strings utilizando a função strcmp para comparar os nomes
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
        //conta o número de comparações feitas
        comparacoes++;
        if(strcmp(esquerda[i].nome, direita[j].nome)<=0){
            jogadores[k] = esquerda[i];
            i++;
        }else{
            jogadores[k] = direita[j];
            j++;
        }
        k++;

        //conta o número de trocas feitas
        trocas++;
    }
    while(i<dimE){
        jogadores[k] = esquerda[i];
        i++;
        k++;

        //conta o número de trocas feitas
        trocas++;
    }
    while(j<dimD){
        jogadores[k] = direita[j];
        j++;
        k++;

        //conta o número de trocas feitas
        trocas++;
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

//a função counting sort é utilizada na função radix sort
void countingSort(jogador jogadores[], int n, int pos){
    jogador saida[n];
    //256 é o número de carcteres da tabela ASCII
    int cont[256] = {0};

    //conta a frequenca dos carcteres na posição pos de cada nome
    for(int i=0; i<n; i++){
        int indice = (unsigned char)jogadores[i].nome[pos];
        cont[indice]++;

        //conta o número de comparações feitas
        comparacoes++;
    }

    //atualiza o vetor de contagem para dizer as posições finais
    for(int i=1;i<256;i++){
        cont[i] += cont[i-1];
    }

    //constroi o vetor de saida
    for(int i=n-1;i>=0;i--){
        int indice=(unsigned char)jogadores[i].nome[pos];
        saida[cont[indice]-1] = jogadores[i];
        cont[indice]--;

        //conta o número de trocas feitas
        trocas++;
    }

    //copia o vetor de saida para o vetor original
    for(int i=0; i<n; i++){
        jogadores[i] = saida[i];
    }
}

//radix sort também foi adptada para ordenar os nomes dos jogadores
void radixSort(jogador jogadores[], int n){
    int maior_tamanho = 0;

    //encontra o tamanho máximo de nome
    for(int i=0; i<n; i++){
        int tamanho_nome = strlen(jogadores[i].nome);
        if(tamanho_nome>maior_tamanho){
            maior_tamanho = tamanho_nome;
        }

        //conta o número de comparações feitas
        comparacoes++;
    }

    //usa o algortimo counting sort para cada posição do nome
    //do ultimo caracter para o primeiro
    for(int pos = maior_tamanho -1; pos>=0;pos--){
        countingSort(jogadores,n,pos);
    }
}