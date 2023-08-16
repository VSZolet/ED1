#include <stdio.h>
#include <stdlib.h>

typedef struct vocabulario{
    int posicao[1000];
    char palavra[50];
    struct vocabulario *proximo;
}Vocabulario;

int recebeTexto(char *url, Vocabulario *primeiro, Vocabulario *ultimo) /** opcao 1; */
{
    int i=0, j, tamanho, leitura;
    char palavra[50];
    Vocabulario *novoNo, *atual;
    FILE *arq;

    fflush(stdin);
    printf("\nDigite o nome do arquivo: ");
    scanf("%s", url);

    arq = fopen(url, "r");

    if(arq == NULL)
    {
        printf("\nErro, não foi possivel abrir o arquivo.\n");
        return 0;
    }
    else
    {
        while (fscanf(arq,"%[^,]", &palavra)!=EOF)
        {
            printf("%s", palavra);
            if(primeiro==NULL)
            {
                novoNo=(Vocabulario *)malloc(sizeof(Vocabulario)*1);
                strcpy(novoNo->palavra,palavra);
                novoNo->proximo=NULL;
                novoNo->posicao[0]=i;
                primeiro=novoNo;
                ultimo=novoNo;
            }
            else
            {
                atual=primeiro;
                while(atual->palavra!=palavra || atual->proximo==NULL)
                {
                    atual=atual->proximo;
                }
                if(atual->palavra==palavra)
                {
                    for(j=0; j<1000; j++)
                        if(atual->posicao[j]==NULL)
                            atual->posicao[j]=i;
                }
                else
                {
                    novoNo=(Vocabulario *)malloc(sizeof(Vocabulario)*1);
                    strcpy(novoNo->palavra,palavra);
                    novoNo->proximo=NULL;
                    novoNo->posicao[0]=i;
                    ultimo->proximo=novoNo;
                    ultimo=novoNo;
                }
            }
            i=i+strlen(palavra)+1;
            printf("%d", i);
        }
    }

    fclose(arq);

    return 0;
}

int mostraInvertido (Vocabulario *primeiro, Vocabulario *ultimo)
{
    int i;
    Vocabulario *atual=primeiro;

    while(atual->proximo!=ultimo || atual==ultimo)
    {
        printf("\nPalavra: %s. Posicoes: ", atual->palavra);
        for(i=0;atual->posicao[i]!=NULL;i++)
            printf("%d ", atual->posicao[i]);
    }
    printf("\nPalavra: %s. Posicoes: ", atual->palavra);
    for(i=0;atual->posicao[i]!=NULL;i++)
        printf("%d ", atual->posicao[i]);

    return 0;
}

int procuraPalavra()
{

}

int proximaOcorrencia()
{

}

int main ()
{
    int opcao;
    char *url, *busca;
    Vocabulario *primeiro, *ultimo;

    url=(char *)malloc(sizeof(char)*30);
    url=(char *)malloc(sizeof(char)*50);
    primeiro=(Vocabulario *)malloc(sizeof(Vocabulario)*1);
    ultimo=(Vocabulario *)malloc(sizeof(Vocabulario)*1);

    do
    {
        printf("\n Escolha uma opcao entre 1 e 5: ");
        scanf("%d", &opcao);
        if(opcao==1) /** Ler arquivo de texto */
        {
            recebeTexto(&url, &primeiro, &ultimo);
        }
        else if(opcao==2) /** Exibir arquivo invertido */
        {
            mostraInvertido(&primeiro, &ultimo);
        }
        else if(opcao==3) /** Procurar palavra. */
        {
            procuraPalavra();
        }
        else if(opcao==4) /** Proxima ocorrencia */
        {
            proximaOcorrencia();
        }
        else if(opcao==5) /** Sair */
            return 0;
        else
            printf("Opcao Invalida. ");
    }while(opcao!=5);

    return 0;
}
