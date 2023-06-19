#include <stdlib.h>
#include<stdio.h>
#include <math.h>


void lerMatriz(int** matriz, int tam){
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void multiplicaPorEscalar(int** matriz, int tam, int valor){
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            matriz[i][j] *= valor; 
        }
    }
}

void exibirMatriz(int** matriz, int tam){
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (j == tam - 1)
            {
                printf("%d", matriz[i][j]);
            }
            else{
                printf("%d ", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

void alocaMatrizQuadrada(int*** matriz, int n){
    *matriz = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        (*matriz)[i] = (int*)malloc(sizeof(int) * n);
    }
}


int main(){
    int** matriz;
    int tam;
    char *texto;
    int num;
    char numTemp[20];
    texto = calloc(25,sizeof(char));

    scanf("%d", &tam);
    alocaMatrizQuadrada(&matriz, tam);
    lerMatriz(matriz, tam);

    // Lendo o valor e convertendo em numero (Porque o the huxley não aceita fflush(stdin))
    fgets(numTemp, 25, stdin);
    num = atoi(numTemp);


   fgets(texto, 25, stdin);
   while (texto[0] != '*')
   {
        num = atoi(texto);
        multiplicaPorEscalar(matriz, tam, num);
        fgets(texto, 25, stdin);
   }
   

    exibirMatriz(matriz, tam);
   
    
}