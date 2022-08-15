#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mergesort(int array[], int inicio, int fim);
int merge(int array[], int inicio, int meio, int fim);



int main()
{
    int array[] = {3, 0, 7, 1, 5, 2, 4, 6};
}

int mergesort(int array[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = inicio + (fim - inicio)/2;
        
        
        mergesort(array, inicio, meio);
        mergesort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }
}

void merge (int array[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++)
    {
        L[i] = array[inicio + i];
    }

    for(int i = 0; i < n2; i++)
    {
        R[i] = array[inicio + i];
    }

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

}