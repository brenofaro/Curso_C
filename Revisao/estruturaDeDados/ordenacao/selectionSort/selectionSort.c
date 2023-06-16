#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10

void ler_vetor(int * vetor, int tam){
    printf("Vetor:\n");
    for (int i = 0; i < tam; i++)
    {
        if (i == tam-1)
        {
            printf("|%d|", vetor[i]);
        }
        else
        {
            printf("|%d| ", vetor[i]);
        }
    }
    printf("\n");
}

void selectionSort(int* vetor, int tam){
    int posicaoDoMenorValor, aux, i, j;

    for (i = 0; i < tam; i++)
    {
        // Recebe a posicao inicial do menor valor
        posicaoDoMenorValor = i;
        for (j = i + 1; j < tam; j++)
        {
            // Verifica se o elemento atual e menor que o menor valor
            if (vetor[j] < vetor[posicaoDoMenorValor])
            {
                // altera o indice do menor valor
                posicaoDoMenorValor = j;
            }
        }
        // faz a troca do valor que esta sendo comparado com o menor valor se for necessario
        if (posicaoDoMenorValor != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[posicaoDoMenorValor];
            vetor[posicaoDoMenorValor] = aux;
        }
        ler_vetor(vetor, TAM);
    }
}


int main(){
    int vetor [TAM] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(vetor, TAM);
    ler_vetor(vetor, TAM);

    return 0;
}