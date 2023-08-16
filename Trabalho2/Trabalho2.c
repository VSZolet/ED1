#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct dadosS /** Struct da lista sequencial. */
{
    long unsigned int rg;
    char nome[20];
}CadastroS;

typedef struct dadosE /** Struct da lista encadeada. */
{
    long int rg;
    struct dados *proximo, *anterior;
    char nome[20];
}CadastroE;

/** Opcoes da lista sequencial. */

int AdicionaPrimeiro(long unsigned int j, CadastroS *lista)
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

int AdicionaUltimo(long unsigned int j, CadastroS *lista)
{
    clock_t inicio, fim;

    printf("\nInsira o Primeiro Nome: ");
    scanf("%s", &lista[j].nome);
    printf("\nInsira o RG: ");
    scanf("%d", &lista[j].rg);

    inicio=clock();
    fim=clock();

    printf("\nAdicionado na ultima posicao, %d. C=1 e M=1. Tempo de Execucao: %.2fs.\n",j+1, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 1;

}

int AdicionaPosicao(long unsigned int j, CadastroS *lista)
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

int RetiraPrimeiro(long unsigned int j, CadastroS *lista)
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

int RetiraUltimo(long unsigned int j, CadastroS *lista)
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

int RetiraPosicao(long unsigned int k, CadastroS *lista)
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

int ProcuraBinario(int *d, int *n, CadastroS *lista, long unsigned int inicio, long unsigned int fim, int a)
{
    long unsigned int i;
    int rg=a, c=*d, m=*n;

    i=(inicio+fim)/2;

    m++;
    c++;
    if(lista[i].rg==rg)
    {
        printf("\nEncontrado na posicao %d. Nome: %s, RG: %d.", i+1, lista[i].nome, lista[i].rg);
        *d=c;
        *n=m;
        return 0;
    }

    c++;
    *d=c;
    *n=m;
    if(inicio==fim)
    {

        printf("\nRG nao encontrado.");
        return 0;
    }
    else
    {
        if(lista[i].rg>rg)
            ProcuraBinario(&c, &m, lista, inicio, i-1, rg);
        else
            ProcuraBinario(&c, &m, lista, i+1, fim, rg);
    }
    *d=c;
    *n=m;

    return 0;
}

int ProcuraSequencia(long unsigned int k, CadastroS *lista)
{
    int rg, j, aux=0, c=0, m=0;
    clock_t inicio, fim;

    printf("\nEscolha o RG: ");
    scanf("%d", &rg);

    inicio=clock();

    for(j=0; j<k; j++)
    {
        c+=2;
        if(rg==lista[j].rg)
        {
            fim=clock();
            printf("\nEncontrado na posicao %d. Nome: %s, RG: %d. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", j+1, lista[j].nome, lista[j].rg, c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
            return 0;
        }
    }

    fim=clock();
    printf("\nNao encontrado na lista. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 0;
}

int OrdenaLista(long unsigned int k, CadastroS *lista)
{
    int opcao;
    int c=0, m=0;
    clock_t inicio, fim;

    do
    {
        printf("\nEscolha entre 1 a 6 para a forma de ordenacao: ");
        scanf("%d",  &opcao);
        if(opcao==1)
        {
            inicio=clock();
            SelectionSort(&c, &m, k, lista);
            fim=clock();

            printf("\nLista Organizada por Selection-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
        }
        else if (opcao==2)
        {
            inicio=clock();
            InsertionSort(&c, &m, k, lista);
            fim=clock();

            printf("\nLista Organizada por Inserction-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
        }
        else if (opcao==3)
        {
            inicio=clock();
            BubbleSort(&c, &m, k, lista);
            fim=clock();

            printf("\nLista Organizada por Bubble-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
        }
        else if (opcao==4)
        {
            inicio=clock();
            ShellSort(&c, &m, k, lista);
            fim=clock();

            printf("\nLista Organizada por Shell-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
        }
        else if (opcao==5)
        {
            inicio=clock();
            QuickSort(&c, &m, lista, 0, k-1);
            fim=clock();

            printf("\nLista Organizada por Quick-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

        }
        else if (opcao==6)
        {
            inicio=clock();
            MergeSort(&c, &m, lista, 0, k-1);
            fim=clock();

            printf("\nLista Organizada por Merge-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
        }
        else
            printf("\nOpcao Invalida.");
        printf("\n");
    }while (opcao<1 || opcao>6);

    return 1;
}

int VerLista(long unsigned int k, CadastroS *lista)
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

int SalvaLista(long unsigned int k, CadastroS *lista)
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

int LerLista(long unsigned int j, CadastroS *lista)
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

/** Fim das opcoes sequencias */

/** Opcoes de ordenacao */

int SelectionSort(int *d, int *n, long unsigned int k, CadastroS *lista)
{
    CadastroS aux;
    int c=0, m=0;
    long unsigned int i, j, aux2, aux3;


    for(j=0; j<k; j++)
    {
        c++;
        m++;
        aux3=j;

        for(i=j; i<k; i++)
        {
            c+=2;
            if(lista[i].rg <= lista[aux3].rg)
            {
                aux3=i;
                aux2=lista[i].rg;
                m+=2;
            }
        }
        if(lista[j].rg!=lista[aux3].rg)
        {
            aux=lista[aux3];
            lista[aux3]=lista[j];
            lista[j]=aux;
            m+=3;
        }
    }

    *n=m;
    *d=c;
    return 0;
}

int InsertionSort(int *d, int *n, long unsigned int k, CadastroS *lista)
{
    CadastroS aux;
    long unsigned int i, j;
    int c=0, m=0;

    for(i=1; i<k; i++)
    {
        c++;
        m++;
        aux=lista[i];

        for(j=i-1; (j>=0) && (lista[j].rg>aux.rg); j--)
        {
            c++;
            m++;
            lista[j+1]=lista[j];
        }
        lista[j+1]=aux;
        m++;
    }

    *d=c;
    *n=m;
    return 0;
}

int BubbleSort(int *d, int *n, long unsigned int k, CadastroS *lista)
{
    CadastroS aux;
    int ord, c=0, m=0;
    long unsigned int i;

    do{
        ord=0;
        m++;
        for(i=0; i<k-1; i++)
        {
            c++;
            if(lista[i].rg>lista[i+1].rg)
            {
                aux=lista[i+1];
                lista[i+1]=lista[i];
                lista[i]=aux;
                ord=1;
                m+=4;
            }
        }
        c++;
    }while(ord!=0);

    *d=c;
    *n=m;
    return 0;
}

int ShellSort(int *d, int *n, long unsigned int k, CadastroS *lista)
{
    CadastroS aux;
    long unsigned int h=1, i, j;
    int c=0, m=0;

    while(h<k)
        h=3*h+1;

    while(h>1)
    {
        c++;
        h/=3;

        for(i=h; i<k; i++)
        {
            c++;
            m+=2;
            aux=lista[i];
            j=i;

            while(j>=h && aux.rg<lista[j-h].rg)
            {
                c++;
                m++;
                lista[j]=lista[j-h];
                j=j-h;
            }
            lista[j]=aux;
            m++;
        }
    }

    *d=c;
    *n=m;
    return 0;
}

int QuickSort(int *d , int *n, CadastroS *lista, long unsigned int ini, long unsigned int ult)
{
    CadastroS aux;
    long unsigned int g, h=ini, j=ult;
    int c=*d, m=*n;

    g=(lista[h].rg+lista[j].rg)/2;
    m++;
    while (h<=j)
    {
        c++;
        while(lista[h].rg<g)
        {
            h++;
            c++;
        }
        while(lista[j].rg>g)
        {
            j--;
            c++;
        }
        if(h<=j)
        {
            c++;
            aux=lista[h];
            lista[h]=lista[j];
            lista[j]=aux;
            m+=3;
            h++;
            j--;
        }
    }

    c++;
    *d=c;
    *n=m;
    if(j>ini)
        QuickSort(&c, &m, lista, ini, j);

    *d=c;
    *n=m;
    c++;
    if(h<ult)
        QuickSort(&c, &m, lista, h, ult);

    *d=c;
    *n=m;
    return 0;
}

int MergeSort(int *d, int *n, CadastroS *lista, long unsigned int ini, long unsigned int ult) /** Parte 1, a divisao de elementos. */
{
    int c=*d, m=*n;

    if (ini < ult)
    {
        c++;
        int meio = (ult+ini)/2;
        m++;

    *d=c;
    *n=m;

        MergeSort(&c, &m, lista, ini, meio);
    *d=c;
    *n=m;
        MergeSort(&c, &m, lista, meio+1, ult);
    *d=c;
    *n=m;
        Merge(&c, &m, lista, ini, meio, ult);
    }
    *d=c;
    *n=m;

    return 0;
}

int Merge(int *d, int *n, CadastroS *lista, long unsigned int ini, long unsigned int meio, long unsigned int ult) /** Parte 2, a juncao de elementos. "merging" */
{
    int com1=ini, com2=meio+1, comAux=0, tam=ult-ini+1, c=*d, m=*n;
    CadastroS *aux;

    aux=malloc(tam*sizeof(CadastroS));

    while(com1<=meio && com2<=ult)
    {
        c++;
        if(lista[com1].rg < lista[com2].rg)
        {
            c++;
            m++;
            aux[comAux]=lista[com1];
            com1++;
        }
        else
        {
            c++;
            m++;
            aux[comAux]=lista[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio)
    {
        c++;
        m++;
        aux[comAux]=lista[com1];
        comAux++;
        com1++;
    }

    while(com2 <= ult)
    {
        c++;
        m++;
        aux[comAux]=lista[com2];
        comAux++;
        com2++;
    }

    for(comAux = ini; comAux <= ult; comAux++)
    {
        c++;
        m++;
        lista[comAux]=aux[comAux-ini];
    }

    *d=c;
    *n=m;
    free(aux);
    return 0;
}

/** Fim das ordenacoes */

/** Encadeada para Sequencial e Sequencial para Encadeada */

int transformaSequencial(int *d, int *n, CadastroS *lista, long unsigned int i, CadastroE *primeiro)
{
    int j, c=*d, m=*n;

    CadastroE *atual;
    atual=malloc(1*sizeof(CadastroE));
    atual=primeiro;
    m++;

    for (j=0; j<i; j++)
    {
        c++;
        lista[j].rg=atual->rg;
        strcpy(lista[j].nome, atual->nome);
        atual=atual->proximo;
        m+=3;
    }

    free(atual);
    *d=c;
    *n=m;
    return 0;
}

int main()
{
    int opcaoF;

    do{
    printf("Escolha 1 para Sequencial, 2 para Encadeado: ");
    scanf("%d", &opcaoF);
    printf("\n");
    }while(opcaoF<1 || opcaoF>2);

    if (opcaoF==1)  /** Leva para Opcoes de uma lista sequencial, iniciando variaveis necessarias. */
    {
        int opcao, ord=0;
        long unsigned int i=23496886, j=0;
        CadastroS *lista;
        lista=malloc(i*sizeof(CadastroS));

        do /*** Opcoes do programa ***/
        {
            printf("Selecione Uma Opcao de 1 a 12: ");
            scanf("%d", &opcao);

            if(opcao==1)
            {
                ord=0;
                j+=AdicionaPrimeiro(j, lista);
            }
            else if(opcao==2)
            {
                ord=0;
                j+=AdicionaUltimo(j, lista);
            }
            else if(opcao==3)
            {
                ord=0;
                j+=AdicionaPosicao(j, lista);
            }
            else if(opcao==4)
                j-=RetiraPrimeiro(j, lista);
            else if(opcao==5)
                j-=RetiraUltimo(j, lista);
            else if(opcao==6)
                j-=RetiraPosicao(j, lista);
            else if(opcao==7)
            {
                int opt, rg, c=0, m=0;
                clock_t inicio, fim;

                if(lista[0].rg==NULL)
                {
                    printf("\nA lista esta vazia.\n");
                }
                else
                {
                    printf("\nEscolha 1 para busca sequencial, 2 para busca binaria: ");
                    scanf("%d", &opt);

                    if(ord!=1 && opt==2)
                        printf("\nNao esta organizado, impossivel fazer busca binaria.\n");
                    else if(ord==1 && opt==2)
                    {
                        printf("\nEscolha o RG: ");
                        scanf("%d", &rg);
                        inicio=clock();
                        ProcuraBinario(&c, &m, lista, 0, j-1, rg);
                        fim=clock();

                        printf("C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                    }
                    else
                        ProcuraSequencia(j, lista);
                }
            }
            else if(opcao==8)
                ord=OrdenaLista(j, lista);
            else if(opcao==9)
                VerLista(j, lista);
            else if(opcao==10)
                SalvaLista(j, lista);
            else if(opcao==11)
            {
                ord=0;
                j+=LerLista(j, lista);
            }
            else if(opcao<1 || opcao>12)
                printf("\nOpcao Invalida.\n");
            printf("\n");
        }while(opcao!=12);

        return 0;
    }
    else            /** Leva para Opcoes de uma lista encadeada, iniciando variaveis necessarias. */
    {
        char url[31], nome[20];
        unsigned long int i=0;
        int c, m;
        int opcao1, rg, ord=0;
        CadastroE *novoNo, *primeiro, *ultimo, *atual;
        clock_t inicio, fim;
        FILE *arq;

        primeiro=(CadastroE *)malloc(1*sizeof(CadastroE));
        primeiro=NULL;
        ultimo=(CadastroE *)malloc(1*sizeof(CadastroE));

        do{
            printf("Selecione uma opcao de 1 a 12: ");
            scanf("%d", &opcao1);
            if(opcao1==1)       /** Insere Primeiro */
            {

                c=0, m=0;

                printf("\nInsira o Nome: ");
                scanf("%s", nome);
                printf("\nInsira o RG: ");
                scanf("%d", &rg);

                inicio=clock();

                novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));
                strcpy(novoNo->nome,nome);
                novoNo->rg=rg;
                novoNo->proximo=NULL;
                m+=3;

                c++;
                if(primeiro!=NULL)
                {
                    novoNo->proximo=primeiro;
                    primeiro->anterior=novoNo;
                    m+=2;
                }
                else
                {
                    ultimo=novoNo;
                    m++;
                }
                primeiro=novoNo;
                primeiro->anterior=NULL;

                m+=2;
                i++;
                ord=0;
                fim=clock();

                printf("\nFoi inserido na primeira posicao. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

            }
            else if(opcao1==2) /** Insere Ultimo */
            {
                printf("\nInsira o Nome: ");
                scanf("%s", nome);
                printf("\nInsira o RG: ");
                scanf("%d", &rg);

                inicio=clock();

                novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                strcpy(novoNo->nome,nome);
                novoNo->rg=rg;
                novoNo->anterior=ultimo;
                novoNo->proximo=NULL;
                ultimo->proximo=novoNo;
                ultimo=novoNo;

                i++;
                ord=0;
                fim=clock();

                printf("\nAdicionado na ultima posicao, %d. C=0 e M=6. Tempo de Execucao: %.2fs.\n", i, (double)(fim-inicio)/CLOCKS_PER_SEC);

            }
            else if(opcao1==3) /** Insere Posicao */
            {
                int n, j;
                c=0; m=0;

                printf("\nSelecione posicao para inserir, entre 1 e %d: ", i+1);
                scanf("%d", &n);

                while(n<0 || n>i+1)
                {
                    printf("\nPosicao Invalida. Selecione posicao para inserir, entre 1 e %d: ", i+1);
                    scanf("%d", &n);
                }

                printf("\nInsira o Nome: ");
                scanf("%s", nome);
                printf("\nInsira o RG: ");
                scanf("%d", &rg);

                inicio=clock();

                novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                c++;
                if(n<=i/2)
                {
                    atual=primeiro;
                    m++;

                    for(j=1; j<n; j++)
                    {
                        c++;
                        atual=atual->proximo;
                        m++;
                    }
                }
                else
                {
                    atual=ultimo;
                    m++;

                    for(j=i; j>n; j--)
                    {
                        c++;
                        atual=atual->anterior;
                        m++;
                    }
                }

                strcpy(novoNo->nome,nome);
                novoNo->rg=rg;
                novoNo->proximo=NULL;
                m+=3;

                c++;
                if(atual==primeiro)
                {


                    c++;
                    if(primeiro!=NULL)
                    {
                        novoNo->proximo=primeiro;
                        primeiro->anterior=novoNo;
                        m+=2;
                    }
                    else
                    {
                        ultimo=novoNo;
                        m++;
                    }
                    primeiro=novoNo;
                    primeiro->anterior=NULL;

                }
                else if(atual==ultimo)
                {
                    c++;
                    strcpy(novoNo->nome,nome);
                    novoNo->rg=rg;
                    novoNo->anterior=ultimo;
                    novoNo->proximo=NULL;
                    ultimo->proximo=novoNo;
                    ultimo=novoNo;
                }
                else
                {
                    c++;
                    novoNo->proximo=atual;
                    novoNo->anterior=atual->anterior;
                    atual=atual->anterior;
                    atual->proximo=novoNo;
                    strcpy(novoNo->nome,nome);
                    novoNo->rg=rg;
                    m+=6;
                }

                i++;
                ord=0;
                fim=clock();

                printf("\nAdicionado na posicao %d. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", n, c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

            }
            else if(opcao1==4) /** Retira Primeiro */
            {
                inicio=clock();

                if(primeiro==NULL)
                    printf("A lista esta vazia, impossivel retirar.");
                else
                {
                    atual=primeiro;
                    primeiro=primeiro->proximo;
                    primeiro->anterior=NULL;
                    free(atual);

                    i--;
                    fim=clock();

                    printf("\nRetirado da primeira posicao. C=1 e M=3. Tempo de Execucao: %.2fs.\n", (double)(fim-inicio)/CLOCKS_PER_SEC);
                }
            }
            else if(opcao1==5) /** Retira Ultimo */
            {
                inicio=clock();

                if(ultimo==NULL)
                    printf("A lista esta vazia, impossivel retirar.");
                else
                {
                    atual=ultimo;
                    ultimo=ultimo->anterior;
                    ultimo->proximo=NULL;
                    free(atual);

                    i--;
                    fim=clock();

                    printf("\nRetirado da ultima posicao, %d. C=1 e M=3. Tempo de Execucao: %.2fs.\n", i+1, (double)(fim-inicio)/CLOCKS_PER_SEC);
                }
            }
            else if(opcao1==6) /** Retira Posicao  */
            {
                c=0; m=0;

                c++;
                if(i==0)
                {
                    printf("\nA lista esta vazia.\n");
                }
                else
                {
                    int n, j;
                    CadastroE *auxP, *auxA;

                    printf("\nSelecione posicao para retirar, entre 1 e %d: ", i);
                    scanf("%d", &n);

                    while(n<1 || n>i)
                    {
                        printf("\nPosicao Invalida. Selecione posicao para retirar, entre 1 e %d: ", i);
                        scanf("%d", &n);
                    }

                    inicio=clock();

                    c++;
                    if(n<=i/2)
                    {
                        atual=primeiro;
                        m++;

                        for(j=1; j<n; j++)
                        {
                            c++;
                            atual=atual->proximo;
                            m++;
                        }
                    }
                    else
                    {
                        atual=ultimo;
                        m++;

                        for(j=i; j>n; j--)
                        {
                            c++;
                            atual=atual->anterior;
                            m++;
                        }
                    }
                    auxP=atual->proximo;
                    auxA=atual->anterior;
                    m+=2;

                    c++;
                    if(atual==primeiro)
                    {
                        primeiro=auxP;
                        primeiro->anterior=NULL;
                        m+=2;
                    }
                    else if(atual==ultimo)
                    {
                        c++;
                        ultimo=auxA;
                        ultimo->proximo=NULL;
                        m+=2;
                    }
                    else
                    {
                        c++;
                        auxA->proximo=atual->proximo;
                        auxP->anterior=atual->anterior;
                        m+=2;
                    }
                    i--;
                    fim=clock();

                    printf("\nRetirado da posicao %d. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", n, c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                }
            }
            else if(opcao1==7) /** Procura RG */
            {

                c=0; m=0;
                int pesq, opt, j=1, l=0;
                clock_t inicio, fim;
                CadastroS *lista;
                lista=malloc(i*sizeof(CadastroS));

                c++;
                if(primeiro==NULL)
                {
                    printf("\nA lista esta vazia.");
                }
                else
                {
                    printf("\nEscolha 1 para busca sequencial, 2 para busca binaria: ");
                    scanf("%d", &opt);

                    c++;
                    if(ord!=1 && opt==2)
                        printf("\nNao esta organizado, impossivel fazer busca binaria.\n");

                    else if(ord==1 && opt==2)
                    {
                        printf("\nEscolha o RG: ");
                        scanf("%d", &rg);
                        inicio=clock();
                        transformaSequencial(&c, &m, lista, i, primeiro);
                        ProcuraBinario(&c, &m, lista, 0, i-1, rg);
                        fim=clock();

                        printf("C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                    }
                    else if (opt==1)
                    {
                        printf("\nEscolha o RG: ");
                        scanf("%d", &pesq);

                        inicio=clock();
                        atual=primeiro;
                        m++;

                        while(atual!=NULL)
                        {
                            c+=2;
                            if(atual->rg==pesq)
                            {
                                printf("\nRG encontrado. Nome %s, posicao %d. ", atual->nome, j);
                                l++;
                            }
                            atual=atual->proximo;
                            m++;
                            j++;
                        }
                        c++;
                        if(l==0)
                            printf("\nRG nao encontrado. ");

                        free(atual);
                        fim=clock();

                        printf("C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                    }
                }
            free(lista);

            }
            else if(opcao1==8) /** Organiza Lista */
            {
                int j, opcao2, c=0, m=0;
                CadastroS *lista;
                CadastroE *novoNo;
                lista=malloc(i*sizeof(CadastroS));

                do{
                    printf("\nEscolha entre 1 a 6 para a forma de ordenacao: ");
                    scanf("%d",  &opcao2);

                    if(opcao2==1)            /** Selection-Sort */
                    {
                        inicio=clock();
                        transformaSequencial(&c, &m, lista, i, primeiro);

                        SelectionSort(&c, &m, i, lista);

                        novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                        strcpy(novoNo->nome,lista[0].nome);
                        novoNo->rg=lista[0].rg;
                        novoNo->proximo=NULL;
                        novoNo->anterior=NULL;
                        primeiro=novoNo;
                        ultimo=novoNo;
                        m+=6;

                        for(j=1; j<i; j++)
                        {
                            c+=1;
                            novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                            strcpy(novoNo->nome,lista[j].nome);
                            novoNo->rg=lista[j].rg;
                            novoNo->proximo=NULL;

                            ultimo->proximo=novoNo;
                            novoNo->anterior=ultimo;

                            ultimo=novoNo;
                            m+=6;
                        }
                        free(lista);
                        fim=clock();

                        printf("\nLista Organizada por Selection-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

                    }
                    else if (opcao2==2)      /** Insertion-Sort */
                    {
                        inicio=clock();
                        transformaSequencial(&c, &m, lista, i, primeiro);
                        InsertionSort(&c, &m, i, lista);

                        novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                        strcpy(novoNo->nome,lista[0].nome);
                        novoNo->rg=lista[0].rg;
                        novoNo->proximo=NULL;
                        novoNo->anterior=NULL;
                        primeiro=novoNo;
                        ultimo=novoNo;
                        m+=6;

                        for(j=1; j<i; j++)
                        {
                            c+=1;
                            novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                            strcpy(novoNo->nome,lista[j].nome);
                            novoNo->rg=lista[j].rg;
                            novoNo->proximo=NULL;

                            ultimo->proximo=novoNo;
                            novoNo->anterior=ultimo;

                            ultimo=novoNo;
                            m+=6;
                        }
                        free(lista);
                        fim=clock();

                        printf("\nLista Organizada por Insertion-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                        fim=clock();
                    }
                    else if (opcao2==3)      /** Bubble-Sort */
                    {
                        inicio=clock();
                        transformaSequencial(&c, &m, lista, i, primeiro);
                        BubbleSort(&c, &m, i, lista);

                        novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                        strcpy(novoNo->nome,lista[0].nome);
                        novoNo->rg=lista[0].rg;
                        novoNo->proximo=NULL;
                        novoNo->anterior=NULL;
                        primeiro=novoNo;
                        ultimo=novoNo;
                        m+=6;

                        for(j=1; j<i; j++)
                        {
                            c+=1;
                            novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                            strcpy(novoNo->nome,lista[j].nome);
                            novoNo->rg=lista[j].rg;
                            novoNo->proximo=NULL;

                            ultimo->proximo=novoNo;
                            novoNo->anterior=ultimo;

                            ultimo=novoNo;
                            m+=6;
                        }
                        free(lista);
                        fim=clock();

                        printf("\nLista Organizada por Bubble-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                    }
                    else if (opcao2==4)      /** Shell-Sort */
                    {
                        inicio=clock();
                        transformaSequencial(&c, &m, lista, i, primeiro);
                        ShellSort(&c, &m, i, lista);

                        novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                        strcpy(novoNo->nome,lista[0].nome);
                        novoNo->rg=lista[0].rg;
                        novoNo->proximo=NULL;
                        novoNo->anterior=NULL;
                        primeiro=novoNo;
                        ultimo=novoNo;
                        m+=6;

                        for(j=1; j<i; j++)
                        {
                            c+=1;
                            novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                            strcpy(novoNo->nome,lista[j].nome);
                            novoNo->rg=lista[j].rg;
                            novoNo->proximo=NULL;

                            ultimo->proximo=novoNo;
                            novoNo->anterior=ultimo;

                            ultimo=novoNo;
                            m+=6;
                        }
                        free(lista);
                        fim=clock();

                        printf("\nLista Organizada por Shell-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                    }
                    else if (opcao2==5)      /** Quick-Sort */
                    {
                        inicio=clock();
                        transformaSequencial(&c, &m, lista, i, primeiro);
                        QuickSort(&c, &m, lista, 0, i-1);

                        novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                        strcpy(novoNo->nome,lista[0].nome);
                        novoNo->rg=lista[0].rg;
                        novoNo->proximo=NULL;
                        novoNo->anterior=NULL;
                        primeiro=novoNo;
                        ultimo=novoNo;
                        m+=6;

                        for(j=1; j<i; j++)
                        {
                            c+=1;
                            novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                            strcpy(novoNo->nome,lista[j].nome);
                            novoNo->rg=lista[j].rg;
                            novoNo->proximo=NULL;

                            ultimo->proximo=novoNo;
                            novoNo->anterior=ultimo;

                            ultimo=novoNo;
                            m+=6;
                        }
                        free(lista);
                        fim=clock();

                        printf("\nLista Organizada por Quick-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

                    }
                    else if (opcao2==6)  /** Merge-Sort */
                    {
                        inicio=clock();
                        transformaSequencial(&c, &m, lista, i, primeiro);
                        MergeSort(&c, &m, lista, 0, i-1);

                        novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                        strcpy(novoNo->nome,lista[0].nome);
                        novoNo->rg=lista[0].rg;
                        novoNo->proximo=NULL;
                        novoNo->anterior=NULL;
                        primeiro=novoNo;
                        ultimo=novoNo;
                        m+=6;

                        for(j=1; j<i; j++)
                        {
                            c+=1;
                            novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                            strcpy(novoNo->nome,lista[j].nome);
                            novoNo->rg=lista[j].rg;
                            novoNo->proximo=NULL;

                            ultimo->proximo=novoNo;
                            novoNo->anterior=ultimo;

                            ultimo=novoNo;
                            m+=6;
                        }
                        free(lista);
                        fim=clock();

                        printf("\nLista Organizada por Merge-Sort. C=%d e M=%d. Tempo de Execucao: %.4f", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                    }
                    else
                        printf("\nOpcao Invalida.");
                    printf("\n");
                }while (opcao2<1 || opcao2>6);

                ord=1;
            }
            else if(opcao1==9) /** Mostra Lista */
            {
                c=0; m=0;

                inicio=clock();

                c++;
                if(primeiro==NULL)
                {
                    printf("\nA lista esta vazia.");
                }
                else
                {
                    int j=1;

                    atual=primeiro;
                    m++;

                    while(atual!=NULL)
                    {
                        c++;
                        printf("\nLinha %d: %s, %d", j, atual->nome, atual->rg);
                        atual=atual->proximo;
                        m++;
                        j++;
                    }
                    free(atual);
                    fim=clock();

                    printf("\n\nFim da lista. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                }

            }
            else if(opcao1==10) /** Salva Lista */
            {
                c=0; m=0;

                printf("\nEscolha um nome para o arquivo ate 30 caracteres, contando com a extensao do mesmo: ");
                scanf("%s", &url);

                inicio=clock();
                arq = fopen(url, "w");
                c++;
                if(arq == NULL)
                {
                    fim=clock();
                    printf("\nErro, nao foi possivel salvar o arquivo.\n");
                }
                else
                {
                    atual=primeiro;
                    while(atual!=NULL)
                    {
                        c++;
                        fprintf(arq, "%s,%d", atual->nome, atual->rg);
                        atual=atual->proximo;
                    }
                    fclose(arq);
                    fim=clock();
                    printf("\nLista salva com sucesso. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                }
            }
            else if(opcao1==11) /** Recebe Lista */
            {
                c=0; m=0; ord=0;

                printf("\nDigite o nome do arquivo, ate 30 caracteres, contando com a extensao do mesmo: ");
                scanf("%s", &url);

                inicio=clock();

                arq = fopen(url, "r");

                c++;
                if(arq == NULL)
                {
                    printf("\nErro, nao foi possivel abrir o arquivo.\n");
                    fclose(arq);
                }
                else
                {
                    while( (fscanf(arq,"%[^,],%d\n", nome, &rg))!=EOF )
                    {
                        c++;

                        novoNo=(CadastroE *)malloc(1*sizeof(CadastroE));

                        strcpy(novoNo->nome,nome);
                        novoNo->rg=rg;
                        novoNo->proximo=NULL;
                        m+=3;

                        c++;
                        if(primeiro==NULL)
                        {
                            primeiro=novoNo;
                            m++;
                        }
                        else
                        {
                            ultimo->proximo=novoNo;
                            novoNo->anterior=ultimo;
                            m+=2;
                        }

                        ultimo=novoNo;
                        m++;
                        i++;
                    }

                    fclose(arq);
                    fim=clock();

                    printf("\nLista carregada com sucesso. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);
                }
            }
            else if(opcao1<1 || opcao1>12)
                printf("\nOpcao invalida.");
            printf("\n");
        }while(opcao1!=12);

        return 1;
    }
}
