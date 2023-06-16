#include <stdio.h>
#include <stdlib.h>


typedef enum {
    DESEJAVEL,
    LIMITROFE,
    ALTO,
    INVALIDO
} Status;


Status verificaTriglicerideos(int value){
    if (value < 0)
    {
        return INVALIDO;
    }
    else if (value < 150)
    {
        return DESEJAVEL;
    }
    else if (value >= 150 && value < 200)
    {
        return LIMITROFE;
    }
    else
    {
        return ALTO;
    }
}

Status verificaColesterol(float value){
    if (value < 0)
    {
        return INVALIDO;
    }
    else if (value < 150)
    {
        return DESEJAVEL;
    }
    else if (value >= 150 && value < 170)
    {
        return LIMITROFE;
    }
    else
    {
        return ALTO;
    }
}


int main(){
    int triglicerideos;
    float colesterol;
    Status resultadoTri;
    Status resultadoCol;


    scanf("%d\n%f", &triglicerideos, &colesterol);
    
    resultadoTri = verificaTriglicerideos(triglicerideos);
    resultadoCol = verificaColesterol(colesterol);

    if (resultadoTri == INVALIDO || resultadoCol == INVALIDO)
    {
        printf("Algum valor fora da faixa");
        return 1;
    }
    switch (resultadoTri)
    {
    case DESEJAVEL:
        printf("Triglicerideos %d mg/dl: DESEJAVEL", triglicerideos);
        break;
    case LIMITROFE:
        printf("Triglicerideos %d mg/dl: LIMITROFE", triglicerideos);
        break;
    default:
        printf("Triglicerideos %d mg/dl: ALTO", triglicerideos);
        break;
    }
    printf("\n");
    switch (resultadoCol)
    {
    case DESEJAVEL:
        printf("Colesterol total %.1f mg/dl: (DESEJAVEL)", colesterol);
        break;
    case LIMITROFE:
        printf("Colesterol total %.1f mg/dl: (LIMITROFE)", colesterol);
        break;
    default:
        printf("Colesterol total %.1f mg/dl: (ALTO)", colesterol);
        break;
    }
    return 0;
}