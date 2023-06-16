#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int formataVetor(int *vetor, int *tam, int min, int max){
    int j, cont = 0;
    while (cont < *tam - 1)
    {
        if (vetor[cont] < min)
        {
            for (j = 0; j < *tam -1; j++)
            {
                vetor[j] = vetor[j+1];
            }
            *tam -= 1;
        }
        else if (vetor[cont] >= max)
        {
            *tam -= 1;
        }else
        {
            cont++;
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

float medianaVetor(int * vetor, int tam){
    if (tam % 2 != 0)
    {
        int meio = tam / 2;
        float mediana = vetor[meio];
        return mediana;
    }
    else
    {
        int meio1 = (tam / 2) -1;
        int meio2 = meio1 + 1;
        float mediana = ((float)vetor[meio1] + vetor[meio2]) / 2;
        return mediana;
    }
}



int main(){
    char *texto;
    char *c;
    int* vetor;
    int tam = 0;
    int min, max;


    texto = calloc(200,sizeof(char));
    vetor = (int*) malloc(50* sizeof(int));
    fgets(texto, 200, stdin);
    

    c = strtok(texto, ",");
    int cont = 0;
    while (c != NULL)
    {
        vetor[cont] = atoi(c);
        cont++;
        tam++;
        c = strtok(NULL, ",");
        
    }
    
    scanf("%d\n%d", &min,&max);

    bubleSort(vetor, tam);
    formataVetor(vetor, &tam, min, max);
    lerVetor(vetor, tam);
    float mediana = medianaVetor(vetor, tam);
    printf("%.2f", mediana);
    

    return 0;
}