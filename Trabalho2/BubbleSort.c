#include <stdio.h>

void BubbleSort(int *v)
{
    int ord, i, aux;

    do{
        ord=0;
        for(i=0; i<9; i++)
        {
            if(v[i]>v[i+1])
            {
                aux=v[i+1];
                v[i+1]=v[i];
                v[i]=aux;
                ord=1;
            }
        }
    }while(ord!=0);
}

int main()
{
    int i, v[10]={6, 5, 3, 7, 2, 1, 0, 8, 9, 4};

    printf("Antes de ordenar: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", v[i]);
    }

    BubbleSort(&v);

    printf("\nDepois de ordenar: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", v[i]);
    }
}
