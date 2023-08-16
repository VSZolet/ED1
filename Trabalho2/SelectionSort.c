#include <stdio.h>

void SelectionSort(int *v)
{
    int aux, aux2, i, j=0;

    do{
        aux=v[j];

        for(i=j; i<10; i++)
        {
            if(v[i]<=aux)
            {
                aux=v[i];
                aux2=i;
            }
        }
        v[aux2]=v[j];
        v[j]=aux;
        j++;
    }while(j<10);
}

int main()
{
    int i, v[10]={6, 5, 3, 7, 2, 1, 0, 8, 9, 4};

    printf("Antes de ordenar: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", v[i]);
    }

    SelectionSort(&v);

    printf("\nDepois de ordenar: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", v[i]);
    }
}
