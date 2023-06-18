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
    
    // Cria o inicio da lista (Seria tipo um cursor)
    estrutura *ponteiroEncadeado;

    // Cria um novo valor
    estrutura *novoPrimeiroValor = (estrutura*) malloc(sizeof(estrutura));

    novoPrimeiroValor->valorNumerico = 13;
    novoPrimeiroValor->proximo = NULL;

    printf("Valor do primeiro elemento: %d\n", novoPrimeiroValor->valorNumerico);

    // Faz o ponteiro encadeado apontar para o primeiro valor
    ponteiroEncadeado = novoPrimeiroValor;

    // Cria um novo valor
    estrutura *novoSegundoValor = (estrutura*) malloc(sizeof(estrutura));
    novoSegundoValor->valorNumerico = 7;
    novoSegundoValor->proximo = NULL;

    // Faz o primeiro valor apontar para o segundo valor
    ponteiroEncadeado->proximo = novoSegundoValor;

    // Imprime a lista encadeda
    while (ponteiroEncadeado != NULL)
    {
        // Imprime o valor atual
        printf("Valor: %d\n", ponteiroEncadeado->valorNumerico);

        // Cursor recebe a posição de memoria do proximo valor
        ponteiroEncadeado = ponteiroEncadeado->proximo;
    }
    

    return 0;
}