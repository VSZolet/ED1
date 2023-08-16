#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct dados
{
    int rg;
    struct dados *proximo, *anterior;
    char nome[20];
}Cadastro;

int main(void)
{

    char url[31], nome[20];
    unsigned long int i=0;
    int opcao, rg;
    Cadastro *novoNo, *primeiro, *ultimo, *atual;
    long unsigned int c, m;
    clock_t inicio, fim;
    FILE *arq;

    primeiro=(Cadastro *)malloc(1*sizeof(Cadastro));
    primeiro=NULL;
    ultimo=(Cadastro *)malloc(1*sizeof(Cadastro));

    do{
        printf("Selecione uma opcao de 1 a 11: ");
        scanf("%d", &opcao);
        if(opcao==1)       /** Insere Primeiro */
        {

            c=0, m=0;

            printf("\nInsira o Nome: ");
            scanf("%s", nome);
            printf("\nInsira o RG: ");
            scanf("%d", &rg);

            inicio=clock();

            novoNo=(Cadastro *)malloc(1*sizeof(Cadastro));
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
            fim=clock();

            printf("\nFoi inserido na primeira posicao. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

        }
        else if(opcao==2) /** Insere Ultimo */
        {
            printf("\nInsira o Nome: ");
            scanf("%s", nome);
            printf("\nInsira o RG: ");
            scanf("%d", &rg);

            inicio=clock();

            novoNo=(Cadastro *)malloc(1*sizeof(Cadastro));

            strcpy(novoNo->nome,nome);
            novoNo->rg=rg;
            novoNo->anterior=ultimo;
            novoNo->proximo=NULL;
            ultimo->proximo=novoNo;
            ultimo=novoNo;

            i++;
            fim=clock();

            printf("\nAdicionado na ultima posicao, %d. C=0 e M=6. Tempo de Execucao: %.2fs.\n", i, (double)(fim-inicio)/CLOCKS_PER_SEC);

        }
        else if(opcao==3) /** Insere Posicao */
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

            novoNo=(Cadastro *)malloc(1*sizeof(Cadastro));

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
            fim=clock();

            printf("\nAdicionado na posicao %d. C=%d e M=%d. Tempo de Execucao: %.2fs.\n", n, c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

        }
        else if(opcao==4) /** Retira Primeiro */
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
        else if(opcao==5) /** Retira Ultimo */
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
        else if(opcao==6) /** Retira Posicao  */
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
                Cadastro *auxP, *auxA;

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
        else if(opcao==7) /** Procura RG */
        {
            c=0; m=0;
            int pesq, j=1, l=0;

            c++;
            if(primeiro==NULL)
            {
                printf("\nA lista esta vazia.");
            }


            printf("\nEscolha o RG: ");
            scanf("%d", &pesq);

            inicio=clock();
            atual=primeiro;

            while(atual!=NULL)
            {
                c+=2;
                if(atual->rg==pesq)
                {
                    printf("\nRG encontrado. Nome %s, posicao %d.\n", atual->nome, j);
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

            printf("\nC=%d e M=%d. Tempo de Execucao: %.2fs.\n", c, m, (double)(fim-inicio)/CLOCKS_PER_SEC);

        }
        else if(opcao==8) /** Mostra Lista */
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
        else if(opcao==9) /** Salva Lista */
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
        else if(opcao==10) /** Recebe Lista */
        {
            c=0; m=0;

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

                    novoNo=(Cadastro *)malloc(1*sizeof(Cadastro));

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
        else if (opcao <1 || opcao > 11)
        {
            printf("\nOpcao invalida.\n");
        }
        printf("\n");
    }while(opcao!=11);

	return 0;
}
