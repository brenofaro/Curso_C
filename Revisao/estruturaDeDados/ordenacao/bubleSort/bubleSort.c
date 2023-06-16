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

void bubble_sort(int *vetor, int tam)
{
    int i, j, aux;

    // Percorre o vetor tam vezes para garantir que todos os elementos estejam ordenados
    for (int i = 0; i < tam; i++)
    {
        // Percorre o vetor a partir do elemento seguinte a 'i'
        for (int j = i + 1; j < tam; j++)
        {
            // Compara dois elementos adjacentes
            if (vetor[i] > vetor[j])
            {
                // Realiza a troca dos elementos
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main(){
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    bubble_sort(vetor, TAM);
    ler_vetor(vetor, TAM);



    
    


    return 0;
}