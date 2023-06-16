#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 3

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
int* alocaVetorInteiro(int tam){
    int *v;
    v = (int *) malloc(sizeof(int) * tam);
    return v;
}

int main(){
    int variaveis[TAM] = {1,2,3};
    ler_vetor(variaveis, TAM);
    return 0;
}