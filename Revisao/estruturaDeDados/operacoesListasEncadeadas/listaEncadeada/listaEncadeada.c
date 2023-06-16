#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct estrutura{
    int valorNumerico;
    struct estrutura *proximo;
}estrutura;

int main(){
    
    // Cria o inicio da lista
    estrutura *ponteiroEncadeado;

    // Cria um novo valor
    estrutura *novoPrimeiroValor = (estrutura*) malloc(sizeof(estrutura));

    novoPrimeiroValor->valorNumerico = 13;
    novoPrimeiroValor->proximo = NULL;

    printf("Valor do primeiro elemento: %d\n", novoPrimeiroValor->valorNumerico);

    // Faz o ponteiro encadeado apontar para o primeiro valor
    ponteiroEncadeado = novoPrimeiroValor;

    return 0;
}