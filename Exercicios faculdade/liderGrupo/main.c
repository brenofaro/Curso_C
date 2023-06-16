#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include <ctype.h>

void formataMinusculo(char *nome){
    for (int i = 0; nome[i]; i++)
    {
        nome[i] = tolower(nome[i]);
    }
}

int resultadoFunc(char *nomeTime1,char *nomeTime2, int *valoresTime1, int *valoresTime2){
    for (int i = 0; i < 3; i++)
    {
        if (valoresTime1[i] > valoresTime2[i])
        {
            return 1;
        }
        else if (valoresTime2[i] > valoresTime1[i])
        {
            return 2;
        }
    }
    return -1;
}

int main(){

    char nomeTime1[25];
    char nomeTime2[25];
    int valoresTime1[3];
    int valoresTime2[3];

    fgets(nomeTime1, 25, stdin);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &valoresTime1[i]);
    }
    fflush(stdin);
    fgets(nomeTime2, 25, stdin);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &valoresTime2[i]);
    }

    formataMinusculo(nomeTime1);
    formataMinusculo(nomeTime2);
    int resultado = resultadoFunc(nomeTime1,nomeTime2,valoresTime1,valoresTime2);
    switch (resultado)
    {
    case 1:
        printf("%s", nomeTime1);
        break;
    case 2:
        printf("%s", nomeTime2);
        break;
    default:
        printf("EMPATE");
        break;
    }

    return 0;
}