#include <stdio.h>
#include <stdlib.h>

int main(){

    int * programacao1, *programacao2, *resultado;
    programacao1 = malloc(sizeof(int) * 45);
    programacao2 = malloc(sizeof(int) * 30);
    resultado = malloc(sizeof(int) * 30);

    for (int i = 0; i < 45; i++)
    {
        scanf("%d", &programacao1[i]);
    }
    for (int i = 0; i < 30; i++)
    {
        scanf("%d", &programacao2[i]);
    }
    int k = 0;
    for (int i = 0; i < 45; i++)
    {
        for (int j = 0; j < 30; j++){
            if (programacao1[i] == programacao2[j])
            {
                resultado[k] = programacao1[i];
                k++;
            }
        }
    }
    resultado[k] = -1;
    int i = 0;
    while (resultado[i] != -1)
    {
        printf("%d ", resultado[i]);
        i++;
    }

    return 0;
}