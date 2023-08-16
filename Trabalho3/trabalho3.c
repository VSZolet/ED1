#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vocabulario{
    char palavra[50];
    int indice[200];
    struct vocabulario *proximo;
}Vocabulario;

int recebeTexto(Vocabulario *primeiro, Vocabulario *ultimo)
{
    Vocabulario *novoNo, *atual;
    char url[30], *linha, palavra[50], *token;
    const char s[11]=",.:;!?-' ";
    int i=0, j;
    FILE *arq;
    primeiro=NULL;

    linha=(char *)malloc(200*sizeof(char));

    fflush(stdin);
    printf("\nDigite o nome do arquivo: ");
    scanf("%s", url);

    arq = fopen(url, "r");

    if(arq == NULL)
    {
        printf("\nErro, nao foi possivel abrir o arquivo.\n");
        return 0;
    }
    else
    {
        while((fgets(linha, 200, arq))!=NULL)
        {
            printf("%s", linha);

            token = strtok(linha, s);

            while(token != NULL)
            {
                if(primeiro==NULL)
                {
                    novoNo=(Vocabulario *)malloc(sizeof(Vocabulario)*1);
                    strcpy(novoNo->palavra, token);
                    novoNo->indice[0]=i;printf("OI1");
                    novoNo->proximo=NULL;
                    primeiro=novoNo;printf("OI2");
                    ultimo=novoNo;
                }
                else
                {
                    atual=primeiro;

                    while(atual->proximo!=NULL || atual->palavra!=token)
                    {
                        printf("OI3");
                        atual=atual->proximo;
                    }
                    if(atual->palavra==token)
                    {
                        j=0;printf("OI4");
                        while(atual->indice[j]!=NULL)
                        {
                            j++;
                        }
                        atual->indice[j]=i;printf("OI5");
                    }
                    else
                    {
                        novoNo=(Vocabulario *)malloc(sizeof(Vocabulario)*1);
                        strcpy(novoNo->palavra, token);
                        novoNo->indice[0]=i;printf("OI6");
                        novoNo->proximo=NULL;
                        ultimo->proximo=novoNo;printf("OI7");
                        ultimo=novoNo;printf("OI8");
                    }
                }
                i=i+strlen(token)+1;
                printf("%s", primeiro->palavra);
                token = strtok(NULL, s);
            }
        }
        printf("\n");
    }
    return 0;
}

int mostraInvertido(Vocabulario *primeiro, Vocabulario *ultimo)
{
    Vocabulario *atual=primeiro;
    int i;

    while(atual!=ultimo)
    {
        printf("\n%s, indices: ", atual->palavra);
        i=0;
        while(atual->indice[i]!=NULL)
        {
            printf("%d ", atual->indice[i]);
        }
    }
    return 0;
}

int buscaPalavra()
{
    return 0;
}

int proximaOcorrencia()
{
    return 0;
}

int main()
{
    Vocabulario *primeiro, *ultimo;
    int opcao;

    primeiro=(Vocabulario *)malloc(sizeof(Vocabulario)*1);
    ultimo=(Vocabulario *)malloc(sizeof(Vocabulario)*1);

    do
    {
        printf("\nEscolha uma opcao de 1 a 5: ");
        scanf("%d", &opcao);

        if(opcao==1)
            recebeTexto(&primeiro, &ultimo);
        else if(opcao==2)
            mostraInvertido(&primeiro, &ultimo);
        else if(opcao==3)
            buscaPalavra();
        else if(opcao==4)
            proximaOcorrencia();
        else if(opcao==5)
            return 0;
        else
            printf("\nOpcao Invalida\n");
    }while(opcao!=5);

    return 0;
}
