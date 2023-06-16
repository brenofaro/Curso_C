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

void shell_sort(int *vetor, int tam)
{
    int i, j, atual;
    int h = 1;

    // Define o tamanho do salto entre as análises
    while (h < tam)
    {
        h = 3 * h + 1;
    }

    while (h > 1)
    {
        // Reduz a distância entre as análises
        h = h / 3;

        for (int i = h; i < tam; i++)
        {
            // Elemento atual em análise
            atual = vetor[i];
            // Elemento anterior ao analisado
            j = i - h;

            // Analisando membros anteriores com um salto de 'h'
            while ((j >= 0) && atual < vetor[j])
            {
                // Move os elementos uma posição para frente
                vetor[j + h] = vetor[j];
                // Decrementa 'j' pelo salto 'h'
                j = j - h;
            }

            // Insere o valor no local correto
            vetor[j + h] = atual; // É 'j+h' pois no final do while foi decrementado 'h'

        }
    }
}


int main()
{
    int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    shell_sort(vetor, TAM);
    ler_vetor(vetor, TAM);
    return 0;
}