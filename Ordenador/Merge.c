#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tads_ordenacao.h"

int mergesort(int array[], int inicio, int fim);
void merge(int array[], int inicio, int meio, int fim);



int main()
{
    int TAM = 8;

    int array[TAM];

    for(int i = 0; i < TAM; i++)
    {
        array[i] = rand() % 10;
    }

    printvetor(array, TAM);
    mergesort(array, 0, TAM - 1);
    printvetor(array, TAM);

return 0;
}

