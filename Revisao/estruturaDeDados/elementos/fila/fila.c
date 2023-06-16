#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 5


void fila_construtor(int* frente, int* tras){
    *frente = 0;
    *tras = -1;
}

bool fila_vazia(int frente, int tras){
    if (frente> tras)
    {
        return true;
    }else{
        return false;
    }
}

bool fila_cheia(int tras){
    if (tras == TAM -1)
    {
        return true;
    }else{
        return false;
    }

}

void fila_enfileirar(int* fila, int valor, int* tras){
    if (fila_cheia(*tras)){
        printf("A fila esta cheia!\n");
    }else{
        *tras += 1;
        fila[*tras] = valor;
    }
}
void fila_desenfileirar(int* fila, int* frente, int tras){
    if (fila_vazia(*frente, tras))
    {
        printf("A fila esta vazia!\n");
    }else{
    
    printf("O valor '%d' foi retirado com sucesso!\n", fila[*frente]);
    fila[*frente] = -1;
    *frente += 1;
    }
}

void fila_imprimir(int* fila, int tamanho){
    int cont;
 
    for(cont = 0; cont < TAM; cont++){
        printf("%d - ", fila[cont]);
    }
    printf("\n");
}

int fila_tamanho(int tras, int frente){
    return tras - frente + 1;
}



int main(){
    int fila[TAM];
    int frente, tras;
    int valor;
    fila_construtor(&frente, &tras);
    fila_enfileirar(fila, 3, &tras);
    fila_enfileirar(fila, 6, &tras);
    fila_enfileirar(fila, 9, &tras);
    fila_enfileirar(fila, 12, &tras);
    fila_enfileirar(fila, 15, &tras);
    fila_enfileirar(fila, 17, &tras);
    fila_enfileirar(fila, 21, &tras);

    fila_imprimir(fila,fila_tamanho(tras, frente));
    printf("Tamanho da fila = %d\n", fila_tamanho(tras,frente));
    fila_desenfileirar(fila, &frente,tras);
    fila_desenfileirar(fila, &frente,tras);
    fila_desenfileirar(fila, &frente,tras);
    fila_desenfileirar(fila, &frente,tras);
    fila_desenfileirar(fila, &frente,tras);
    fila_desenfileirar(fila, &frente,tras);
    fila_imprimir(fila,fila_tamanho(tras, frente));





    return 0;
}