#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct dados
{
    int rg;
    char nome[20];
}Cadastro;

int AdicionaPrimeiro(long unsigned int j, Cadastro *lista)
{
    long unsigned int c=0, m=0;
    clock_t inicio, fim;

    inicio = clock();
    c++;
    if (j==0)
    {
        fim=clock();
        printf("\nInsira o Primeiro Nome: ");
        scanf("%s", &lista[0].nome);
        printf("\nInsira o RG: ");
        scanf("%d", &lista[0].rg);

    }
    else
    {

        while(j>0)
        {
            strcpy(lista[j+1].nome,lista[j].nome);
            lista[j+1].rg=lista[j].rg;
            m+=2;
            c++;
            j--;
        }
        strcpy(lista[j+1].nome,lista[j].nome);
        lista[j+1].rg=lista[j].rg;
        m+=2;
        fim=clock();

        printf("\nInsira o Primeiro Nome: ");
        scanf("%s", &lista[0].nome);
        printf("\nInsira o RG: ");
        scanf("%d", &lista[0].rg);

    }

    printf("\nFoi inserido na primeira posicao. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 1;
}

int AdicionaUltimo(long unsigned int j, Cadastro *lista)
{
    clock_t inicio, fim;

    printf("\nInsira o Primeiro Nome: ");
    scanf("%s", &lista[j].nome);
    printf("\nInsira o RG: ");
    scanf("%d", &lista[j].rg);

    inicio=clock();
    fim=clock();

    printf("\nAdicionado na ultima posicao, %d. C=0 e M=0. Tempo de Execucao: %.2fs.\n",j+1, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 1;

}

int AdicionaPosicao(long unsigned int j, Cadastro *lista)
{
    long unsigned int aux, m=0, c=0;
    clock_t inicio, fim;

    printf("\nInsira posicao que deseja inserir: ");
    scanf("%d", &aux);

    while(aux-1>j)
    {
        c++;
        printf("\nPosicao maior que %d, o seguinte do ultimo da fila.\n", j+1);
        printf("\nInsira posicao que deseja inserir: ");
        scanf("%d", &aux);
    }

    inicio=clock();

    while(j>aux-1)
    {
        strcpy(lista[j+1].nome,lista[j].nome);
        lista[j+1].rg=lista[j].rg;
        m+=2;
        c++;
        j--;
    }
    strcpy(lista[j+1].nome,lista[j].nome);
    lista[j+1].rg=lista[j].rg;

    fim=clock();

    printf("\nInsira o Primeiro Nome: ");
    scanf("%s", &lista[j].nome);
    printf("\nInsira o RG: ");
    scanf("%d", &lista[j].rg);

    printf("\nFoi inserido na posicao %d. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", aux, c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 1;

}

int RetiraPrimeiro(long unsigned int j, Cadastro *lista)
{
    long unsigned int i=j, m=0, c=0;
    clock_t inicio, fim;

    inicio=clock();

    c++;
    if(j==0)
    {
        fim=clock();
        printf("\nA lista está vazia, impossível retirar.");
        return 0;
    }
    else
    {
        j=0;
        while(j<i)
        {
            strcpy(lista[j].nome,lista[j+1].nome);
            lista[j].rg=lista[j+1].rg;
            m+=2;
            c++;
            j++;
        }
        strcpy(lista[j].nome,"");
        lista[j].rg=0;
    }

    fim=clock();

    printf("\nFoi retirado da primeira posicao. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 1;

}

int RetiraUltimo(long unsigned int j, Cadastro *lista)
{
    long unsigned int c=0, m=0;
    clock_t  inicio, fim;

    inicio=clock();

    c++;
    if(j==0)
    {
        fim=clock();
        printf("\nA lista está vazia, impossível retirar.");
        return 0;
    }
    else
    {
        strcpy(lista[j-1].nome,"");
        lista[j-1].rg=0;
        m++;
    }
    fim=clock();

    printf("\nFoi retirado da ultima posicao, %d. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", j, c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 1;
}

int RetiraPosicao(long unsigned int k, Cadastro *lista)
{
    long unsigned int aux, j, m=0, c=0;
    clock_t inicio, fim;

    printf("\nInsira posicao que deseja retirar: ");
    scanf("%d", &j);

    while(j-1>k)
    {
        c++;
        printf("\nPosicao maior que %d, o seguinte do ultimo da fila.\n", j+1);
        printf("\nInsira posicao que deseja inserir: ");
        scanf("%d", &j);
    }

    inicio=clock();
    aux=j;
    j--;

    while(j-1<k)
    {
        strcpy(lista[j].nome,lista[j+1].nome);
        lista[j].rg=lista[j+1].rg;
        m+=2;
        c++;
        j++;
    }
    strcpy(lista[j].nome,"");
    lista[j].rg=0;

    fim=clock();

    printf("\nFoi retirado da posicao %d. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", aux, c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 1;
}

int ProcuraRG(long unsigned int k, Cadastro *lista)
{
    int rg, j, aux=0;
    long unsigned int c=0, m=0;
    clock_t inicio, fim;

    printf("\nInsira RG para busca: ");
    scanf("%d", &rg);

    inicio=clock();

    for(j=0; j<k; j++)
    {
        c+=2;
        if(rg==lista[j].rg)
        {
            aux=1;
            printf("\nEncontrado na posicao %d. Nome: %s, RG: %d.\n", j+1, lista[j].nome, lista[j].rg);
            break;
        }
    }

    c++;
    if(aux==1)
    {
        fim=clock();
        printf("\nC=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
    }
    else
    {
        fim=clock();
        printf("\nNao encontrado na lista. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
    }

    return 0;

}

int VerLista(long unsigned int k, Cadastro *lista)
{
    long unsigned int j, c=0;
    clock_t inicio, fim;
    printf("\n");

    inicio=clock();

    c++;
    if(k==0)
    {
        printf("A lista esta vazia.\n");
    }
    for(j=0;j<k;j++)
    {
        c++;
        printf("Linha %d: %s, %d\n", j+1, lista[j].nome, lista[j].rg);
    }

    fim=clock();

    printf("\nC=%d, M=0. Tempo de Execucao: %.2fs.\n", c, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 0;

}

int SalvaLista(long unsigned int k, Cadastro *lista)
{
    long unsigned int j, c=0;
    clock_t inicio, fim;
    char url[31];
    FILE *arq;

    inicio=clock();

	printf("\nEscolha um nome para o arquivo ate 30 caracteres, contando com a extensao do mesmo: ");
	scanf("%s", &url);

	inicio=clock();
	arq = fopen(url, "w");
	c++;
	if(arq == NULL)
    {
        fim=clock();
        printf("Erro, nao foi possivel salvar o arquivo.\n");
        return 0;
    }
	else
    {
        for(j=0; j<k; j++)
        {
            c++;
            fprintf(arq, "%s,%d", lista[j].nome, lista[j].rg);
        }
    }
    fclose(arq);

    fim=clock();

    printf("\nArquivo %s criado com exito. C=%d e M=0. Tempo de Execucao: %.2f\n", url, c, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 0;
}

int LerLista(long unsigned int j, Cadastro *lista)
{
    char  url[20], nome[20];
    int   rg, c=0, m=0, k=j;
    clock_t inicio, fim;
    FILE *arq;

    fflush(stdin);
    printf("\nDigite o nome do arquivo: ");
    scanf("%s", url);

    inicio=clock();
    arq = fopen(url, "r");
    c++;
    if(arq == NULL)
    {
        fim=clock();
        printf("\nErro, nao foi possivel abrir o arquivo.\n");
        return 0;
    }
    else
    {
        c++;
        while( (fscanf(arq,"%[^,],%d\n", &nome, &rg))!=EOF )
        {
            c++;
            strcpy(lista[j].nome,nome);
            lista[j].rg=rg;
            m+=2;
            j++;
        }
    }
    fclose(arq);

    fim=clock();

    printf("\nLista adicionada entre posicao %d e %d. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", k+1, j, c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return j-k;
}

int main(void)
{

    int opcao;
    long unsigned int i=23496886, j=0;
    Cadastro *lista;
    lista=malloc(i*sizeof(Cadastro));

    printf("Selecione Uma Opcao de 1 a 11: ");
    scanf("%d", &opcao);

    while(opcao!=11) /*** Opcoes do programa ***/
    {
        if(opcao==1)
            j+=AdicionaPrimeiro(j, lista);
        else if(opcao==2)
            j+=AdicionaUltimo(j, lista);
        else if(opcao==3)
            j+=AdicionaPosicao(j, lista);
        else if(opcao==4)
            j-=RetiraPrimeiro(j, lista);
        else if(opcao==5)
            j-=RetiraUltimo(j, lista);
        else if(opcao==6)
            j-=RetiraPosicao(j, lista);
        else if(opcao==7)
            ProcuraRG(j, lista);
        else if(opcao==8)
            VerLista(j, lista);
        else if(opcao==9)
            SalvaLista(j, lista);
        else if(opcao==10)
            j+=LerLista(j, lista);
        else
            printf("\nOpcao Invalida.\n");

        printf("\nSelecione Uma Opcao de 1 a 11: ");
        scanf("%d", &opcao);
    }

    return 0;
}

