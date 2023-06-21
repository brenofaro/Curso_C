#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct Pessoa
{
    char nome[50];
    int rg;
    struct Pessoa *proximo;
} Pessoa;

void hr();
int tamanhoLista(Pessoa *ponteiroEncadeado);
void imprimir_menu(Pessoa *ponteiroEncadeado);
void imprime_encadeada(Pessoa *ponteiroEncadeado);
void inserir_inicio(Pessoa **ponteiroEncadeado, char *nome, int rg);

int main()
{
    int funcaoDesejada = 0;
    char tempInput[50];
    char nome[50];
    int rg;

    // Cria o inicio da lista encadeada vazio
    Pessoa *ponteiroEncadeado = (Pessoa *)malloc(sizeof(Pessoa));
    // Atribui valores ao inicio da lista encadeada
    ponteiroEncadeado->nome[0] = '\0';
    ponteiroEncadeado->rg = 0;
    ponteiroEncadeado->proximo = NULL;

    /*
    // Cria o primeiro valor
    Pessoa *novoPrimeiroValor = (Pessoa *) malloc(sizeof(Pessoa));
    // Atribui valores ao primeiro valor
    novoPrimeiroValor->rg = 123456;
    strcpy(novoPrimeiroValor->nome, "Carolina");
    novoPrimeiroValor->proximo = NULL;

    // Transforma o ponteiro do inicio da lista no novo valor
    ponteiroEncadeado = novoPrimeiroValor;

    // Cria o segundo valor
    Pessoa *novoSegundoValor = (Pessoa *) malloc(sizeof(Pessoa));
    // Atribui valores ao segundo valor
    novoSegundoValor->rg = 654321;
    strcpy(novoSegundoValor->nome, "Joao");
    novoSegundoValor->proximo = NULL;

    novoPrimeiroValor->proximo = novoSegundoValor;
    */

    while (funcaoDesejada != 9)
    {
        // Mostrando o menu
        imprimir_menu(ponteiroEncadeado);

        // Lendo o input do usuario
        fgets(tempInput, 50, stdin);
        funcaoDesejada = atoi(tempInput);

        // Realizar as acoes de acordo com a escolha do usuario
        switch (funcaoDesejada)
        {
        case 1:
            printf("Inserindo no inicio da lista...\n");
            hr();
            printf("Digite o nome da pessoa: \n");
            fgets(nome, 50, stdin);
            // Remove o \n do final da string
            nome[strcspn(nome, "\n")] = 0;
            printf("Digite o RG da pessoa: \n");
            fgets(tempInput, 50, stdin);
            rg = atoi(tempInput);
            inserir_inicio(&ponteiroEncadeado, nome, rg);

            break;

        case 8:
            printf("Imprimindo lista...\n");
            hr();
            if (tamanhoLista(ponteiroEncadeado) == 0)
            {
                printf("A lista nao possui elementos! \n");
                hr();
            }
            else
            {
                imprime_encadeada(ponteiroEncadeado);
            }
            break;

        case 9:
            printf("Saindo do programa...\n");
            break;

        default:
            break;
        }
    }

    return 0;
}

void hr()
{
    printf("---------------------------------------------------------------\n");
}

int tamanhoLista(Pessoa *ponteiroEncadeado)
{
    // Se a lista estiver vazia, retorna 0
    if (ponteiroEncadeado->nome[0] == '\0')
    {
        return 0;
    }

    int tamanho = 0;
    // Cria um ponteiro auxiliar para percorrer a lista
    Pessoa *ponteiroAuxiliar = ponteiroEncadeado;
    // Percorre a lista enquanto o ponteiro auxiliar nao for nulo
    while (ponteiroAuxiliar != NULL)
    {
        tamanho++;
        ponteiroAuxiliar = ponteiroAuxiliar->proximo;
    }

    return tamanho;
}

void imprimir_menu(Pessoa *ponteiroEncadeado)
{
    printf("                   OPERACOES: \n");
    hr();
    if (tamanhoLista(ponteiroEncadeado) == 0)
    {
        printf("Lista vazia! \n");
    }
    else
    {
        printf("Tamanho da lista: %d \n", tamanhoLista(ponteiroEncadeado));
    }

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

void imprime_encadeada(Pessoa *ponteiroEncadeado)
{

    // Cria um ponteiro auxiliar para percorrer a lista
    Pessoa *p = ponteiroEncadeado;
    int i = 0;
    while (p != NULL)
    {
        printf("Pessoa %d:\n", i);
        printf("Nome: %s\n", p->nome);
        printf("RG: %d\n", p->rg);
        hr();
        p = p->proximo;
        i++;
    }
}

void inserir_inicio(Pessoa **ponteiroEncadeado, char *nome, int rg)
{
    
    
    Pessoa *novaPessoa = (Pessoa *)malloc(sizeof(Pessoa));
    // Atribui valores ao primeiro valor
    strcpy(novaPessoa->nome, nome);
    novaPessoa->rg = rg;
    
    // Se a lista estiver vazia, o proximo valor eh nulo
    if ((*ponteiroEncadeado)->nome[0] == '\0')
    {
        novaPessoa->proximo = NULL;
    }
    else
    {
        novaPessoa->proximo = *ponteiroEncadeado;
    }
    

    // Transforma o ponteiro do inicio da lista no novo valor
    *ponteiroEncadeado = novaPessoa;

    printf("Pessoa inserida com sucesso!\n");
}