#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10

void ler_vetor(int *vetor, int tam)
{
    printf("Vetor:\n");
    for (int i = 0; i < tam; i++)
    {
        if (i == tam - 1)
        {
            printf("|%d|", vetor[i]);
        }
        else
        {
            printf("|%d| ", vetor[i]);
        }
    }
    printf("\n");
}

// Junta os dois subarrays criados ao dividir o vetor principal
void merge(int* vetor, int tam, int indiceEsquerdo, int meio, int indiceDireito )
{
    int i, j, k; // Variáveis auxiliares contadoras 
    int n1 = meio - indiceEsquerdo + 1; // Tamanho do primeiro vetor auxiliar
    int n2 = indiceDireito - meio; // Tamanho do segundo vetor auxiliar

    // Cria dois arrays temporários
    int vetorEsquerdo[n1], vetorDireito[n2];

    // Passa os elementos do vetor principal para o primeiro vetor auxiliar (Esquerda)
    for (int i = 0; i < n1; i++)
    {
        vetorEsquerdo[i] = vetor[indiceEsquerdo + i];
    }
    // Passa os elementos do vetor principal para o segundo vetor auxiliar (Direita)
    for (int j = 0; j < n2; j++)
    {
        vetorDireito[j] = vetor[meio + 1 + j];
    }

    // Reseta as variáveis
    i = 0;
    j = 0;
    k = indiceEsquerdo;

    while (i < n1 && j < n2)
    {
        // Caso o valor da esquerda seja menor ou igual ao valor da direita
        if (vetorEsquerdo[i] <= vetorDireito[j])
        {
            // Passa para o vetor principal o valor menor
            vetor[k] = vetorEsquerdo[i];
            // Incrementa o auxiliar para passar para os próximos valores do vetor auxiliar da esquerda
            i++;
        }
        else {
            // Passa para o vetor principal o valor maior
            vetor[k] = vetorDireito[j];
            // Incrementa o auxiliar para passar para os próximos valores do vetor auxiliar da direita
            j++;
        }
        // Aumenta o índice de posicionamento do vetor principal
        k++;
    }

    // Se ainda restarem elementos no vetor auxiliar da esquerda, passa-os para o vetor principal
    while (i < n1)
    {
        vetor[k] = vetorEsquerdo[i];
        i++;
        k++;
    }

    // Se ainda restarem elementos no vetor auxiliar da direita, passa-os para o vetor principal
    while (j < n2)
    {
        vetor[k] = vetorDireito[j];
        j++;
        k++;
    }
}

// Algoritmo de ordenação Merge Sort
void merge_sort(int* vetor, int tam, int indiceEsquerdo, int indiceDireito)
{
    if (indiceEsquerdo < indiceDireito)
    {
        // Encontra o índice do meio
        int meio = indiceEsquerdo + (indiceDireito - indiceEsquerdo) / 2;

        // Ordena a metade esquerda do vetor
        merge_sort(vetor, tam, indiceEsquerdo, meio);
        // Ordena a metade direita do vetor
        merge_sort(vetor, tam, meio + 1, indiceDireito);

        // Une os dois sub-arrays ordenados
        merge(vetor, tam, indiceEsquerdo, meio, indiceDireito);
    }
}


int main(){
    int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    ler_vetor(vetor, TAM);
    merge_sort(vetor, TAM, 0, TAM - 1);
    ler_vetor(vetor, TAM);

    
    return 0;
}