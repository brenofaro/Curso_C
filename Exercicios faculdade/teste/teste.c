#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10




int main()
{
    char letra;
    char *texto;
    int num;
    bool boleano;
    float numReal;
    double doubleNum;
    int *ponteiro;

    printf("Tam char: %d\n", sizeof(letra));
    printf("Tam string: %d\n", sizeof(texto));
    printf("Tam int: %d\n", sizeof(num));
    printf("Tam ponteiro: %d\n", sizeof(ponteiro));
    printf("Tam bool: %d\n", sizeof(boleano));
    printf("Tam float: %d\n", sizeof(numReal));
    printf("Tam double: %d\n", sizeof(doubleNum));
    



    
    return 0;
}
