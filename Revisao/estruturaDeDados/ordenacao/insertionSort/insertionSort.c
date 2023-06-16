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

void inserction_sort(int* vetor, int tam){
    int i, j, atual = 1;

    for (int i = 1; i < tam; i++)
    {
        // Elemento atual em analise
        atual = vetor[i];
        // Elemento anterior ao analisado
        j = i - 1;
        // Analisando membros anteriores
        while ( (j >=  0) && atual < vetor[j])
        {
            // Move os elementos uma posicao para frente
            vetor[j+1] = vetor[j];
            // Faz o j andar para tras
            j--;
        }
        // Insere o valor no local correto
        vetor[j + 1] = atual; // É j+1 pois no final do while foi decrementado 1
    }
}

int main(){
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    inserction_sort(vetor, TAM);
    ler_vetor(vetor, TAM);
    return 0;
}