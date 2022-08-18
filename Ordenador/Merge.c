#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tads_ordenacao.h"

void mergesort(int *vetor, int inicio, int fim);
void merge(int *vetor, int inicio, int meio, int fim);



int main()
{
    int TAM = 8;

    int vetor[TAM];

    for(int i = 0; i < TAM; i++)
    {
        vetor[i] = rand() % 10;
    }

    printvetor(vetor, TAM);
    mergesort(vetor, 0, TAM - 1);
    printvetor(vetor, TAM);

return 0;
}

