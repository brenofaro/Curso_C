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
// Dividir pra conquistar
void quick_sort(int *vetor, int inicio, int fim)
{
    int pivo, esq, dir, meio, aux;

    // Limites da esquerda e da direita da região analisada
    esq = inicio;
    dir = fim;

    // Ajustando auxiliares do centro
    meio = (int)((esq + dir) / 2);
    pivo = vetor[meio];

    // Particionamento do vetor em relação ao pivo
    while (dir > esq)
    {
        // Enquanto os valores anteriores ao pivo estiverem menores, move-se para a direita
        while (vetor[esq] < pivo)
        {
            esq = esq + 1;
        }
        // Enquanto os valores depois do pivo estiverem maiores, move-se para a esquerda
        while (vetor[dir] > pivo)
        {
            dir = dir - 1;
        }

        if (esq <= dir)
        {
            // Realiza a troca de elementos
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;

            // Move os limites laterais em direção ao centro
            esq++;
            dir--;
        }
    }

    // Chamada recursiva para continuar ordenando

    // Ordena a partição esquerda
    if (inicio < dir)
    {
        quick_sort(vetor, inicio, dir);
    }

    // Ordena a partição direita
    if (esq < fim)
    {
        quick_sort(vetor, esq, fim);
    }
}


int main()
{
    int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quick_sort(vetor, 0, TAM);
    ler_vetor(vetor, TAM);
    return 0;
}