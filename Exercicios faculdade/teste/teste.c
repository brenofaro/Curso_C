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

int main()
{
    char nome[30];
    nome[0] = 'a';
    int *p1, *p2, *p3, *p4, x=0;
    int vetor[] = {1,2,3,4,5};
    x=0;
    p1 = &x;
    p2 = ++p1;
    p3 = p2 + 4;
    p4 = p3 - 5;

    if (p1 > p2)
    {
        printf("P1 é maior que p2\n");
    }else{
        printf("p2 é maior que p1");
    }
    



    
    return 0;
}
