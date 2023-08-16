#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale

typedef struct vocabulario{
    int posicao[2000];
    char palavra[50];
}Vocabulario;

int main(void)
 {
    setlocale(LC_ALL,"portuguese");
    printf("oi");
    char texto[10000];
    printf("oi");
    Vocabulario index[1000];
    printf("oi3");
    return 0;
}
