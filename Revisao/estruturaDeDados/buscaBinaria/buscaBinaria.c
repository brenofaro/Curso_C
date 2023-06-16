#include <stdio.h>
#include <stdlib.h>
#define TAM 9

void bubleSort(int * vetor, int tam){
    int aux;
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (vetor[j] < vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void lerVetor(int * vetor, int tam){
    for (int i = 0; i < tam; i++)
    {
        if (i == tam-1)
        {
            printf("%d", vetor[i]);
        }
        else
        {
            printf("%d,", vetor[i]);
        }
    }
    printf("\n");
}

int busca_binaria(int vetor[TAM], int valorProcurado, int* posicaoEncontrada){
    
    int meio, esquerda, direita;
    esquerda = 0;
    direita = TAM-1;

    meio = (esquerda + direita) / 2;
    
    while (esquerda <= direita)
    {
        if (vetor[meio] == valorProcurado)
        {
            *posicaoEncontrada = meio;
            return 1;
        }
        else if (vetor[meio] < valorProcurado)
        {
            esquerda = meio+1;
            meio = (esquerda + direita) / 2;
        }
        else
        {
            direita = meio-1;
            meio = (esquerda + direita) / 2;
        }
    }
    return -1;
}

int main(){

    int vetor[TAM] = {1,23,44,56,63,72,84,90,98};
    int valorProcurado;
    int *posicaoProcurada;
    lerVetor(vetor,TAM);
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valorProcurado);
    int resultado = busca_binaria(vetor, valorProcurado, &posicaoProcurada);
    if (resultado == -1)
    {
        printf("O valor %d nao foi encontrado", valorProcurado);
    }
    else
    {
        printf("O valor %d foi encontrado na posicao '%d'", valorProcurado, posicaoProcurada);
    }


    return 0;
}