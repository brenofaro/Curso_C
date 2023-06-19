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
    else if (value >= 150 && value <= 200)
    {
        return LIMITROFE;
    }
    else
    {
        return ALTO;
    }
}
float porcetagemFormat(int value, int total){
    return (((float)value/total) * 100);

}
int main(){

    int desejavel = 0, limitrofe = 0, alto = 0, total = 0;
    char input[25];
    int number;
    Status result;
    fgets(input, 25, stdin);
    while (input[0] != '*')
    {
        number = atoi(input);
        result = verificaTriglicerideos(number);
        switch (result)
        {
        case 0:
            desejavel++;
            break;
        case 1:
            limitrofe++;
            break;
        case 2:
            alto++;
            break;
        default:
            break;
        }
        fgets(input, 25, stdin);
    }
        total = limitrofe + desejavel + alto;
        printf("Desejavel: %d(%.1f\%)\n", desejavel, porcetagemFormat(desejavel, total));
        printf("Limitrofe: %d(%.1f\%)\n", limitrofe, porcetagemFormat(limitrofe, total));
        printf("Alto: %d(%.1f\%)\n", alto, porcetagemFormat(alto, total));

        if (alto > limitrofe && alto > desejavel)
        {
            printf("Quantidade de ALTO acima do normal");
        }
    
    return 0;
}