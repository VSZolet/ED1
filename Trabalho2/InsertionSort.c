#include <stdio.h>

void InsertionSort(int *v)
{
    int aux, aux2, i, j;

    for(i=1; i<10; i++)
    {
        aux=v[i];
        j=i-1;

        while(j>=0 && v[j]>aux)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=aux;
    }
}

int main()
{
    int i, v[10]={6, 5, 3, 7, 2, 1, 0, 8, 9, 4};

    printf("Antes de ordenar: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", v[i]);
    }

    InsertionSort(&v);

    printf("\nDepois de ordenar: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", v[i]);
    }
}
