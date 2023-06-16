#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10

void ler_vetor(int *vetor, int tam)
{
    printf("Vetor:\n");
    for (int i = 0; i < tam; i++)
    {
        if (i == tam - 1)
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

int dividir(int *vetor, int esq, int dir)
{
    int aux; // Aux para troca de posicoes
    int cont = esq; // 
    for (int i = esq + 1; i <= dir; i++)
    {
        if (vetor[i] < vetor[esq])
        {
            cont++;
            aux = vetor[i];
            vetor[i] = vetor[cont];
            vetor[cont] = aux;
        }
    }
    aux = vetor[esq];
    vetor[esq] = vetor[cont];
    vetor[cont] = aux;

    return cont;
}

void quick_sort(int *vetor, int esq, int dir)
{
    int pos;
    if (esq < dir)
    {
        pos = dividir(vetor, esq, dir);
        quick_sort(vetor, esq, pos - 1);
        quick_sort(vetor, pos + 1, dir);
    }
}

int main()
{
    int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quick_sort(vetor, 0, TAM);
    ler_vetor(vetor, TAM);

    return 0;
}