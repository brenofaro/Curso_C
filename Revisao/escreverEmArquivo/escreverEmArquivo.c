#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE* arquivo;
    char texto[255];

    arquivo = fopen("alunos.txt", "r+");

    fgets(texto, 255, (FILE*)arquivo);
    printf("%s", texto);
    printf("%s", "Teste de escrita");

    fclose(arquivo);


        

    return 0;
}