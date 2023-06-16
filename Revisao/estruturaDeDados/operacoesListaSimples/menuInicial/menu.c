#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct pessoa
{
    char nome[50];
    int rg;
} Pessoa;

void alocaVetor(Pessoa **ponteiroSequencial, int tamanhoLista)
{
    *ponteiroSequencial = (Pessoa *)malloc(sizeof(Pessoa) * tamanhoLista);
}

void realoca_vetor(Pessoa **ponteiroSequencial, int novotamanho)
{
    *ponteiroSequencial = (Pessoa *)(ponteiroSequencial, sizeof(Pessoa) * novotamanho);
}

void imprimeSequencial(Pessoa *ponteiroSequencial, int tamanhoLista)
{
    if (tamanhoLista > 0)
    {
        for (int i = 0; i < tamanhoLista; i++)
        {
            printf("Usuario: %d - Nome:  %s - RG: %d\n", i, ponteiroSequencial[i].nome, ponteiroSequencial[i].rg);
        }
        printf("Total de %d pessoas\n", tamanhoLista);
    }
    else
    {
        printf("Lista Vazia\n");
    }
}

void hr()
{
    printf("---------------------------------------------------------------\n");
}
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

void limpaTela()
{
    system("CLS");
}
// Funcao para o case 1: Insercao de um node no inicio da lista
void addComecoSequencial(Pessoa **ponteiroSequencial, int *tamanhoLista, Pessoa pessoa)
{
    if (*tamanhoLista > 0)
    {
        Pessoa *novaListaSequencial;
        int novoTamanho = *tamanhoLista + 1;
        alocaVetor(&novaListaSequencial, novoTamanho);

        // Insere o primeiro novo elemento
        novaListaSequencial[0] = pessoa;

        // Percorro a lista antiga pra colocar os valores na lista nova
        for (int i = 0; i < *tamanhoLista; i++)
        {
            novaListaSequencial[i + 1] = (*ponteiroSequencial)[i];
        }

        // Libera a memoria da lista antiga
        free(*ponteiroSequencial);
        // Atribui a lista nova ao ponteiro
        *ponteiroSequencial = novaListaSequencial;
    }
    else
    {

        *ponteiroSequencial = (Pessoa *)malloc(sizeof(Pessoa));
        (*ponteiroSequencial)[0] = pessoa;
    }

    // Aumenta o tamanho da lista na variavel
    *tamanhoLista += 1;
    printf("Usuario adicionado com sucesso!\n");
    sleep(1);
}

// Funcao para o case 2: Insercao de um node no fim da lista

void addFimSequencial(Pessoa **ponteiroSequencial, int *tamanhoLista, Pessoa pessoa)
{

    int novoTamanho = *tamanhoLista + 1;
    // Aloca um novo vetor com o tamanho da lista + 1
    *ponteiroSequencial = (Pessoa *)realloc(*ponteiroSequencial, sizeof(Pessoa) * novoTamanho);
    // Adiciona o novo elemento no fim da lista
    (*ponteiroSequencial)[novoTamanho - 1] = pessoa;
    // Aumenta o tamanho da lista na variavel
    *tamanhoLista += 1;

    printf("Usuario adicionado com sucesso!\n");
    sleep(1);
}

// Funcao para o case 3: Insercao de um node na posicao N
void addPosicaoN(Pessoa **ponteiroSequencial, int *tamanhoLista, Pessoa pessoa, int posicao)
{
    int novoTamanho = *tamanhoLista + 1;
    // Aloca um novo vetor com o tamanho da lista + 1
    *ponteiroSequencial = (Pessoa *)realloc(*ponteiroSequencial, sizeof(Pessoa) * novoTamanho);
    // Percorre a lista para deslocar os elementos
    for (int i = posicao; i < *tamanhoLista; i++)
    {
        (*ponteiroSequencial)[i + 1] = (*ponteiroSequencial)[i];
    }
    // Adiciona o novo elemento na posicao desejada
    (*ponteiroSequencial)[posicao] = pessoa;
    // Aumenta o tamanho da lista na variavel
    *tamanhoLista += 1;

    printf("Usuario adicionado com sucesso!\n");
    sleep(1);
}

void removerInicioSequencial(Pessoa **ponteiroSequencial, int *tamanhoLista)
{

    if (*tamanhoLista > 0)
    {
        Pessoa *novaListaSequencial;

        alocaVetor(&novaListaSequencial, *tamanhoLista - 1);
        for (int i = 0; i < *tamanhoLista - 1; i++)
        {
            novaListaSequencial[i] = (*ponteiroSequencial)[i + 1];
        }

        free(*ponteiroSequencial);
        // Atribui ao apontador o novo endereco da lista
        *ponteiroSequencial = novaListaSequencial;
        // Atualiza o tamanho da lista
        *tamanhoLista -= 1;

        printf("Primeiro node removido com sucesso\n");
        sleep(1);
    }
    else
    {
        printf("Impossivel realiza operacao. Lista vazia!\n");
        sleep(1);
    }
}

void removerFimSequencial(Pessoa **ponteiroSequencial, int *tamanhoLista)
{
    if (tamanhoLista > 0)
    {
        Pessoa *novaListaSequencial;

        alocaVetor(&novaListaSequencial, *tamanhoLista - 1);
        for (int i = 0; i < *tamanhoLista - 1; i++)
        {
            novaListaSequencial[i] = (*ponteiroSequencial)[i];
        }

        free(*ponteiroSequencial);
        // Atribui ao apontador o novo endereco da lista
        *ponteiroSequencial = novaListaSequencial;
        // Atualiza o tamanho da lista
        *tamanhoLista -= 1;

        printf("Ultimo node removido com sucesso\n");
        sleep(1);
    }
    else
    {
        printf("Impossivel realiza operacao. Lista vazia!\n");
        sleep(1);
    }
}

void removerNodeN(Pessoa **ponteiroSequencial, int *tamanhoLista, int posicao){
    if (tamanhoLista > 0 && posicao < *tamanhoLista && posicao >= 0)
    {
        Pessoa *novaListaSequencial;

        alocaVetor(&novaListaSequencial, *tamanhoLista - 1);
        for (int i = 0; i < *tamanhoLista - 1; i++)
        {
            if (i >= posicao)
            {
                novaListaSequencial[i] = (*ponteiroSequencial)[i + 1];
            }
            else
            {
                novaListaSequencial[i] = (*ponteiroSequencial)[i];
            }
        }

        free(*ponteiroSequencial);
        // Atribui ao apontador o novo endereco da lista
        *ponteiroSequencial = novaListaSequencial;
        // Atualiza o tamanho da lista
        *tamanhoLista -= 1;

        printf("Node na posicao %d removido com sucesso\n", posicao);
    }else{
        if (*tamanhoLista == 0)
        {
            printf("Impossivel realiza operacao. Lista vazia!\n");
        }else{
            printf("Impossivel realiza operacao. Posicao invalida!\n");
        }
        
        sleep(1);
    }
    
}

Pessoa *buscaSequencial(Pessoa *ponteiroSequencial, int tamanhoLista, int rg)
{
    for (int i = 0; i < tamanhoLista; i++)
    {
        if (ponteiroSequencial[i].rg == rg)
        {
            return &ponteiroSequencial[i];
        }
    }
    return NULL;
}


int main()
{
    // Variaveis
    int funcaoDesejada = 0;
    int tamanhoDaLista = 0;
    char tempInput[50];

    // Variaveis temporarias
    Pessoa pessoaTemp;
    char nomeTemp[50];
    int posicaoTemp;

    // Ponteiro para lista sequencial
    Pessoa *ponteiroSequencial = NULL;

    // Pessoa para teste
    alocaVetor(&ponteiroSequencial, 2);

    Pessoa pessoa2;
    strcpy(pessoa2.nome, "Jose");
    pessoa2.rg = 22562626;
    Pessoa pessoa3;
    strcpy(pessoa3.nome, "Maria");
    pessoa3.rg = 995226;

    ponteiroSequencial[0] = pessoa2;
    ponteiroSequencial[1] = pessoa3;

    tamanhoDaLista++;
    tamanhoDaLista++;

    while (funcaoDesejada != 9)
    {
        imprimir_menu();
        fflush(stdin);
        fgets(tempInput, 50, stdin);
        funcaoDesejada = atoi(tempInput);

        switch (funcaoDesejada)
        {
        case 1:
        {
            printf("Funcao escolhida : 1 - Insercao de um node no inicio da lista \n");

            printf("Digite um nome: \n");
            scanf("%s", nomeTemp);
            strcpy(pessoaTemp.nome, nomeTemp);

            printf("Digite o RG \n");
            scanf("%d", &pessoaTemp.rg);

            addComecoSequencial(&ponteiroSequencial, &tamanhoDaLista, pessoaTemp);
            break;
        }

        case 2:
        {
            printf("Funcao escolhida : 2 - Insercao de um node no fim da lista \n");

            printf("Digite um nome: \n");
            scanf("%s", nomeTemp);
            strcpy(pessoaTemp.nome, nomeTemp);

            printf("Digite o RG \n");
            scanf("%d", &pessoaTemp.rg);
            if (tamanhoDaLista == 0)
            {
                addComecoSequencial(&ponteiroSequencial, &tamanhoDaLista, pessoaTemp);
            }
            else
            {
                addFimSequencial(&ponteiroSequencial, &tamanhoDaLista, pessoaTemp);
            }

            break;
        }
        case 3:
            printf("Funcao escolhida : 3 - Insercao de um node na posicao N \n");

            printf("Digite a posicao que deseja inserir: \n");
            scanf("%d", &posicaoTemp);

            printf("Digite um nome: \n");
            scanf("%s", nomeTemp);
            strcpy(pessoaTemp.nome, nomeTemp);

            printf("Digite o RG \n");
            scanf("%d", &pessoaTemp.rg);

            if (posicaoTemp == 0)
            {
                // Se a posicao for 0, insere no comeco
                addComecoSequencial(&ponteiroSequencial, &tamanhoDaLista, pessoaTemp);
            }
            else if (posicaoTemp == tamanhoDaLista)
            {
                // Se a posicao escolhida for igual a posiçao final, insere no fim
                addFimSequencial(&ponteiroSequencial, &tamanhoDaLista, pessoaTemp);
            }
            else
            {
                // Se nao, insere na posicao desejada
                addPosicaoN(&ponteiroSequencial, &tamanhoDaLista, pessoaTemp, posicaoTemp);
            }

            break;
        case 4:
            printf("Funcao escolhida : 4 - Remocao de um node do inicio da lista \n");

            removerInicioSequencial(&ponteiroSequencial, &tamanhoDaLista);
            break;

        case 5:
            printf("Funcao escolhida : 5 - Remocao de um node do fim da lista \n");

            removerFimSequencial(&ponteiroSequencial, &tamanhoDaLista);
            break;
        
        case 6:
            printf("Funcao escolhida : 6 - Remocao de um node da posicao N \n");

            printf("Digite a posicao que deseja remover: \n");
            scanf("%d", &posicaoTemp);

            if (posicaoTemp == 0)
            {
                // Se a posicao for 0, remove no comeco
                removerInicioSequencial(&ponteiroSequencial, &tamanhoDaLista);
            }
            else if (posicaoTemp == tamanhoDaLista)
            {
                // Se a posicao escolhida for igual a posiçao final, remove no fim
                removerFimSequencial(&ponteiroSequencial, &tamanhoDaLista);
            }
            else
            {
                // Se nao, remove na posicao desejada
                removerNodeN(&ponteiroSequencial, &tamanhoDaLista, posicaoTemp);
            }

            break;
        case 7:
            int rgBusca;
            Pessoa *pessoaBusca;
            printf("Funcao escolhida : 7 - Busca de um node por Rg \n");

            printf("Digite o RG que deseja buscar: \n");
            scanf("%d", &rgBusca);

            pessoaBusca = buscaSequencial(ponteiroSequencial, tamanhoDaLista, rgBusca);

            if (pessoaBusca != NULL){
                printf("Pessoa encontrada!\n");
                printf("Nome: %s\n", pessoaBusca->nome);
                printf("Nome: %d\n", pessoaBusca->rg);
            }else{
                printf("Pessoa nao encontrada!\n");
            }
            sleep(1);


        case 8:

            imprimeSequencial(ponteiroSequencial, tamanhoDaLista);
            break;

        case 9:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }

    free(ponteiroSequencial);

    return 0;
}