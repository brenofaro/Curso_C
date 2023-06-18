#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>



void imprimir_menu()
{
    printf("                   OPERACOES: \n");
    hr();
    printf("1 - Insercao de um node no inicio da lista \n");
    printf("2 - Insercao de um node no fim da lista \n");
    printf("3 - Insercao de um node na posicao N \n");
    printf("4 - Retirar um node do inicio da lista \n");
    printf("5 - Retirar um node do fim da lista \n");
    printf("6 - Retirar um node da posicao N \n");
    printf("7 - Procurar um node com o campo RG \n");
    printf("8 - Imprimir lista \n");
    printf("9 - Sair do sistema \n");
    hr();
    printf("Escolha um numero e pressione ENTER: \n");
}



int main(){
    int funcaoDesejada = 0;
    char tempInput[20];

    while (funcaoDesejada != 9)
    {
        // Mostrando o menu
        imprimir_menu();

        // Lendo o input do usuario
        fgets(tempInput, 20, stdin);
        funcaoDesejada = atoi(tempInput);

        // Realizar as acoes de acordo com a escolha do usuario
        switch (funcaoDesejada)
        {

        case 9:
            printf("Saindo do programa...\n");
            break;
        
        default:
            break;
        }

    }
    
    return 0;
}