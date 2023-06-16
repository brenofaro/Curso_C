#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 5


bool pilha_vazia(int topo){
    if (topo == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool pilha_cheia(int topo){
    if (topo == TAM -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pilha_push(int* pilha, int valor, int *topo){
    if (pilha_cheia(*topo))
    {
        printf("Pilha cheia\n");
    }
    else
    {   
        printf("Valor %d inserido com sucesso!\n");
        (*topo)++;
        pilha[*topo] = valor;
    }
}

void pilha_pop(int* pilha, int *topo){
    if (pilha_vazia(*topo))
    {
        printf("Pilha vazia!\n");
    }
    else
    {
        printf("O valor %d foi removido com sucesso!\n", pilha[*topo]);
        pilha[*topo] = -1;
        *topo -= 1;
    }
}

void pilha_ler(int* pilha, int topo){
    for (int i = 0; i<= topo; i++)
    {
        printf("Valor[%d] = %d\n",i, pilha[i]);
    }
    if (topo == -1)
    {
        printf("Pilha vazia\n");
    }
    else
    {
        printf("Topo = '%d'\n",topo);
    }
}

void pilha_construtor (int* pilha, int *topo){
    *topo = -1;
    for (int i = 0; i < TAM; i++)
    {
        pilha[i] = -1;
    }
}

int pilha_tamanho(int topo){
    return topo + 1;
}

int pilha_get(int* pilha, int topo){
    if (pilha_vazia(topo))
    {
        printf("A pilha está vázia!\n");
        return 0;
    }else{
        return pilha[topo];
    }
}

int main(){
    int pilha[TAM];
    int topo;
    pilha_construtor(pilha, &topo);

    pilha_ler(pilha, topo);
    pilha_push(pilha, 1, &topo);
    pilha_push(pilha, 2, &topo);
    pilha_push(pilha, 3, &topo);
    pilha_push(pilha, 4, &topo);
    pilha_push(pilha, 5, &topo);
    pilha_push(pilha, 6, &topo);
    pilha_push(pilha, 7, &topo);
    printf("Ultimo elemento da pilha = '%d'\n", pilha_get(pilha,topo));

    pilha_ler(pilha, topo);
    pilha_pop(pilha, &topo);
    pilha_pop(pilha, &topo);
    pilha_pop(pilha, &topo);
    pilha_pop(pilha, &topo);
    pilha_pop(pilha, &topo);
    pilha_pop(pilha, &topo);
    pilha_ler(pilha, topo);
    pilha_get(pilha,topo);

    return 0;
}
