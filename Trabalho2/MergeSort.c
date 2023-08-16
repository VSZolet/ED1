#include <stdio.h>

void Merge(int *v, int comeco, int meio, int fim)
{
    int com1=comeco, com2=meio+1, comAux=0, tam=fim-comeco+1;
    int *vAux;

    vAux=(int*)malloc(tam * sizeof(int));

    while(com1<=meio && com2<=fim)
    {
        if(v[com1] < v[com2])
        {
            vAux[comAux]=v[com1];
            com1++;
        }
        else
        {
            vAux[comAux]=v[com2];
            com2++;
        }
        comAux++;
    }


    while(com1 <= meio) /**Caso ainda haja elementos na primeira metade */
    {

        vAux[comAux]=v[com1];
        comAux++;
        com1++;
    }


    while(com2 <= fim) /**Caso ainda haja elementos na segunda metade */
    {

        vAux[comAux]=v[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++)    /**Move os elementos de volta para o vetor original*/
    {
        v[comAux]=vAux[comAux-comeco];
    }

    free(vAux);
}

void MergeSort(int vetor[], int comeco, int fim){

    if (comeco < fim)
    {
        int meio = (fim+comeco)/2;

        MergeSort(vetor, comeco, meio);
        MergeSort(vetor, meio+1, fim);
        Merge(vetor, comeco, meio, fim);
    }
}

int main()
{
    int i, comeco=0, fim=9, v[10]={6, 5, 3, 7, 2, 1, 0, 8, 9, 4};

    printf("Antes de ordenar: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", v[i]);
    }

    MergeSort(&v, comeco, fim);

    printf("\nDepois de ordenar: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", v[i]);
    }
}
